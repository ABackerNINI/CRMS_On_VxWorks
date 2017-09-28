#pragma once

#ifndef _CRMS_REQUEST_HANDLER_H_
#define _CRMS_REQUEST_HANDLER_H_

#include "../../../utility/HttpUtil/HttpUtil.h"
#include "../../../utility/HttpUtil/mongoose.h"
#include "../../../utility/HttpUtil/Server.h"

namespace cse {

    namespace protocol {

        namespace agent {

            namespace request_handler {

                void on_request(/*IN*/ HttpUtil::Http_Req *http_req,/*OUT*/ HttpUtil::Http_Rsp *http_rsp);

                void on_error(HttpUtil::server::ErrCode errcode, http_message *_Hm, mg_connection *_Nc, void *_Extra);
            }
        }
    }
}

#endif//_CRMS_REQUEST_HANDLER_H_
