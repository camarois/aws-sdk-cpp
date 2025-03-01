# Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0.
#

cmake_minimum_required (VERSION 3.1)
if(POLICY CMP0056)
    cmake_policy(SET CMP0056 NEW) # CMP0056: Honor link flags in try_compile() source-file signature. Introduced in 3.2
endif()
if(POLICY CMP0057)
    cmake_policy(SET CMP0057 NEW) # CMP0057: Support new IN_LIST if() operator. Introduced in 3.3.
endif()
if (POLICY CMP0077)
    cmake_policy(SET CMP0077 OLD) # CMP0077: option() honors normal variables. Introduced in 3.13
endif()

# 3.12 or higher is strongly suggested; build settings (target_compile_options/etc...) sometimes do not get propagated properly under certain conditions prior to this version
# Making this a hard requirement is potentially disruptive to existing customers who aren't affected by the bad behavior though, so just warn for now
if(CMAKE_VERSION VERSION_LESS 3.12)
    message(WARNING "Building with CMake 3.12 or higher is strongly suggested; current version is ${CMAKE_VERSION}")
endif()

get_filename_component(AWS_NATIVE_SDK_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

# Cmake invocation variables:
#   BUILD_ONLY - only build project identified by this variable, a semi-colon delimited list, if this is set we will build only the projects listed. Core will always be built as will its unit tests.
#                    Also if a high level client is specified then we will build its dependencies as well. If a project has tests, the tests will be built.
#   ADD_CUSTOM_CLIENTS - semi-colon delimited list of format serviceName=<yourServiceName>,version=<theVersionNumber>;serviceName2=<yourOtherServiceName>,version=<versionNumber2>
#                          to use these arguments, you should add the api definition .normal.json file for your service to the api-description folder in the generator.
#   NDK_DIR - directory where the android NDK is installed; if not set, the location will be read from the ANDROID_NDK environment variable
#   CUSTOM_PLATFORM_DIR - directory where custom platform scripts, modules, and source resides
#   AWS_SDK_ADDITIONAL_LIBRARIES - names of additional libraries to link into aws-cpp-sdk-core in order to support unusual/unanticipated linking setups (static curl against static-something-other-than-openssl for example)

option(ENABLE_UNITY_BUILD "If enabled, the SDK will be built using a single unified .cpp file for each service library.  Reduces the size of static library binaries on Windows and Linux" ON)
option(MINIMIZE_SIZE "If enabled, the SDK will be built via a unity aggregation process that results in smaller static libraries; additionally, release binaries will favor size optimizations over speed" OFF)
option(BUILD_SHARED_LIBS "If enabled, all aws sdk libraries will be build as shared objects; otherwise all Aws libraries will be built as static objects" ON)
option(FORCE_SHARED_CRT "If enabled, will unconditionally link the standard libraries in dynamically, otherwise the standard library will be linked in based on the BUILD_SHARED_LIBS setting" ON)
option(SIMPLE_INSTALL "If enabled, removes all the additional indirection (platform/cpu/config) in the bin and lib directories on the install step" ON)
option(NO_HTTP_CLIENT "If enabled, no platform-default http client will be included in the library.  For the library to be used you will need to provide your own platform-specific implementation" OFF)
option(NO_ENCRYPTION "If enabled, no platform-default encryption will be included in the library.  For the library to be used you will need to provide your own platform-specific implementations" OFF)
option(USE_IXML_HTTP_REQUEST_2 "If enabled on windows, the com object IXmlHttpRequest2 will be used for the http stack" OFF)
option(ENABLE_RTTI "Flag to enable/disable rtti within the library" ON)
option(ENABLE_TESTING "Flag to enable/disable building unit and integration tests" ON)
option(AUTORUN_UNIT_TESTS "Flag to enable/disable automatically run unit tests after building" ON)
option(ANDROID_BUILD_CURL "When building for Android, should curl be built as well" ON)
option(ANDROID_BUILD_OPENSSL "When building for Android, should Openssl be built as well" ON)
option(ANDROID_BUILD_ZLIB "When building for Android, should Zlib be built as well" ON)
option(FORCE_CURL "Forces usage of the Curl client rather than the default OS-specific api" OFF)
option(ENABLE_ADDRESS_SANITIZER "Flags to enable/disable Address Sanitizer for gcc or clang" OFF)
option(BYPASS_DEFAULT_PROXY "Bypass the machine's default proxy settings when using IXmlHttpRequest2" ON)
option(BUILD_DEPS "Build third-party dependencies" ON)
option(USE_OPENSSL "Set this if you want to use your system's OpenSSL 1.0.2/1.1.1 compatible libcrypto" ON)
option(ENABLE_CURL_LOGGING "If enabled, Curl's internal log will be piped to SDK's logger" ON)
option(ENABLE_HTTP_CLIENT_TESTING "If enabled, corresponding http client test suites will be built and run" OFF)
option(ENABLE_FUNCTIONAL_TESTING "If enabled, clients might be generated based on dummy models, and run functional tests as part of unit tests: aws-cpp-sdk-core-tests" OFF)
option(CUSTOM_MEMORY_MANAGEMENT "If set to ON, generates the sdk project files with custom memory management enabled, otherwise disables it" OFF)
option(REGENERATE_CLIENTS "If set to ON, all clients being built on this run will be regenerated from the api definitions, this option involves some setup of python, java 8+, and maven" OFF)
option(ENABLE_VIRTUAL_OPERATIONS "This option usually works with REGENERATE_CLIENTS. \
                                If enabled when doing code generation, operation related functions in service clients will be marked as virtual. \
                                If disabled when doing code generation, virtual will not be added to operation functions and service client class will be marked as final. \
                                If disabled, SDK will add compiler flags '-ffunction-sections -fdata-sections' for gcc and clang when compiling. \
                                You can utilize this feature to work with your linker to reduce binary size of your application on Unix platforms when doing static linking in Release mode." ON)
option(REGENERATE_DEFAULTS "If set to ON, defaults mode configuration will be regenerated from the JSON definitions, this option involves some setup of python, java 8+, and maven" OFF)

set(BUILD_ONLY "" CACHE STRING "A semi-colon delimited list of the projects to build")
set(CPP_STANDARD "11" CACHE STRING "Flag to upgrade the C++ standard used. The default is 11. The minimum is 11.")

get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if (NOT ${is_multi_config})
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Release build by default.")
endif()

#From https://stackoverflow.com/questions/18968979/how-to-get-colorized-output-with-cmake
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(Magenta     "${Esc}[35m")
  set(Cyan        "${Esc}[36m")
  set(White       "${Esc}[37m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldYellow  "${Esc}[1;33m")
  set(BoldBlue    "${Esc}[1;34m")
  set(BoldMagenta "${Esc}[1;35m")
  set(BoldCyan    "${Esc}[1;36m")
  set(BoldWhite   "${Esc}[1;37m")
endif()

if(NOT USE_OPENSSL)
    message(WARNING "Turning off USE_OPENSSL will install AWS-LC as replacement of OpenSSL in the system default directory. This is an experimental feature. Do not use if you have an OpenSSL installation in your system already.")
endif()

# backwards compatibility with old command line params
if("${STATIC_LINKING}" STREQUAL "1")
    set(BUILD_SHARED_LIBS OFF)
endif()

if(MINIMIZE_SIZE)
    message(STATUS "MINIMIZE_SIZE enabled")
    set(ENABLE_UNITY_BUILD ON) # MINIMIZE_SIZE always implies UNITY_BUILD
endif()

set(PYTHON_CMD "python")

# CMAKE_MODULE_PATH is a CMAKE variable. It contains a list of paths
# which could be used to search CMAKE modules by "include()" or "find_package()", but the default value is empty.
# Add ${CMAKE_INSTALL_LIBDIR}/cmake and ${CMAKE_PREFIX_PATH}/lib/cmake to search list
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(AWS_MODULE_DIR "/${CMAKE_INSTALL_LIBDIR}/cmake")
string(REPLACE ";" "${AWS_MODULE_DIR};" AWS_MODULE_PATH "${CMAKE_PREFIX_PATH}${AWS_MODULE_DIR}")
list(APPEND CMAKE_MODULE_PATH ${AWS_MODULE_PATH})

# include() will "load and run" cmake script
include(resolve_platform)
include(CMakePackageConfigHelpers)

if (REGENERATE_CLIENTS AND NOT ENABLE_VIRTUAL_OPERATIONS)
    if (PLATFORM_LINUX OR PLATFORM_APPLE)
        Message(STATUS "${BoldYellow}You are regenerating service client's source code and is turning ENABLE_VIRTUAL_OPERATIONS off. If you are targeting smaller binary size, read description string of ENABLE_VIRTUAL_OPERATIONS.${ColourReset}")
    endif()
endif()

# use response files to prevent command-line-too-big errors for large libraries like iam
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS 1)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 1)
set(CMAKE_CXX_RESPONSE_FILE_LINK_FLAG "@")

if(COMMAND apply_pre_project_platform_settings)
    apply_pre_project_platform_settings()
endif()

include(initialize_project_version)

if (BUILD_SHARED_LIBS OR FORCE_SHARED_CRT)
    set(STATIC_CRT OFF)
else()
    set(STATIC_CRT ON)
endif()

# Add Linker search paths to RPATH so as to fix the problem where some linkers can't find cross-compiled dependent libraries in customer paths when linking executables.
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

# build the sdk targets
project("aws-cpp-sdk-all" VERSION "${PROJECT_VERSION}" LANGUAGES CXX)

if (UNIX AND NOT APPLE)
    include(GNUInstallDirs)
elseif(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    set(CMAKE_INSTALL_LIBDIR "lib")
endif()

if (DEFINED CMAKE_PREFIX_PATH)
    file(TO_CMAKE_PATH "${CMAKE_PREFIX_PATH}" CMAKE_PREFIX_PATH)
endif()

if (DEFINED CMAKE_INSTALL_PREFIX)
    file(TO_CMAKE_PATH "${CMAKE_INSTALL_PREFIX}" CMAKE_INSTALL_PREFIX)
endif()

# http client, encryption, zlib
include(external_dependencies)
include(build_external)

if(COMMAND apply_post_project_platform_settings)
    apply_post_project_platform_settings()
endif()

set(CMAKE_CONFIGURATION_TYPES
        Debug                   # Setup for easy debugging. No optimizations.
        DebugOpt                # An optimized version of Debug.
        Release                 # Fully optimized, no debugging information.
        RelWithDebInfo          # A debuggable version of Release.
        MinSizeRel              # Like Release, but optimized for memory rather than speed.
        )

# build third-party targets
if (BUILD_DEPS)
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/crt/aws-crt-cpp/crt/aws-c-common/cmake")

    include(AwsFindPackage)

    set(IN_SOURCE_BUILD ON)
    set(BUILD_TESTING_PREV ${BUILD_TESTING})
    set(BUILD_TESTING OFF CACHE BOOL "Disable all tests in dependencies.")
    # TODO: Use same BUILD_SHARED_LIBS for Aws Common Runtime dependencies.
    # libcurl and aws-sdk-cpp-core may link to different libcrypto, which leads to some issues for shared build.
    if (ENABLE_OPENSSL_ENCRYPTION)
        set(BUILD_SHARED_LIBS_PREV ${BUILD_SHARED_LIBS})
        set(BUILD_SHARED_LIBS OFF)
    endif()
    set(CRT_BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS})
    add_subdirectory(crt/aws-crt-cpp)
    set(BUILD_TESTING ${BUILD_TESTING_PREV})
    if (ENABLE_OPENSSL_ENCRYPTION)
        set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS_PREV})
    endif()
