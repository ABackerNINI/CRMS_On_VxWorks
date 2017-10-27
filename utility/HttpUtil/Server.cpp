//
// Created by abacker on 11/24/16.
//

#include "Server.h"

#if(DEBUG_SHOW_REQ)

void HttpUtil::server::_Show_Req(const Http_Req &_Req) {

    if (SETTING_SHOW_REQ != REQ_NONE) {
        std::cout << "\033[33m" << "\n***Recv Request:" << "\033[0m" << std::endl;
    }

    if (SETTING_SHOW_REQ & REQ_MTD_AND_URI_AND_QUERYS) {
        std::cout << MtdToString(_Req.Method) << " " << _Req.Uri;

        if (!_Req.Queries.empty()) {
            std::cout << "?";

            std::map<std::string, std::string>::const_iterator _Iter = _Req.Queries.begin();
            std::cout << _Iter->first << "=" << _Iter->second;

            for (++_Iter; _Iter != _Req.Queries.end(); ++_Iter) {
                std::cout << "&" << _Iter->first << "=" << _Iter->second;
            }
        }
        std::cout << std::endl;
    }

    if (SETTING_SHOW_REQ & REQ_HEADERS) {
        std::cout << "Headers:" << std::endl;

        for (std::map<std::string, std::string>::const_iterator _Iter = _Req.Headers.begin();
             _Iter != _Req.Headers.end(); ++_Iter) {
            std::cout << _Iter->first << ":" << _Iter->second << std::endl;

        }
    }

    if (SETTING_SHOW_REQ & REQ_BODY) {
        std::cout << "Body:" << std::endl;

        std::cout << _Req.Body << std::endl;
    }
}

void HttpUtil::server::Show_Req(int SETTING_SHOW_REQ) {
    server::SETTING_SHOW_REQ = SETTING_SHOW_REQ;
}

#endif

#if (DEBUG_SHOW_RSP)

void HttpUtil::server::_Show_Rsp(const Http_Rsp &_Rsp) {
    if (SETTING_SHOW_RSP != RSP_NONE) {
        std::cout << "\033[34m" << "\n***Send Response:" << "\033[0m" << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write("***Send Response:\r\n",WITH_TIME);//log
    }

    if (SETTING_SHOW_RSP & RSP_STATUS_CODE_AND_MSG) {
        std::cout << _Rsp.Status_Code << " " << _Rsp.Status_Msg << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write(Common::to_string(_Rsp.Status_Code)+" "+_Rsp.Status_Msg+"\r\n");//log
    }

    if (SETTING_SHOW_RSP & RSP_HEADERS) {
        std::cout << "Headers:" << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write("Headers:\r\n");//log

        for (std::map<std::string, std::string>::const_iterator _Iter = _Rsp.Headers.begin();
             _Iter != _Rsp.Headers.end(); ++_Iter) {
            std::cout << _Iter->first << ":" << _Iter->second << std::endl;
            //LogFile::LogFileEx::GetInstance()->Write(_Iter->first+":"+_Iter->second+"\r\n");//log
        }
    }

    if (SETTING_SHOW_RSP & RSP_BODY) {
        std::cout << "Body:" << std::endl;
        // LogFile::LogFileEx::GetInstance()->Write("Body:\r\n");//log

        std::cout << _Rsp.Body << std::endl;
        // LogFile::LogFileEx::GetInstance()->Write(_Rsp.Body+"\r\n");
    }
}

void HttpUtil::server::Show_Rsp(int SETTING_SHOW_RSP) {
    server::SETTING_SHOW_RSP = SETTING_SHOW_RSP;
}

#endif

void HttpUtil::server::_CallOnError(ErrCode _ErrCode, http_message *_Hm, mg_connection *_Nc, void *_Extra) {
    if (_Callback._On_Error != NULL) {
        _Callback._On_Error(_ErrCode, _Hm, _Nc, _Extra);
    }
}

void HttpUtil::server::_CallOnRequest(mg_connection *_Nc, Http_Req *_Req) {
    Http_Rsp _Rsp;
    if (_Callback._On_Req != NULL) {
        _Callback._On_Req(_Req, &_Rsp);
        _Replay(_Nc, &_Rsp);
    } else {//default response
        _Rsp.Status_Code = 400;
        _Rsp.Status_Msg = "Bad Request";
        _Replay(_Nc, &_Rsp);
    }

#if(DEBUG_SHOW_RSP)
    if (SETTING_SHOW_RSP)
        _Show_Rsp(_Rsp);
#endif
}

bool HttpUtil::server::_Parse_Http_Method(http_message *_Hm, Http_Req *_Req) {
//    if (!_Strcmp("GET", _Hm->method.p, _Hm->method.len)) {
//        _Req->Method = GET;
//    } else if (!_Strcmp("POST", _Hm->method.p, _Hm->method.len)) {
//        _Req->Method = POST;
//    } else if (!_Strcmp("PUT", _Hm->method.p, _Hm->method.len)) {
//        _Req->Method = PUT;
//    } else if (!_Strcmp("DELETE", _Hm->method.p, _Hm->method.len)) {
//        _Req->Method = DELETE;
//    } else {
//        _CallOnError(ERR_PARSING_METHOD, _Hm, NULL, NULL);
//        _Req->Method = UNDEFINED;
//
//        return false;
//    }
//
//    return true;

    _Req->Method = ToHttpMtd(_Hm->method.p, _Hm->method.len);

    return _Req->Method != UNDEFINED;
}

bool HttpUtil::server::_Parse_Http_Uri(http_message *_Hm, Http_Req *_Req) {
    _Req->Uri = std::string(_Hm->uri.p, _Hm->uri.len);

    return true;
}

