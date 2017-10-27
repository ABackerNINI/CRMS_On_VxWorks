//
// Created by nini on 11/9/16.
//

#include "Test_Tool.h"
#include "../utility/HttpUtil/Client.h"
#include "../protocol/keyword.h"
#include "../protocol/resource/support/PrimitiveContentTypeSupport.h"

std::map<std::string, std::string> test_tool::GetHeaders() {
    std::map<std::string, std::string> _Headers;
    _Headers[KW_HEADERS_HOST] = "test_client_test_create";
    _Headers[KW_HEADERS_X_CRMS_RI] = "1";

    return _Headers;
}

std::string serialize_resource(const crms::protocol::resource::resource::CRMS_Resource *resource) {
    crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> pc;
    pc.set_ty(resource->get_ty());
    pc.set_val((void *) resource);
    char *s = serialize_pc(&pc);

    std::string ret = s;

    delete[]s;

    return ret;
}

bool test_tool::Create(const std::string &path, const std::string &name,
                      const crms::protocol::resource::resource::CRMS_Resource *resource) {
    HttpUtil::Http_Req req;
    {
        char ty_str[11];
        sprintf(ty_str, "%d", resource->get_ty());

        req.Method = HttpUtil::POST;
        req.Uri = URL + path;
        req.Headers = GetHeaders();
        req.Body = serialize_resource(resource);
        req.Queries["rn"] = name;
        req.Queries["ty"] = std::string(ty_str);
    }

    HttpUtil::Http_Rsp rsp;
    HttpUtil::Client::ErrCode err_code;

    HttpUtil::Client::SendRequestSync(&req, &rsp, &err_code);

    if (err_code != HttpUtil::Client::OK) {
        printf("error code:%d\n", err_code);
    }

    return rsp.Headers[KW_HEADERS_X_CRMS_RSC] == RSC_OK;
}

void test_tool::Retrieve(const std::string &path, crms::protocol::resource::common::CRMS_PartialRetrieve pr) {

}

void test_tool::Retrieve(const std::string &path, crms::protocol::resource::common::CRMS_PaginationRetrieve pg) {

}

void test_tool::Retrieve(const std::string &path, crms::protocol::resource::common::CRMS_SubscriptionRetrieve sr) {

}

void test_tool::Update(const std::string &path, const std::string &body) {

}

void test_tool::Delete(const std::string &path) {

}

//void test_tool::Create(const std::string &_Path,
//                       const enumeration::m2m_resourceType &_Type,
//                       const std::string &_Name,
//                       const std::string &_Xml) {
////    std::cout << "Create:" << (_URL + _Path + "?rn=" + _Name + "&ty=" + Common::to_string(_Type.val)) << std::endl;
//
//    HttpUtil::Http_Req _Req;
//    {
//        _Req.Method = HttpUtil::POST;
//        _Req.Uri = (_URL + _Path);
//        _Req.Headers = GetHeaders();
//        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
//        _Req.Body = _Xml;
//        _Req.Queries["rn"] = _Name;
//        _Req.Queries["ty"] = Common::to_string(_Type.val);
//    }
//
//    HttpUtil::Http_Rsp _Rsp;
//    HttpUtil::Client::ErrCode _ErrCode;
//
//    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
//}
//
//void test_tool::Retrieve(const std::string &_Path, const std::string &_Xml) {
////    std::cout << "Retrieve:" << (_URL + _Path) << std::endl;
//
//    HttpUtil::Http_Req _Req;
//    {
//        _Req.Method = HttpUtil::GET;
//        _Req.Uri = (_URL + _Path);
//        _Req.Headers = GetHeaders();
//        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
//        _Req.Body = _Xml;
//    }
//
//    HttpUtil::Http_Rsp _Rsp;
//    HttpUtil::Client::ErrCode _ErrCode;
//
//    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
//    std::cout<<_Rsp.Body<<std::endl;
//}
//
//void test_tool::Retrieve(const std::string &_Path, const std::string &_Xml,HttpUtil::Http_Rsp* _Rsp) {
////    std::cout << "Retrieve:" << (_URL + _Path) << std::endl;
//
//    HttpUtil::Http_Req _Req;
//    {
//        _Req.Method = HttpUtil::GET;
//        _Req.Uri = (_URL + _Path);
//        _Req.Headers = GetHeaders();
//        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
//        _Req.Body = _Xml;
//    }
//
//    HttpUtil::Client::ErrCode _ErrCode;
//
//    HttpUtil::Client::SendRequestSync(&_Req, _Rsp, &_ErrCode);
//}
//
//void test_tool::Update(const std::string &_Path, const std::string &_Xml) {
////    std::cout << "Update:" << (_URL + _Path) << std::endl;
//
//    HttpUtil::Http_Req _Req;
//    {
//        _Req.Method = HttpUtil::PUT;
//        _Req.Uri = (_URL + _Path);
//        _Req.Headers = GetHeaders();
//        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
//        _Req.Body = _Xml;
//    }
//
//    HttpUtil::Http_Rsp _Rsp;
//    HttpUtil::Client::ErrCode _ErrCode;
//
//    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
//}
//
//void test_tool::Delete(const std::string &_Path) {
////    std::cout << "Delete:" << (_URL + _Path) << std::endl;
//
//    HttpUtil::Http_Req _Req;
//    {
//        _Req.Method = HttpUtil::DELETE;
//        _Req.Uri = (_URL + _Path);
//        _Req.Headers = GetHeaders();
//        _Req.Headers["Content-Length"] = "0";
//    }
//
//    HttpUtil::Http_Rsp _Rsp;
//    HttpUtil::Client::ErrCode _ErrCode;
//
//    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
//}

