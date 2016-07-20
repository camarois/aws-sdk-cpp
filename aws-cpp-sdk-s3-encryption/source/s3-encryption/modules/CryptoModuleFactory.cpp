/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/s3-encryption/modules/CryptoModuleFactory.h>
#include <aws/core/utils/logging/LogMacros.h>

namespace Aws
{
namespace S3Encryption
{
namespace Modules
{
static const char* const Allocation_Tag = "CryptoModuleFactory";


CryptoModuleBuilder::CryptoModuleBuilder()
{
    m_cryptoFactories.insert(std::pair < CryptoMode, std::shared_ptr<CryptoModuleFactory>>(CryptoModuleFactoryEO().HandlesMode(), Aws::MakeShared<CryptoModuleFactoryEO>(Allocation_Tag, CryptoModuleFactoryEO())));
    m_cryptoFactories.insert(std::pair < CryptoMode, std::shared_ptr<CryptoModuleFactory>>(CryptoModuleFactoryAE().HandlesMode(), Aws::MakeShared<CryptoModuleFactoryAE>(Allocation_Tag, CryptoModuleFactoryAE())));
    m_cryptoFactories.insert(std::pair < CryptoMode, std::shared_ptr<CryptoModuleFactory>>(CryptoModuleFactoryStrictAE().HandlesMode(), Aws::MakeShared<CryptoModuleFactoryStrictAE>(Allocation_Tag, CryptoModuleFactoryStrictAE())));
}

std::shared_ptr<CryptoModule> CryptoModuleBuilder::FetchCryptoModule(const CryptoConfiguration& cryptoConfig, const Aws::S3Encryption::Materials::EncryptionMaterials& , const Aws::Auth::AWSCredentialsProvider& )
{
    auto entry = m_cryptoFactories.find(cryptoConfig.GetCryptoMode());
    if (entry == m_cryptoFactories.end())
    {
        AWS_LOGSTREAM_ERROR(Allocation_Tag, "Crypto Module Factory not found. Factory does not exist for current crypto mode.")
        return nullptr;
    }
    else
    {
        std::shared_ptr<CryptoModuleFactory> factory = entry->second;
        return factory->CreateModule(); //pass in all parameters here once modules are implemented
    }
}

CryptoModuleFactoryEO::CryptoModuleFactoryEO() :
    m_cryptoModuleEO(nullptr)
{
}

std::shared_ptr<CryptoModule> CryptoModuleFactoryEO::CreateModule()
{
    if (m_cryptoModuleEO == nullptr)
    {
        m_cryptoModuleEO = Aws::MakeShared<CryptoModuleEO>(Allocation_Tag, CryptoModuleEO());
        //This is where I will set the encryption materials, crypto config, and aws credntials provider for the module
        return m_cryptoModuleEO;
    }
    else
    {
        //This is where I will set the encryption materials, crypto config, and aws credntials provider for the module
        return m_cryptoModuleEO;
    }
}

CryptoMode CryptoModuleFactoryEO::HandlesMode() const
{
    return CryptoMode::ENCRYPTION_ONLY;
}

CryptoModuleFactoryAE::CryptoModuleFactoryAE() :
    m_cryptoModuleAE(nullptr)
{
}

std::shared_ptr<CryptoModule> CryptoModuleFactoryAE::CreateModule()
{
    if (m_cryptoModuleAE == nullptr)
    {
        m_cryptoModuleAE = Aws::MakeShared<CryptoModuleAE>(Allocation_Tag, CryptoModuleAE());
        //This is where I will set the encryption materials, crypto config, and aws credntials provider for the module
        return m_cryptoModuleAE;
    }
    else
    {
        //This is where I will set the encryption materials, crypto config, and aws credntials provider for the module
        return m_cryptoModuleAE;
    }
}

CryptoMode CryptoModuleFactoryAE::HandlesMode() const
{
    return CryptoMode::AUTHENTICATED_ENCRYPTION;
}

CryptoModuleFactoryStrictAE::CryptoModuleFactoryStrictAE() :
    m_cryptoModuleStrictAE(nullptr)
{
}

std::shared_ptr<CryptoModule> CryptoModuleFactoryStrictAE::CreateModule()
{
    if (m_cryptoModuleStrictAE == nullptr)
    {
        m_cryptoModuleStrictAE = Aws::MakeShared<CryptoModuleStrictAE>(Allocation_Tag, CryptoModuleStrictAE());
        //This is where I will set the encryption materials, crypto config, and aws credntials provider for the module
        return m_cryptoModuleStrictAE;
    }
    else
    {
        //This is where I will set the encryption materials, crypto config, and aws credntials provider for the module
        return m_cryptoModuleStrictAE;
    }
}

CryptoMode CryptoModuleFactoryStrictAE::HandlesMode() const
{
    return CryptoMode::STRICT_AUTHENTICATED_ENCRYPTION;
}

}
}
}