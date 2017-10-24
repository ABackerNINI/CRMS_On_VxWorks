#include "request_handler.h"
#include "../../common.h"
#include "../../keyword.h"
#include "../../resource/crms_primitive/CRMS_Rsp.h"
#include "../../resource/crms_primitive/CRMS_Req.h"
#include "../../../utility/resource_pool/resource_pool.h"
#include "../../resource/crms_resource/CRMS_Resource.h"
#include "../resource_handler/resource_handler.h"

bool check_req_headers(HttpUtil::Http_Req *http_req) {
    return true;
}

crms::protocol::resource::primitive::CRMS_Rsp request_dispatch(HttpUtil::Http_Req *http_req) {

    crms::protocol::resource::primitive::CRMS_Req crms_req;

    crms_req.set_to(http_req->Uri);
//    std::map<std::string, std::string>::const_iterator it = http_req->Headers.find(KW_HEADERS_FROM);
//    if (it != http_req->Headers.end())
//        crms_req.set_fr(it->second);

    if (http_req->Method == HttpUtil::POST) {//CREATE
        std::map<std::string, std::string>::const_iterator it_ty = http_req->Querys.find(KW_TYPE_SHORT);
        std::map<std::string, std::string>::const_iterator it_rn = http_req->Querys.find(KW_RESOURCE_NAME_SHORT);

        if (it_ty == http_req->Querys.end()) {
            LOGEVT("'ty' Not Found in URL @request_dispatch");

            return crms::protocol::resource::primitive::CRMS_Rsp(&crms_req,
                                                 crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
        }

        char *p = NULL;
        int ty = (int) strtol(it_ty->second.c_str(), &p, 10);
        ////TODO:handle error
        crms_req.set_ty(ty);
        if (it_rn != http_req->Querys.end()) {
            crms_req.set_rn(it_rn->second);
        }

        crms::protocol::resource::primitive::CRMS_PrimitiveContentType pc;

        crms_req.set_pc(pc);
        crms_req.set_op(crms::protocol::resource::enumeration::CRMS_Operation::Create);
    } else if (http_req->Method == HttpUtil::GET) {//RETRIEVE
        std::map<std::string, std::string>::const_iterator it_q = http_req->Querys.find(KW_QUERY_Q);
        if (it_q != http_req->Querys.end()) {
            if (it_q->second.compare(KV_QUERY_Q_PR) == 0) {
                std::map<std::string, std::string>::const_iterator it_in = http_req->Querys.find(KW_QUERY_Q_PR_IN);
                if (it_in != http_req->Querys.end()) {
//                    crms_req.retrieve_query.retrieve_query_pr.pr = it_in->second.c_str();
//                    crms_req.retrieve_query.retrieve_query_pr.ty = crms::protocol::resource::primitive::CRMS_Req::IN;
//                    crms_req.set_pc(crms::protocol::resource::resource::CRMS_PrimitiveContentType(it_in->second));
//                    crms_req.set_ty(2);//in////TODO:enumeration-lism ex and op
                } else {
                    std::map<std::string, std::string>::const_iterator it_ex = http_req->Querys.find(KW_QUERY_Q_PR_EX);
                    if (it_ex != http_req->Querys.end()) {
//                        crms_req.retrieve_query.retrieve_query_pr.pr = it_ex->second.c_str();
//                        crms_req.retrieve_query.retrieve_query_pr.ty = crms::protocol::resource::primitive::CRMS_Req::EX;
//                        crms_req.set_pc(crms::protocol::resource::resource::CRMS_PrimitiveContentType(it_ex->second));
//                        crms_req.set_ty(3);//ex
                    } else {
                        ////TODO:handle error
                    }
                }
//                crms_req.retrieve_query.ty = crms::protocol::resource::primitive::CRMS_Req::PR;
            } else if (it_q->second.compare(KV_QUERY_Q_PG) == 0) {
                std::map<std::string, std::string>::const_iterator it_offset = http_req->Querys.find(
                        KW_QUERY_Q_PG_OFFSET);
                if (it_offset != http_req->Querys.end()) {
//                    crms_req.retrieve_query.retrieve_query_pg.offset = (int) strtol(it_offset->second.c_str(), NULL,
//                                                                                    10);
                } else {
//                    crms_req.retrieve_query.retrieve_query_pg.offset = 0;
                }
                std::map<std::string, std::string>::const_iterator it_len = http_req->Querys.find(KW_QUERY_Q_PG_LEN);
                if (it_len != http_req->Querys.end()) {
//                    crms_req.retrieve_query.retrieve_query_pg.len = (int) strtol(it_len->second.c_str(), NULL, 10);
                } else {
//                    crms_req.retrieve_query.retrieve_query_pg.len = 10;////mark:default pg len
                }

//                crms_req.retrieve_query.ty = resource::primitive::CRMS_Req::PG;
            } else if (it_q->second.compare(KV_QUERY_Q_SR) == 0) {
//                crms_req.retrieve_query.ty = resource::primitive::CRMS_Req::SR;
            }
        }
        crms_req.set_op(crms::protocol::resource::enumeration::CRMS_Operation::Retrieve);
    } else if (http_req->Method == HttpUtil::PUT) {//UPDATE
//        crms_req.set_pc(crms::protocol::resource::primitive::CRMS_PrimitiveContentType(http_req->Body.c_str()));
        crms_req.set_op(crms::protocol::resource::enumeration::CRMS_Operation::Update);
    } else if (http_req->Method == HttpUtil::DELETE) {//DELETE
        crms_req.set_op(crms::protocol::resource::enumeration::CRMS_Operation::Delete);
    } else {
        return crms::protocol::resource::primitive::CRMS_Rsp(&crms_req,
                                                             crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
    }

    crms::protocol::resource::resource::CRMS_Resource *resource = NULL;

    if (http_req->Uri.empty()) {
        LOGEVT("Request Path Is NULL @request_dispatch");

        return crms::protocol::resource::primitive::CRMS_Rsp(&crms_req,
                                                             crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
    }

    resource = (crms::protocol::resource::resource::CRMS_Resource *) resource_pool::get_instance().get_resource_from_id(http_req->Uri);

    if (resource == NULL) {
        LOGEVT("Resource Not Found @request_dispatch");
        crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType rsc;
        switch (crms_req.get_op().get_val()) {
            case crms::protocol::resource::enumeration::CRMS_Operation::Create:
                rsc = crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request;////mark
                break;
            case crms::protocol::resource::enumeration::CRMS_Operation::Retrieve:
                rsc = crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Retrieve_error_does_not_exist;
                break;
            case crms::protocol::resource::enumeration::CRMS_Operation::Update:
                rsc = crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Update_error_does_not_exist;
                break;
            case crms::protocol::resource::enumeration::CRMS_Operation::Delete:
                rsc = crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Delete_error_does_not_exist;
                break;
            default:
                assert(false);
        }
        return crms::protocol::resource::primitive::CRMS_Rsp(&crms_req, rsc);
    }

    crms::protocol::resource::primitive::CRMS_Rsp crms_rsp;
    crms::protocol::agent::resource_handler::resource_handler::handle_crud(&crms_req, &crms_rsp, resource);

    return crms_rsp;
}

void cse::protocol::agent::request_handler::on_request(HttpUtil::Http_Req *http_req, HttpUtil::Http_Rsp *http_rsp) {
    if (check_req_headers(http_req)) {
        crms::protocol::resource::primitive::CRMS_Rsp crms_rsp = request_dispatch(http_req);

        char *s = serialize(crms_rsp.get_pc());////TODO:handle error

        http_rsp->Body = s;

        delete[]s;

        http_rsp->Headers[KW_HEADERS_HOST] = KV_HEADERS_HOST;

        std::map<std::string, std::string>::const_iterator X_M2M_RI_Iter = http_req->Headers.find(KW_HEADERS_X_CRMS_RI);
        if (X_M2M_RI_Iter != http_req->Headers.end())
            http_rsp->Headers[KW_HEADERS_X_CRMS_RI] = X_M2M_RI_Iter->second;

        http_rsp->Status_Code = 200;
        http_rsp->Status_Msg = "OK";
    } else {
        http_rsp->Headers[KW_HEADERS_HOST] = KV_HEADERS_HOST;

        std::map<std::string, std::string>::const_iterator X_M2M_RI_Iter = http_req->Headers.find(KW_HEADERS_X_CRMS_RI);
        if (X_M2M_RI_Iter != http_req->Headers.end())
            http_rsp->Headers[KW_HEADERS_X_CRMS_RI] = X_M2M_RI_Iter->second;

        http_rsp->Status_Code = 400;
        http_rsp->Status_Msg = "Bad Request";
    }
}


void cse::protocol::agent::request_handler::on_error(HttpUtil::server::ErrCode errcode, http_message *_Hm,
                                                     mg_connection *_Nc, void *_Extra) {
    char _errcode[10];
    sprintf(_errcode, "%d", errcode);
    LOGEVT("%s", _errcode);
}