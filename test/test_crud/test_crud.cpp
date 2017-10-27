//
// Created by nini on 9/28/17.
//

#include "../../utility/HttpUtil/HttpUtil.h"
#include "../../utility/HttpUtil/Client.h"
#include "../../protocol/resource/crms_resource/CRMS_ResourceObject.h"
#include "../../protocol/keyword.h"
#include "../../protocol/resource/crms_resource/CRMS_Attribute.h"
#include "../../protocol/resource/crms_resource/CRMS_Command.h"
#include "../../protocol/resource/crms_resource/CRMS_DataTable.h"
#include "../../protocol/resource/support/PrimitiveContentTypeSupport.h"

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
        http_req.Querys["ty"] = to_string(crms::protocol::resource::enumeration::CRMS_MemberType::resourceObject);

        crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_ResourceObject> pc;
        {
            pc.set_ty(crms::protocol::resource::enumeration::CRMS_MemberType::resourceObject);
            crms::protocol::resource::resource::CRMS_ResourceObject resource_object;
            {
                resource_object.set_onto("dasdas");
            }
            pc.set_val(&resource_object);
        };
        char *s = serialize_pc((crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *)&pc);

        http_req.Body = s;

        delete[]s;
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

//    {
//        http_req.Method = HttpUtil::POST;
//        http_req.Uri = "http://localhost:8080/root/1";
//        http_req.Headers[KW_HEADERS_X_CRMS_RI] = "11111";
//        http_req.Querys["ty"] = to_string(crms::protocol::resource::enumeration::CRMS_MemberType::attribute);
//        crms::protocol::resource::primitive::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Attribute> req_rsp;
//        {
//            req_rsp.set_ty(crms::protocol::resource::enumeration::CRMS_MemberType::attribute);
//            crms::protocol::resource::resource::CRMS_Attribute attribute;
//            {
//                attribute.set_nm("attr");
//            }
//            req_rsp.set_val(&attribute);
//        };
//        char *s = serialize(req_rsp);
//
//        http_req.Body = s;
//
//        delete[]s;
//    }
//    HttpUtil::Client::SendRequestAsyn(&http_req, callback);
//
//    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    std::cin.getline(cmd, 100);
//
//    {
//        http_req.Method = HttpUtil::POST;
//        http_req.Uri = "http://localhost:8080/root/1";
//        http_req.Headers[KW_HEADERS_X_CRMS_RI] = "11111";
//        http_req.Querys["ty"] = to_string(crms::protocol::resource::enumeration::CRMS_MemberType::command);
//        crms::protocol::resource::primitive::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Command> req_rsp;
//        {
//            req_rsp.set_ty(crms::protocol::resource::enumeration::CRMS_MemberType::command);
//            crms::protocol::resource::resource::CRMS_Command command;
//            {
//                command.set_con("command");
//            }
//            req_rsp.set_val(&command);
//        };
//        char *s = serialize(req_rsp);
//
//        http_req.Body = s;
//
//        delete[]s;
//    }
//    HttpUtil::Client::SendRequestAsyn(&http_req, callback);
//
//    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    std::cin.getline(cmd, 100);
//
//    {
//        http_req.Method = HttpUtil::POST;
//        http_req.Uri = "http://localhost:8080/root/1";
//        http_req.Headers[KW_HEADERS_X_CRMS_RI] = "11111";
//        http_req.Querys["ty"] = to_string(crms::protocol::resource::enumeration::CRMS_MemberType::dataTable);
//        crms::protocol::resource::primitive::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_DataTable> req_rsp;
//        {
//            req_rsp.set_ty(crms::protocol::resource::enumeration::CRMS_MemberType::dataTable);
//            crms::protocol::resource::resource::CRMS_DataTable dataTable;
//            {
//                dataTable.set_rn("dt");
//            }
//            req_rsp.set_val(&dataTable);
//        };
//        char *s = serialize(req_rsp);
//
//        http_req.Body = s;
//
//        delete[]s;
//    }
//    HttpUtil::Client::SendRequestAsyn(&http_req, callback);
//
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

    {
        http_req.Method = HttpUtil::GET;
        http_req.Uri = "http://localhost:8080/root";
        http_req.Headers[KW_HEADERS_X_CRMS_RI] = "11111";
        http_req.Querys["q"] = "pr";
        http_req.Querys["ex"] = "ty,pa,lt";
    }
    HttpUtil::Client::SendRequestAsyn(&http_req, callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cin.getline(cmd, 100);

    HttpUtil::Client::StopAsynClient();

    return 0;
}