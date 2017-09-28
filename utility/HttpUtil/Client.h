//
// Created by abacker on 11/26/16.
//

#ifndef FBS_SERVER_CLIENT_H
#define FBS_SERVER_CLIENT_H

#include "mongoose.h"
#include "HttpUtil.h"


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
    namespace Client {
        enum ErrCode {
            OK,
            ERR_CONNECT,
            ERR_PARSING,
            ERR_PARSING_STATUS_CODE,
            ERR_PARSING_STATUS_MSG,
            ERR_PARSING_HEADERS,
            ERR_PARSING_BODY
        };

        typedef void (*On_Response)(Http_Rsp *);

        typedef void (*On_Error)(ErrCode, Http_Rsp *, http_message *, void *_Extra);

        struct Callback {
            On_Response _On_Rsp;
            On_Error _On_Error;

            Callback() : _On_Rsp(NULL), _On_Error(NULL) {}

            Callback(On_Response _On_Rsp, On_Error _On_Error) : _On_Rsp(_On_Rsp), _On_Error(_On_Error) {}
        };

        static mg_mgr *_Mgr = NULL;
        static std::map<mg_connection *, Callback> _CallbackPool;
        static pthread_t _EvLoopThread;
        static std::map<mg_connection *, std::pair<ErrCode, Http_Rsp *> > _RspPool;

#if(DEBUG_SHOW_REQ)

        static int SETTING_SHOW_REQ = REQ_ALL;

        void _Show_Req(const Http_Req &_Req);

        void Show_Req(int SETTING_SHOW_REQ);

#endif

#if (DEBUG_SHOW_RSP)

        static int SETTING_SHOW_RSP = RSP_ALL;

        void _Show_Rsp(const Http_Rsp &_Rsp);

        void Show_Rsp(int SETTING_SHOW_RSP);

#endif

        std::string _ToUrl(const Http_Req *_Req);

        std::string _ToHeaders(const Http_Req *_Req);

        std::string _ToMethod(const Http_Req *_Req);

        bool _Parse_Http_StatusCode(const http_message *_Hm, Http_Rsp *_Rsp);

        bool _Parse_Http_StatusMsg(const http_message *_Hm, Http_Rsp *_Rsp);

        bool _Parse_Http_Headers(const http_message *_Hm, Http_Rsp *_Rsp);

        bool _Parse_Http_Body(const http_message *_Hm, Http_Rsp *_Rsp);

        void _CallOnError(mg_connection *_Nc, ErrCode _ErrCode, Http_Rsp *_Rsp, http_message *_Hm, void *_Extra);

        void _CallOnResponse(mg_connection *_Nc, Http_Rsp *_Rsp);

        bool _HandleResponse(mg_connection *_Nc, int _Ev, void *_Data);

        void _EvHandlerAsyn(mg_connection *_Nc, int _Ev, void *_Data);

        void _EvHandlerSync(mg_connection *_Nc, int _Ev, void *_Data);

        void *_EvLoop(void *);

        bool StartAsynClient();

        bool StopAsynClient();

        bool SendRequestAsyn(const Http_Req *_Req, Callback _Callback);

        bool SendRequest(const Http_Req *_Req, Callback _Callback);

        bool SendRequestSync(const Http_Req *_Req, Http_Rsp *_Rsp, ErrCode *_ErrCode);
    };
}


#endif //FBS_SERVER_CLIENT_H