else()
    include(AwsFindPackage)
    set(IN_SOURCE_BUILD OFF)
endif()
set(AWS_COMMON_RUNTIME_LIBS "aws-crt-cpp;aws-c-auth;aws-c-cal;aws-c-common;aws-c-compression;aws-c-event-stream;aws-c-http;aws-c-io;aws-c-mqtt;aws-c-s3;aws-checksums")

include(compiler_settings)
# Instead of calling functions/macros inside included cmake scripts, we should call them in our main CMakeList.txt
set_msvc_flags()
set_msvc_warnings()

include(sdks)

include(utilities)

if(ENABLE_BCRYPT_ENCRYPTION)
    set(CRYPTO_LIBS Bcrypt)
    set(CRYPTO_LIBS_ABSTRACT_NAME Bcrypt)
elseif(ENABLE_OPENSSL_ENCRYPTION)
    set(CRYPTO_LIBS ${OPENSSL_LIBRARIES} ${ZLIB_LIBRARIES})
    set(CRYPTO_LIBS_ABSTRACT_NAME crypto ssl z)
endif()

if(ENABLE_CURL_CLIENT)
    set(CLIENT_LIBS ${CURL_LIBRARIES})
    set(CLIENT_LIBS_ABSTRACT_NAME curl)
elseif(ENABLE_WINDOWS_CLIENT)
    if(USE_IXML_HTTP_REQUEST_2)
        set(CLIENT_LIBS msxml6 runtimeobject)
        set(CLIENT_LIBS_ABSTRACT_NAME msxml6 runtimeobject)
        if(BYPASS_DEFAULT_PROXY)
            list(APPEND CLIENT_LIBS winhttp)
            list(APPEND CLIENT_LIBS_ABSTRACT_NAME winhttp)
        endif()
    else()
        set(CLIENT_LIBS Wininet winhttp)
        set(CLIENT_LIBS_ABSTRACT_NAME Wininet winhttp)
    endif()
