//
// Created by abacker on 11/24/16.
//

#ifndef FBS_SERVER_SERVER_H
#define FBS_SERVER_SERVER_H

#include "mongoose.h"
#include "HttpUtil.h"
#include <iostream>
#include <queue>
#include <map>

#define DEBUG_SHOW_REQ 1
#define DEBUG_SHOW_RSP 1

#if(DEBUG_SHOW_REQ)

#ifndef REQ_MTD_AND_URI_AND_QUERYS

#define REQ_MTD_AND_URI_AND_QUERYS 1
#define REQ_PROTOCOL 2
#define REQ_QUERYS  4
#define REQ_HEADERS 8
#define REQ_BODY 16
#define REQ_ALL 31
#define REQ_NONE 0

#endif

#endif

#if(DEBUG_SHOW_RSP)

#ifndef RSP_STATUS_CODE_AND_MSG

#define RSP_STATUS_CODE_AND_MSG 1
#define RSP_HEADERS 2
#define RSP_BODY 4
#define RSP_ALL 7
#define RSP_NONE 0

#endif

#endif

namespace HttpUtil {
    namespace server {

        enum ErrCode {
            ERR_PARSING,
            ERR_PARSING_METHOD,
            ERR_PARSING_PATH,
            ERR_PARSING_QUERYS,
            ERR_PARSING_HEADERS,
            ERR_PARSING_BODY
        };

        typedef void (*On_Request)(/*IN*/ Http_Req *,/*OUT*/ Http_Rsp *);

        typedef void (*On_Error)(ErrCode _ErrCode, http_message *_Hm, mg_connection *_Nc, void *_Extra);

        struct Callback {
            On_Request _On_Req;
            On_Error _On_Error;

            Callback() : _On_Req(NULL), _On_Error(NULL) {}

            Callback(On_Request _On_Req, On_Error _On_Error) : _On_Req(_On_Req), _On_Error(_On_Error) {}
        };


        static mg_mgr _Mgr;
        static pthread_t _EvLoopThread;
        static Callback _Callback;
//    static std::queue<http_message *> _Reqpool;

#if(DEBUG_SHOW_REQ)

        static int SETTING_SHOW_REQ = REQ_NONE;

        void _Show_Req(const Http_Req &_Req);

        void Show_Req(int SETTING_SHOW_REQ);

#endif

#if (DEBUG_SHOW_RSP)

        static int SETTING_SHOW_RSP = RSP_NONE;

        void _Show_Rsp(const Http_Rsp &_Rsp);

        void Show_Rsp(int SETTING_SHOW_RSP);

#endif

        void _CallOnError(ErrCode _ErrCode, http_message *_Hm, mg_connection *_Nc, void *_Extra);

        void _CallOnRequest(mg_connection *_Nc, Http_Req *_Req);

        bool _Parse_Http_Method(http_message *_Hm, Http_Req *_Req);

        bool _Parse_Http_Uri(http_message *_Hm, Http_Req *_Req);

        bool _Parse_Http_Proto(http_message *_Hm, Http_Req *_Req);

        bool _Parse_Http_Querys(http_message *_Hm, Http_Req *_Req);

        bool _Parse_Http_Headers(http_message *_Hm, Http_Req *_Req);

        bool _Parse_Http_Body(http_message *_Hm, Http_Req *_Req);

        void _Replay(mg_connection *_Nc, const Http_Rsp *_Rsp);

        bool _HandleRequest(mg_connection *_Nc, int _Ev, void *_Data);

        void _EvHandler(mg_connection *_Nc, int _Ev, void *_Data);

        void *_EvLoop(void *);

        bool Start(const char *_Port, Callback _Callback);

        bool Stop();
    }
}


#endif //FBS_SERVER_SERVER_H
