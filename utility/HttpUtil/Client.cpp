//
// Created by abacker on 11/26/16.
//

#include "Client.h"

#if(DEBUG_SHOW_REQ)

void HttpUtil::Client::_Show_Req(const Http_Req &_Req) {

    if (SETTING_SHOW_REQ != REQ_NONE) {
        std::cout << "\033[33m" << "\n***Send Request:" << "\033[0m" << std::endl;
    }

    if (SETTING_SHOW_REQ & REQ_MTD_AND_URI_AND_QUERYS) {
        std::cout << MtdToString(_Req.Method) << " " << _Req.Uri;

        if (!_Req.Querys.empty()) {
            std::cout << "?";
            std::map<std::string, std::string>::const_iterator _Iter = _Req.Querys.begin();
            std::cout << _Iter->first << "=" << _Iter->second;
            for (++_Iter; _Iter != _Req.Querys.end(); ++_Iter) {
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

void HttpUtil::Client::Show_Req(int SETTING_SHOW_REQ) {
    Client::SETTING_SHOW_REQ = SETTING_SHOW_REQ;
}

#endif

#if (DEBUG_SHOW_RSP)

void HttpUtil::Client::_Show_Rsp(const Http_Rsp &_Rsp) {
    if (SETTING_SHOW_RSP != RSP_NONE) {
        std::cout << "\033[34m" << "\n***Recv Response:" << "\033[0m" << std::endl;
    }

    if (SETTING_SHOW_RSP & RSP_STATUS_CODE_AND_MSG) {
        std::cout << _Rsp.Status_Code << " " << _Rsp.Status_Msg << std::endl;
    }

    if (SETTING_SHOW_RSP & RSP_HEADERS) {
        std::cout << "Headers:" << std::endl;
        for (std::map<std::string, std::string>::const_iterator _Iter = _Rsp.Headers.begin();
             _Iter != _Rsp.Headers.end(); ++_Iter) {
            std::cout << _Iter->first << ":" << _Iter->second << std::endl;
        }
    }

    if (SETTING_SHOW_RSP & RSP_BODY) {
        std::cout << "Body:" << std::endl;
        std::cout << _Rsp.Body << std::endl;
    }
}

void HttpUtil::Client::Show_Rsp(int SETTING_SHOW_RSP) {
    Client::SETTING_SHOW_RSP = SETTING_SHOW_RSP;
}

#endif

std::string HttpUtil::Client::_ToUrl(const Http_Req *_Req) {
    std::string _Url;
    _Url.reserve(50);
    _Url.append(_Req->Uri);
    if (!_Req->Querys.empty()) {
        _Url.append("?");
        std::map<std::string, std::string>::const_iterator _Iter = _Req->Querys.begin();

        _Url.append(_Iter->first);
        _Url.append("=");
        _Url.append(_Iter->second);

        ++_Iter;

        for (; _Iter != _Req->Querys.end(); ++_Iter) {
            _Url.append("&");
            _Url.append(_Iter->first);
            _Url.append("=");
            _Url.append(_Iter->second);
        }
    }
    return _Url;
}

std::string HttpUtil::Client::_ToHeaders(const Http_Req *_Req) {
    std::string _Headers;
    _Headers.reserve(100);

    if (_Req->Headers.find("Host") == _Req->Headers.end())_Headers.append("Host: host\r\n");
    if (_Req->Headers.find("Content-Length") == _Req->Headers.end()) {
        _Headers.append("Content-Length: ");
        char _Len[10];
        sprintf(_Len, "%ld", _Req->Body.length());
        _Headers.append(_Len);
        _Headers.append("\r\n");
    }

    for (std::map<std::string, std::string>::const_iterator _Iter = _Req->Headers.begin();
         _Iter != _Req->Headers.end(); ++_Iter) {
        _Headers.append(_Iter->first);
        _Headers.append(": ");
        _Headers.append(_Iter->second);
        _Headers.append("\r\n");
    }
    return _Headers;
}

std::string HttpUtil::Client::_ToMethod(const Http_Req *_Req) {
    return MtdToString(_Req->Method);
}


bool HttpUtil::Client::_Parse_Http_StatusCode(const http_message *_Hm, Http_Rsp *_Rsp) {
    _Rsp->Status_Code = _Hm->resp_code;

    return true;
}

bool HttpUtil::Client::_Parse_Http_StatusMsg(const http_message *_Hm, Http_Rsp *_Rsp) {
    _Rsp->Status_Msg = std::string(_Hm->resp_status_msg.p, _Hm->resp_status_msg.len);

    return true;
}

bool HttpUtil::Client::_Parse_Http_Headers(const http_message *_Hm, Http_Rsp *_Rsp) {
    for (int i = 0; i < MG_MAX_HTTP_HEADERS && _Hm->header_names[i].len != 0; ++i) {
        _Rsp->Headers[std::string(_Hm->header_names[i].p, _Hm->header_names[i].len)] = std::string(
                _Hm->header_values[i].p, _Hm->header_values[i].len);
    }

    return true;
}

bool HttpUtil::Client::_Parse_Http_Body(const http_message *_Hm, Http_Rsp *_Rsp) {
    _Rsp->Body = std::string(_Hm->body.p, _Hm->body.len);

    return true;
}

void HttpUtil::Client::_CallOnError(mg_connection *_Nc, ErrCode _ErrCode, Http_Rsp *_Rsp, http_message *_Hm,
                                    void *_Extra) {
    std::map<mg_connection *, Callback>::const_iterator _Iter = _CallbackPool.find(_Nc);
    if (_Iter != _CallbackPool.end())_Iter->second._On_Error(_ErrCode, _Rsp, _Hm, _Extra);
}

void HttpUtil::Client::_CallOnResponse(mg_connection *_Nc, Http_Rsp *_Rsp) {
    std::map<mg_connection *, Callback>::const_iterator _Iter = _CallbackPool.find(_Nc);
    if (_Iter != _CallbackPool.end())_Iter->second._On_Rsp(_Rsp);
}

bool HttpUtil::Client::_HandleResponse(mg_connection *_Nc, int _Ev, void *_Data) {
    http_message *_Hm = (http_message *) _Data;
    _Nc->flags |= MG_F_CLOSE_IMMEDIATELY;

    Http_Rsp _Rsp;
    {
        if (!(_Parse_Http_StatusCode(_Hm, &_Rsp) &&
              _Parse_Http_StatusMsg(_Hm, &_Rsp) &&
              _Parse_Http_Headers(_Hm, &_Rsp) &&
              _Parse_Http_Body(_Hm, &_Rsp))) {
            _CallOnError(_Nc, ERR_PARSING, NULL, _Hm, NULL);

            return false;
        }
    }

#if (DEBUG_SHOW_RSP)
    _Show_Rsp(_Rsp);
#endif

    _CallOnResponse(_Nc, &_Rsp);

    return true;
}

void HttpUtil::Client::_EvHandlerAsyn(mg_connection *_Nc, int _Ev, void *_Data) {
    switch (_Ev) {
        case MG_EV_CONNECT:
            if (*(int *) _Data != 0) {
                _CallOnError(_Nc, ERR_CONNECT, NULL, NULL, NULL);
            }
            break;
        case MG_EV_HTTP_REPLY: {
            if (_Nc->flags ^ MG_F_CLOSE_IMMEDIATELY) {
                _HandleResponse(_Nc, _Ev, _Data);

                _Nc->flags |= MG_F_CLOSE_IMMEDIATELY;
            }
            break;
        }
        case MG_EV_CLOSE:
            _CallbackPool.erase(_Nc);
            break;
        default:
            break;
    }
}

void HttpUtil::Client::_EvHandlerSync(mg_connection *_Nc, int _Ev, void *_Data) {
    switch (_Ev) {
        case MG_EV_CONNECT:
            if (*(int *) _Data != 0) {
                _CallOnError(_Nc, ERR_CONNECT, NULL, NULL, NULL);
            }
            break;
        case MG_EV_HTTP_REPLY: {
            if (_Nc->flags ^ MG_F_CLOSE_IMMEDIATELY) {
                _HandleResponse(_Nc, _Ev, _Data);

                _Nc->flags |= MG_F_CLOSE_IMMEDIATELY;
            }
            break;
        }
        case MG_EV_CLOSE:
            break;
        default:
            break;
    }
}

void *HttpUtil::Client::_EvLoop(void *_Mgr) {
    while (1) {
        mg_mgr_poll((mg_mgr *) _Mgr, 1000);
    }

    return NULL;
}

bool HttpUtil::Client::StartAsynClient() {
    if (!_Mgr) {
        _Mgr = new mg_mgr();
        mg_mgr_init(_Mgr, NULL);

        pthread_create(&_EvLoopThread, NULL, _EvLoop, _Mgr);
    }

    return true;
}

bool HttpUtil::Client::StopAsynClient() {
    if (_Mgr) {
        pthread_cancel(_EvLoopThread);

        mg_mgr_free(_Mgr);
        _Mgr = NULL;
    }

    return true;
}

bool HttpUtil::Client::SendRequestAsyn(const Http_Req *_Req, Callback _Callback) {
#if(DEBUG_SHOW_REQ)
    _Show_Req(*_Req);
#endif

    mg_connect_opts opts;
    memset(&opts, 0, sizeof(opts));

    char *_Addr = NULL;
    const char *_Path = NULL;

    std::string _Url = _ToUrl(_Req);
    mg_connection *_Nc = mg_connect_http_base(_Mgr, _EvHandlerAsyn, opts, "http://", "https://", _Url.c_str(), &_Path,
                                              &_Addr);

    free(_Addr);

    if (_Nc == NULL) {
        return false;
    }

    _CallbackPool[_Nc] = _Callback;

    mg_printf(_Nc, "%s %s HTTP/1.1\r\n%s\r\n%s",
              _ToMethod(_Req).c_str(), _Path,
              _ToHeaders(_Req).c_str(),
              _Req->Body.c_str());

    mg_set_protocol_http_websocket(_Nc);

    return true;
}

bool HttpUtil::Client::SendRequest(const Http_Req *_Req, Callback _Callback) {
    return SendRequestAsyn(_Req, _Callback);
}

bool HttpUtil::Client::SendRequestSync(const Http_Req *_Req, Http_Rsp *_Rsp, ErrCode *_ErrCode) {
#if(DEBUG_SHOW_REQ)
    _Show_Req(*_Req);
#endif
    return true;
}