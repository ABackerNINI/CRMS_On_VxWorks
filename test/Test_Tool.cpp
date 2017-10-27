//
// Created by nini on 11/9/16.
//

#include "Test_Tool.h"

std::map<std::string, std::string> Test_Tool::GetHeaders() {
    std::map<std::string, std::string> _Headers;
    _Headers["Host"] = "/CSEBase";
    _Headers["Accept"] = "application/onem2m-resource+xml";
    _Headers["From"] = "/CSEBaseID";
    _Headers["Content-type"] = "application/onem2m-resource+xml";
    _Headers["X-M2M-RI"] = "ID";

    return _Headers;
}

void Test_Tool::Create(const std::string &_Path,
                       const enumeration::m2m_resourceType &_Type,
                       const std::string &_Name,
                       const std::string &_Xml) {
//    std::cout << "Create:" << (_URL + _Path + "?rn=" + _Name + "&ty=" + Common::to_string(_Type.val)) << std::endl;

    HttpUtil::Http_Req _Req;
    {
        _Req.Method = HttpUtil::POST;
        _Req.Uri = (_URL + _Path);
        _Req.Headers = GetHeaders();
        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
        _Req.Body = _Xml;
        _Req.Queries["rn"] = _Name;
        _Req.Queries["ty"] = Common::to_string(_Type.val);
    }

    HttpUtil::Http_Rsp _Rsp;
    HttpUtil::Client::ErrCode _ErrCode;

    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
}

void Test_Tool::Retrieve(const std::string &_Path, const std::string &_Xml) {
//    std::cout << "Retrieve:" << (_URL + _Path) << std::endl;

    HttpUtil::Http_Req _Req;
    {
        _Req.Method = HttpUtil::GET;
        _Req.Uri = (_URL + _Path);
        _Req.Headers = GetHeaders();
        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
        _Req.Body = _Xml;
    }

    HttpUtil::Http_Rsp _Rsp;
    HttpUtil::Client::ErrCode _ErrCode;

    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
    std::cout<<_Rsp.Body<<std::endl;
}

void Test_Tool::Retrieve(const std::string &_Path, const std::string &_Xml,HttpUtil::Http_Rsp* _Rsp) {
//    std::cout << "Retrieve:" << (_URL + _Path) << std::endl;

    HttpUtil::Http_Req _Req;
    {
        _Req.Method = HttpUtil::GET;
        _Req.Uri = (_URL + _Path);
        _Req.Headers = GetHeaders();
        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
        _Req.Body = _Xml;
    }

    HttpUtil::Client::ErrCode _ErrCode;

    HttpUtil::Client::SendRequestSync(&_Req, _Rsp, &_ErrCode);
}

void Test_Tool::Update(const std::string &_Path, const std::string &_Xml) {
//    std::cout << "Update:" << (_URL + _Path) << std::endl;

    HttpUtil::Http_Req _Req;
    {
        _Req.Method = HttpUtil::PUT;
        _Req.Uri = (_URL + _Path);
        _Req.Headers = GetHeaders();
        _Req.Headers["Content-Length"] = std::to_string(_Xml.length());
        _Req.Body = _Xml;
    }

    HttpUtil::Http_Rsp _Rsp;
    HttpUtil::Client::ErrCode _ErrCode;

    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
}

void Test_Tool::Delete(const std::string &_Path) {
//    std::cout << "Delete:" << (_URL + _Path) << std::endl;

    HttpUtil::Http_Req _Req;
    {
        _Req.Method = HttpUtil::DELETE;
        _Req.Uri = (_URL + _Path);
        _Req.Headers = GetHeaders();
        _Req.Headers["Content-Length"] = "0";
    }

    HttpUtil::Http_Rsp _Rsp;
    HttpUtil::Client::ErrCode _ErrCode;

    HttpUtil::Client::SendRequestSync(&_Req, &_Rsp, &_ErrCode);
}
