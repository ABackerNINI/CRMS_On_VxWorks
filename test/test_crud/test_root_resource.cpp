//
// Created by nini on 9/27/17.
//

#include "../../utility/HttpUtil/HttpUtil.h"
#include "../../utility/HttpUtil/Client.h"
#include "../../protocol/resource/crms_resource/CRMS_ResourceObject.h"
#include "../../protocol/resource/crms_resource/CRMS_Req_Rsp.h"
#include "../../protocol/keyword.h"

void On_Response(HttpUtil::Http_Rsp *http_rsp) {
    //printf("%s\n", http_rsp->Body.c_str());
}

void On_Error(HttpUtil::Client::ErrCode err_code, HttpUtil::Http_Rsp *rsp, http_message *msg, void *_Extra) {
    printf("%d\n", err_code);
}

int main() {
    HttpUtil::Client::StartAsynClient();
    HttpUtil::Client::Callback callback(On_Response, On_Error);

    char cmd[100];

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    HttpUtil::Http_Req http_req;
    {
        http_req.Method = HttpUtil::POST;
        http_req.Uri = "http://localhost:8080/root";
        http_req.Headers[KW_HEADERS_X_CRMS_RI] = "11111";
        http_req.Querys["ty"] = "2";

        crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_ResourceObject> req_rsp;
        {
            req_rsp.set_ty(2);
            crms::protocol::resource::resource::CRMS_ResourceObject resource_object;
            {
                resource_object.set_onto("dasdas");
            }
            req_rsp.set_val(&resource_object);
        };
        char *s = serialize(req_rsp);

        http_req.Body = s;

        delete[]s;
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

    {
        http_req.Method = HttpUtil::GET;
        http_req.Uri = "http://localhost:8080/root/untitled";
        http_req.Querys.clear();
        http_req.Querys[KW_QUERY_Q] = KV_QUERY_Q_PR;
        http_req.Querys[KW_QUERY_Q_PR_IN] = "ty,ri,pa";
        http_req.Body = "";
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);
    {
        http_req.Method = HttpUtil::PUT;
        http_req.Uri = "http://localhost:8080/root/untitled";
        http_req.Querys.clear();

        crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_ResourceObject> req_rsp;
        {
            req_rsp.set_ty(2);
            crms::protocol::resource::resource::CRMS_ResourceObject resource_object;
            {
                resource_object.set_onto("dasdas dfjaoe");
            }
            req_rsp.set_val(&resource_object);
        };
        char *s = serialize(req_rsp);

        http_req.Body = s;

        delete[]s;
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

    {
        http_req.Method = HttpUtil::GET;
        http_req.Uri = "http://localhost:8080/root/untitled";
        http_req.Querys.clear();
        http_req.Querys[KW_QUERY_Q] = KV_QUERY_Q_PR;
        http_req.Querys[KW_QUERY_Q_PR_EX] = "ty,ri,pa";
        http_req.Body = "";
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

    {
        http_req.Method = HttpUtil::DELETE;
        http_req.Uri = "http://localhost:8080/root/untitled";
        http_req.Querys.clear();
        http_req.Body = "";
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

    {
        http_req.Method = HttpUtil::GET;
        http_req.Uri = "http://localhost:8080/root/untitled";
        http_req.Querys.clear();
        http_req.Querys[KW_QUERY_Q] = KV_QUERY_Q_PR;
        http_req.Querys[KW_QUERY_Q_PR_EX] = "ty,onto";
        http_req.Body = "";
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

    HttpUtil::Client::StopAsynClient();

    return 0;
}