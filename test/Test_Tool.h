//
// Created by nini on 11/9/16.
//

#ifndef GATEWAY_CSE_TEST_TOOL_H
#define GATEWAY_CSE_TEST_TOOL_H


#include <iostream>
#include <map>
#include "../lab/mars/m2m/protocol/resource/M2M_KeyWords.h"
#include "../lab/mars/m2m/protocol/resource/resource/m2m_resource.h"
#include "../lab/mars/m2m/utility/XmlLib/XmlLib.h"
#include "../lab/mars/m2m/utility/HttpUtil/HttpUtil.h"

#define CSB KW_CSE_BASE_PATH

namespace Test_Tool {

    static const std::string _URL = "192.168.1.1:8080";

    std::map<std::string, std::string> GetHeaders();

    void Create(const std::string &_Path,
                const enumeration::m2m_resourceType &_Type,
                const std::string &_Name,
                const std::string &_Body);

    void Retrieve(const std::string &_Path, const std::string &_Xml);

    void Retrieve(const std::string &_Path, const std::string &_Xml,HttpUtil::Http_Rsp* _Rsp);

    void Update(const std::string &_Path, const std::string &_Body);

    void Delete(const std::string &_Path);
}


#endif //GATEWAY_CSE_TEST_TOOL_H