bool HttpUtil::server::_Parse_Http_Proto(http_message *_Hm, Http_Req *_Req) {
    _Req->Protocol = std::string(_Hm->proto.p, _Hm->proto.len);

    return true;
}

bool HttpUtil::server::_Parse_Http_Querys(http_message *_Hm, Http_Req *_Req) {
    if (_Hm->query_string.len == 0)return true;

    int _Status = 0;
    size_t _Len = _Hm->query_string.len + 1;
    std::string _First, _Second;

    for (const char *p = _Hm->query_string.p, *q = p; _Len--; ++p) {
        if (*p == '&' || _Len == 0) {
            if (_Status == 1) {
                _Second = std::string(q, p - q);
                _Status = 2;
                q = p + 1;
            } else {
                _CallOnError(ERR_PARSING_QUERYS, _Hm, NULL, NULL);
                return false;
            }
        } else if (*p == '=') {
            if (_Status == 0) {
                _First = std::string(q, p - q);
                _Status = 1;
                q = p + 1;
            } else {
                _CallOnError(ERR_PARSING_QUERYS, _Hm, NULL, NULL);
                return false;
            }
        } else if (*p == '\0') {
            _CallOnError(ERR_PARSING_QUERYS, _Hm, NULL, NULL);
            return false;
        }

        if (_Status == 2) {
            _Req->Queries[_First] = _Second;
            _Status = 0;
            q = p + 1;
        }
    }

    if (_Status == 1) {
        _CallOnError(ERR_PARSING_QUERYS, _Hm, NULL, NULL);
        return false;
    }

    return true;
}

bool HttpUtil::server::_Parse_Http_Headers(http_message *_Hm, Http_Req *_Req) {
    for (int i = 0; i < MG_MAX_HTTP_HEADERS && _Hm->header_names[i].len != 0; ++i) {
        _Req->Headers[std::string(_Hm->header_names[i].p, _Hm->header_names[i].len)] = std::string(
                _Hm->header_values[i].p, _Hm->header_values[i].len);
    }

    return true;
}

bool HttpUtil::server::_Parse_Http_Body(http_message *_Hm, Http_Req *_Req) {
    _Req->Body = std::string(_Hm->body.p, _Hm->body.len);

    return true;
}

void HttpUtil::server::_Replay(mg_connection *_Nc, const Http_Rsp *_Rsp) {
    std::string _Headers;
    _Headers.reserve(200);

    if (_Rsp->Headers.find("Host") == _Rsp->Headers.end())_Headers.append("Host: host\r\n");
    if (_Rsp->Headers.find("Content-Length") == _Rsp->Headers.end()) {
        _Headers.append("Content-Length: ");
        char _Len[11];
        sprintf(_Len, "%ld", _Rsp->Body.length());
        _Headers.append(_Len);
        _Headers.append("\r\n");
    }

    for (std::map<std::string, std::string>::const_iterator _Header = _Rsp->Headers.begin();
         _Header != _Rsp->Headers.end(); ++_Header) {
        _Headers.append(_Header->first);
        _Headers.append(": ");
        _Headers.append(_Header->second);
        _Headers.append("\r\n");
    }

    //DON'T use Transfer-Encoding: chunked
    mg_printf(_Nc, "HTTP/1.1 %d %s\r\n%s\r\n",
              _Rsp->Status_Code,
              _Rsp->Status_Msg.c_str(),
              _Headers.c_str()
    );
    mg_printf(_Nc, "%s", _Rsp->Body.c_str());

    _Nc->flags |= MG_F_SEND_AND_CLOSE;
}

bool HttpUtil::server::_HandleRequest(mg_connection *_Nc, int _Ev, void *_Data) {
    http_message *_Hm = (http_message *) _Data;

    Http_Req _Req;
    {
        if (!(_Parse_Http_Method(_Hm, &_Req) &&
              _Parse_Http_Uri(_Hm, &_Req) &&
              _Parse_Http_Proto(_Hm, &_Req) &&
              _Parse_Http_Querys(_Hm, &_Req) &&
              _Parse_Http_Headers(_Hm, &_Req) &&
              _Parse_Http_Body(_Hm, &_Req))) {
            _CallOnError(ERR_PARSING, _Hm, _Nc, NULL);

            return false;
        }
    }

#if (DEBUG_SHOW_REQ)
    if (SETTING_SHOW_REQ)
        _Show_Req(_Req);
#endif

    _CallOnRequest(_Nc, &_Req);

    return true;
}

void HttpUtil::server::_EvHandler(mg_connection *_Nc, int _Ev, void *_Data) {
    switch (_Ev) {
        case MG_EV_HTTP_REQUEST:
            _HandleRequest(_Nc, _Ev, _Data);
            break;
        default:
            break;
    }
}

void *HttpUtil::server::_EvLoop(void *) {
    while (1) {
        mg_mgr_poll(&_Mgr, 1000);
    }
    return NULL;
}

bool HttpUtil::server::Start(const char *_Port, Callback _Callback) {
    server::_Callback = _Callback;

    mg_mgr_init(&_Mgr, NULL);
    mg_connection *_Nc = mg_bind(&_Mgr, _Port, _EvHandler);

    if (_Nc == NULL) {
        mg_mgr_free(&_Mgr);
        return false;
    }

    mg_set_protocol_http_websocket(_Nc);

    pthread_create(&_EvLoopThread, NULL, _EvLoop, NULL);

    return true;
}

bool HttpUtil::server::Stop() {
    pthread_cancel(_EvLoopThread);
    mg_mgr_free(&_Mgr);

    return true;
}