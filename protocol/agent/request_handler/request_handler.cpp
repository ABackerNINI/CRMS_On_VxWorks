#include "request_handler.h"
#include "../../common.h"
#include "../../keyword.h"
#include "../../resource/crms_primitive/CRMS_Rsp.h"
#include "../../resource/crms_primitive/CRMS_Req.h"
#include "../../../utility/resource_pool/resource_pool.h"
#include "../../resource/crms_resource/CRMS_Resource.h"
#include "../resource_handler/resource_handler.h"
#include "../../resource/support/PrimitiveContentTypeSupport.h"
#include "../../resource/crms_common/CRMS_RetrieveQuery.h"

bool check_req_headers(HttpUtil::Http_Req *http_req) {
    return true;
}

crms::protocol::resource::primitive::CRMS_Rsp request_dispatch(HttpUtil::Http_Req *http_req) {
    crms::protocol::resource::primitive::CRMS_Req crms_req;
    crms::protocol::resource::primitive::CRMS_Rsp crms_rsp;

    crms_req.set_to(http_req->Uri);
    std::map<std::string, std::string>::const_iterator it_ri = http_req->Headers.find(KW_HEADERS_X_CRMS_RI);
    if (it_ri != http_req->Headers.end())
        crms_req.set_rqi(it_ri->second);
    else {
        static int rqi = 0;

        char rqi_str[11];
        sprintf(rqi_str, "%d", rqi++);

        crms_req.set_rqi(rqi_str);
    }

    if (http_req->Method == HttpUtil::POST) {////CREATE
        std::map<std::string, std::string>::const_iterator it_ty = http_req->Queries.find(KW_TYPE_SHORT);
        std::map<std::string, std::string>::const_iterator it_rn = http_req->Queries.find(KW_RESOURCE_NAME_SHORT);

        if (it_ty == http_req->Queries.end()) {
            LOGEVT("'ty' Not Found in URL @request_dispatch");

            return crms::protocol::resource::primitive::CRMS_Rsp(&crms_req,
                                                                 crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
        }

        char *p = NULL;
        int ty = (int) strtol(it_ty->second.c_str(), &p, 10);
        ////TODO:handle error
        if (it_rn != http_req->Queries.end()) {
            crms_req.set_rn(it_rn->second);
        }

        crms_req.set_ty(ty);
        crms_req.get_pc().set_val((void *) http_req->Body.c_str());
        crms_req.set_op(crms::protocol::resource::enumeration::CRMS_Operation::Create);
    } else if (http_req->Method == HttpUtil::GET) {////RETRIEVE
        std::map<std::string, std::string>::const_iterator it_q = http_req->Queries.find(KW_QUERY_Q);
        if (it_q != http_req->Queries.end()) {
            crms::protocol::resource::common::CRMS_RetrieveQuery *rq = &(crms_rsp.get_pc().get_rq());////mark:const?

            if (it_q->second.compare(KV_QUERY_Q_PR) == 0) {////PR
                crms::protocol::resource::common::CRMS_PartialRetrieve *pr = &(rq->get_val().get_pr());

                rq->set_ty(crms::protocol::resource::common::CRMS_RetrieveQueryType::PartialRetrieve);

                std::map<std::string, std::string>::const_iterator it_in = http_req->Queries.find(KW_QUERY_Q_PR_IN);

                if (it_in != http_req->Queries.end()) {////IN
                    pr->set_ty(crms::protocol::resource::common::CRMS_PartialRetrieveType::In);
                    pr->set_val(it_in->second.c_str());
                } else {////EX
                    std::map<std::string, std::string>::const_iterator it_ex = http_req->Queries.find(KW_QUERY_Q_PR_EX);
                    if (it_ex != http_req->Queries.end()) {
                        pr->set_ty(crms::protocol::resource::common::CRMS_PartialRetrieveType::Ex);
                        pr->set_val(it_ex->second.c_str());
                    } else {
                        ////TODO:handle error
                    }
                }
            } else if (it_q->second.compare(KV_QUERY_Q_PG) == 0) {////PG
                crms::protocol::resource::common::CRMS_PaginationRetrieve *pg = &(rq->get_val().get_pg());

                rq->set_ty(crms::protocol::resource::common::CRMS_RetrieveQueryType::PaginationRetrieve);

                std::map<std::string, std::string>::const_iterator it_offset = http_req->Queries.find(
                        KW_QUERY_Q_PG_OFFSET);
                if (it_offset != http_req->Queries.end()) {
                    pg->set_offset((int) strtol(it_offset->second.c_str(), NULL, 10));
                } else {
                    pg->set_offset(0);
                }
                std::map<std::string, std::string>::const_iterator it_len = http_req->Queries.find(KW_QUERY_Q_PG_LEN);
                if (it_len != http_req->Queries.end()) {
                    pg->set_len((int) strtol(it_len->second.c_str(), NULL, 10));
                } else {
                    pg->set_len(10);
                }
            } else if (it_q->second.compare(KV_QUERY_Q_SR) == 0) {////SR
                rq->set_ty(crms::protocol::resource::common::CRMS_RetrieveQueryType::SubscriptionRetrieve);

                crms::protocol::resource::common::CRMS_SubscriptionRetrieve *sr = &(rq->get_val().get_sr());

                ////TODO
            }
        }

        crms_req.set_op(crms::protocol::resource::enumeration::CRMS_Operation::Retrieve);
    } else if (http_req->Method == HttpUtil::PUT) {////UPDATE
        crms_req.get_pc().set_val((void *) http_req->Body.c_str());
        crms_req.set_op(crms::protocol::resource::enumeration::CRMS_Operation::Update);
    } else if (http_req->Method == HttpUtil::DELETE) {////DELETE
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

    resource = (crms::protocol::resource::resource::CRMS_Resource *) resource_pool::get_instance().get_resource_from_id(
            http_req->Uri);

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

    crms::protocol::agent::resource_handler::resource_handler::handle_crud(&crms_req, &crms_rsp, resource);

    return crms_rsp;
}

void cse::protocol::agent::request_handler::on_request(HttpUtil::Http_Req *http_req, HttpUtil::Http_Rsp *http_rsp) {
    if (check_req_headers(http_req)) {
        crms::protocol::resource::primitive::CRMS_Rsp crms_rsp = request_dispatch(http_req);

        char *s = serialize_pc(&(crms_rsp.get_pc()));////TODO:handle error

        http_rsp->Body = s;

        delete[]s;

        http_rsp->Headers[KW_HEADERS_HOST] = KV_HEADERS_HOST;

//        std::map<std::string, std::string>::const_iterator X_M2M_RI_Iter = http_req->Headers.find(KW_HEADERS_X_CRMS_RI);
//        if (X_M2M_RI_Iter != http_req->Headers.end())
//            http_rsp->Headers[KW_HEADERS_X_CRMS_RI] = X_M2M_RI_Iter->second;

        char rsc[11];
        sprintf(rsc, "%d", crms_rsp.get_rsc().get_val());

        http_rsp->Headers[KW_HEADERS_X_CRMS_RI] = crms_rsp.get_rqi();
        http_rsp->Headers[KW_HEADERS_X_CRMS_RSC] = std::string(rsc);

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