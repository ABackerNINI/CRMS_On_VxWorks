//
// Created by nini on 11/9/16.
//

#include "Test_Tool.h"
#include "../utility/HttpUtil/Client.h"
#include "../protocol/keyword.h"
#include "../protocol/resource/support/PrimitiveContentTypeSupport.h"
#include "../protocol/common.h"

std::map<std::string, std::string> test_tool::GetHeaders() {
    std::map<std::string, std::string> _Headers;
    _Headers[KW_HEADERS_HOST] = "test_tool";
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
        req.Queries["rn"] = name;
        req.Queries["ty"] = std::string(ty_str);
        req.Body = serialize_resource(resource);
    }

    HttpUtil::Http_Rsp rsp;
    HttpUtil::Client::ErrCode err_code;

    HttpUtil::Client::SendRequestSync(&req, &rsp, &err_code);

    if (err_code != HttpUtil::Client::OK) {
        printf("error code:%d\n", err_code);

        return false;
    }

    return rsp.Headers[KW_HEADERS_X_CRMS_RSC] == RSC_OK;
}

bool test_tool::Retrieve(const std::string &path, HttpUtil::Http_Req *req) {
    HttpUtil::Http_Req tmp;
    if (req == NULL)req = &tmp;
    {
        req->Method = HttpUtil::GET;
        req->Uri = URL + path;
        req->Headers = GetHeaders();
    }

    HttpUtil::Http_Rsp rsp;
    HttpUtil::Client::ErrCode err_code;

    HttpUtil::Client::SendRequestSync(req, &rsp, &err_code);

    if (err_code != HttpUtil::Client::OK) {
        printf("error code:%d\n", err_code);

        return false;
    }

    return rsp.Headers[KW_HEADERS_X_CRMS_RSC] == RSC_OK;
}

bool test_tool::Retrieve(const std::string &path, const crms::protocol::resource::common::CRMS_PartialRetrieve &pr) {
    HttpUtil::Http_Req req;
    req.Queries[KW_QUERY_Q] = KV_QUERY_Q_PR;
    req.Queries[pr.get_ty() == crms::protocol::resource::common::CRMS_PartialRetrieveType::In ? KW_QUERY_Q_PR_IN
                                                                                              : KW_QUERY_Q_PR_EX] = pr.get_val();

    return Retrieve(path, &req);
}

bool test_tool::Retrieve(const std::string &path, const crms::protocol::resource::common::CRMS_PaginationRetrieve &pg) {
    HttpUtil::Http_Req req;
    char str[11];

    req.Queries[KW_QUERY_Q] = KV_QUERY_Q_PG;
    sprintf(str, "%d", pg.get_offset());
    req.Queries[KW_QUERY_Q_PG_OFFSET] = std::string(str);
    sprintf(str, "%d", pg.get_len());
    req.Queries[KW_QUERY_Q_PG_LEN] = std::string(str);

    return Retrieve(path, &req);
}

bool test_tool::Retrieve(const std::string &path,
                         const crms::protocol::resource::common::CRMS_SubscriptionRetrieve &sr) {
    HttpUtil::Http_Req req;
    req.Queries[KW_QUERY_Q] = KV_QUERY_Q_SR;
    req.Queries[KW_QUERY_Q_SR_ID] = sr.get_id();

    return Retrieve(path, &req);
}

bool test_tool::Update(const std::string &path, const crms::protocol::resource::resource::CRMS_Resource *resource) {
    HttpUtil::Http_Req req;
    {
        req.Method = HttpUtil::PUT;
        req.Uri = URL + path;
        req.Headers = GetHeaders();
        req.Body = serialize_resource(resource);
    }

    HttpUtil::Http_Rsp rsp;
    HttpUtil::Client::ErrCode err_code;

    HttpUtil::Client::SendRequestSync(&req, &rsp, &err_code);

    if (err_code != HttpUtil::Client::OK) {
        printf("error code:%d\n", err_code);

        return false;
    }

    return rsp.Headers[KW_HEADERS_X_CRMS_RSC] == RSC_OK;
}

bool test_tool::Delete(const std::string &path) {
    HttpUtil::Http_Req req;
    {
        req.Method = HttpUtil::DELETE;
        req.Uri = URL + path;
        req.Headers = GetHeaders();
    }

    HttpUtil::Http_Rsp rsp;
    HttpUtil::Client::ErrCode err_code;

    HttpUtil::Client::SendRequestSync(&req, &rsp, &err_code);

    if (err_code != HttpUtil::Client::OK) {
        printf("error code:%d\n", err_code);

        return false;
    }

    return rsp.Headers[KW_HEADERS_X_CRMS_RSC] == RSC_OK;
}

int test_tool::Test(test_func *funcs, int n) {
    bool *rst = new bool[n];
    int failed = 0;

    for (int i = 0; i < n; ++i) {
        LOGEVT("test_%d begin", i + 1);
        rst[i] = funcs[i] ? funcs[i]() : true;
        LOGEVT("test_%d end", i + 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!rst[i]) {
            ++failed;
            printf("test_%d failed!\n", i + 1);
        }
    }

    if (failed == 0) {
        printf("all tests succeed!\n");
    }

    delete[]rst;

    return failed;
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