endif()

# setup user specified installation directory if any, regardless previous platform default settings
if (CMAKE_INSTALL_BINDIR)
    set(BINARY_DIRECTORY "${CMAKE_INSTALL_BINDIR}")
endif()

if (CMAKE_INSTALL_LIBDIR)
    set(LIBRARY_DIRECTORY "${CMAKE_INSTALL_LIBDIR}")
endif()

if (CMAKE_INSTALL_INCLUDEDIR)
    set(INCLUDE_DIRECTORY "${CMAKE_INSTALL_INCLUDEDIR}")
endif()

if(BUILD_SHARED_LIBS)
    set(ARCHIVE_DIRECTORY "${BINARY_DIRECTORY}")
else()
    set(ARCHIVE_DIRECTORY "${LIBRARY_DIRECTORY}")
endif()

if (ENABLE_ADDRESS_SANITIZER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -fno-omit-frame-pointer")
    if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.1)
        message(STATUS "adding libasan as static explicitly for GCC 7+")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libasan")
    endif()
endif()

include(CheckCXXSymbolExists)

check_cxx_symbol_exists("pathconf" "unistd.h" HAS_PATHCONF)
if (HAS_PATHCONF)
    add_definitions(-DHAS_PATHCONF)
endif()

check_cxx_symbol_exists("umask" "sys/stat.h" HAS_UMASK)
if (HAS_UMASK)
    add_definitions(-DHAS_UMASK)
endif()

add_sdks()

# for user friendly cmake usage
include(setup_cmake_find_module)

# for generating make uninstall target
if (NOT TARGET uninstall)
    ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "${AWS_NATIVE_SDK_ROOT}/cmake/make_uninstall.cmake")
else()
    ADD_CUSTOM_TARGET(uninstall-awssdk "${CMAKE_COMMAND}" -P "${AWS_NATIVE_SDK_ROOT}/cmake/make_uninstall.cmake")
endif()
