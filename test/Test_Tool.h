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

//    static const std::string _URL = "127.0.0.1:8080";
    static const std::string _URL = "192.168.1.1:8080";
    template<class _Ty>
    std::string Serialize(const _Ty &_Instance) {
        xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
        {
            xmlNodePtr _Rnode = xmlNewNode(NULL, BAD_CAST "pc");
            {
                xmlNewProp(_Rnode, BAD_CAST "xmlns:m2m", BAD_CAST "http://www.onem2m.org/xml/protocols");
                xmlAddChild(_Rnode, _Instance.BuildNode());
            }

            xmlDocSetRootElement(doc, _Rnode);
        }

        const char *__Str = save_doc(doc, 1);

        std::string _Ret(__Str);

        delete[]__Str;

        return _Ret;
    }

    template<class _Ty>
    _Ty Deserialize(const char *_Str) {
        _Ty _Attr;
        xmlDocPtr doc = xmlParseDoc(BAD_CAST _Str);
        xmlNodePtr _Rnode = xmlDocGetRootElement(doc);

        xmlNodePtr _Node = _Rnode->children;
        while (_Node && _Node->type != XML_ELEMENT_NODE)_Node = _Node->next;

        _Attr.ParseNode(_Node);

        xmlFreeDoc(doc);

        return _Attr;
    }

    std::map<std::string, std::string> GetHeaders();

    template<class _Ty>
    std::string GetCreateXml(const _Ty &_Instance) {
        return Test_Tool::Serialize(_Instance);
    }

    std::string GetRetrieveXml(const std::string &_Attrs);

    template<class _Ty>
    std::string GetUpdateXml(const _Ty &_Instance) {
        return Test_Tool::Serialize(_Instance);
    }

    std::string GeDeleteXml();

    void Create(const std::string &_Path,
                const enumeration::m2m_resourceType &_Type,
                const std::string &_Name,
                const std::string &_Xml);

    void Retrieve(const std::string &_Path, const std::string &_Xml);

    void Retrieve(const std::string &_Path, const std::string &_Xml,HttpUtil::Http_Rsp* _Rsp);

    void Update(const std::string &_Path, const std::string &_Xml);

    void Delete(const std::string &_Path);
}


#endif //GATEWAY_CSE_TEST_TOOL_H
