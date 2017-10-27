//
// Created by abacker on 11/26/16.
//

#include "Client.h"

#if(DEBUG_SHOW_REQ)

void HttpUtil::Client::_Show_Req(const Http_Req &_Req) {

    if (SETTING_SHOW_REQ != REQ_NONE) {
        std::cout << "\033[33m" << "\n***Send Request:" << "\033[0m" << std::endl;
       // LogFile::LogFileEx::GetInstance()->Write("***Send Request:\r\n",WITH_TIME);//log
    }

    if (SETTING_SHOW_REQ & REQ_MTD_AND_URI_AND_QUERYS) {
        std::cout << MtdToString(_Req.Method) << " " << _Req.Uri;
       // LogFile::LogFileEx::GetInstance()->Write(std::string(MtdToString(_Req.Method))+" "+ _Req.Uri);//log

        if (!_Req.Queries.empty()) {
            std::cout << "?";
         //   LogFile::LogFileEx::GetInstance()->Write("?");//log

            auto _Iter = _Req.Queries.begin();
            std::cout << _Iter->first << "=" << _Iter->second;
           // LogFile::LogFileEx::GetInstance()->Write(_Iter->first+"="+_Iter->second);//log

            for (++_Iter; _Iter != _Req.Queries.end(); ++_Iter) {
                std::cout << "&" << _Iter->first << "=" << _Iter->second;
           //     LogFile::LogFileEx::GetInstance()->Write("&"+_Iter->first+"="+_Iter->second);//log
            }
        }
        std::cout << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write("\r\n");//log
    }

    if (SETTING_SHOW_REQ & REQ_HEADERS) {
        std::cout << "Headers:" << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write("Headers:\r\n");//log

        for (auto _Iter = _Req.Headers.begin(); _Iter != _Req.Headers.end(); ++_Iter) {
            std::cout << _Iter->first << ":" << _Iter->second << std::endl;
         //   LogFile::LogFileEx::GetInstance()->Write(_Iter->first+":"+_Iter->second+"\r\n");//log
        }
    }

    if (SETTING_SHOW_REQ & REQ_BODY) {
        std::cout << "Body:" << std::endl;
       // LogFile::LogFileEx::GetInstance()->Write("Body:\r\n");

        std::cout << _Req.Body << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write(_Req.Body+"\r\n");
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
       // LogFile::LogFileEx::GetInstance()->Write("***Recv Response:\r\n");//log
    }

    if (SETTING_SHOW_RSP & RSP_STATUS_CODE_AND_MSG) {
        std::cout << _Rsp.Status_Code << " " << _Rsp.Status_Msg << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write(Common::to_string(_Rsp.Status_Code)+" "+_Rsp.Status_Msg+"\r\n");//log
    }

    if (SETTING_SHOW_RSP & RSP_HEADERS) {
        std::cout << "Headers:" << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write("Headers:\r\n");//log

        for (auto _Iter = _Rsp.Headers.begin(); _Iter != _Rsp.Headers.end(); ++_Iter) {
            std::cout << _Iter->first << ":" << _Iter->second << std::endl;
            //LogFile::LogFileEx::GetInstance()->Write(_Iter->first+":"+_Iter->second+"\r\n");//log
        }
    }

    if (SETTING_SHOW_RSP & RSP_BODY) {
        std::cout << "Body:" << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write("Body:\r\n");

        std::cout << _Rsp.Body << std::endl;
        //LogFile::LogFileEx::GetInstance()->Write(_Rsp.Body+"\r\n");
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
    if (!_Req->Queries.empty()) {
        _Url.append("?");
        auto _Iter = _Req->Queries.begin();

        _Url.append(_Iter->first);
        _Url.append("=");
        _Url.append(_Iter->second);

        ++_Iter;

        for (; _Iter != _Req->Queries.end(); ++_Iter) {
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
        char _Len[11];
        sprintf(_Len, "%ld", _Req->Body.length());
        _Headers.append(_Len);
        _Headers.append("\r\n");
    }

    for (auto _Iter = _Req->Headers.begin(); _Iter != _Req->Headers.end(); ++_Iter) {
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
    auto _Iter = _CallbackPool.find(_Nc);
    if (_Iter != _CallbackPool.end() && _Iter->second._On_Error != NULL)
        _Iter->second._On_Error(_ErrCode, _Rsp, _Hm, _Extra);
}

void HttpUtil::Client::_CallOnResponse(mg_connection *_Nc, Http_Rsp *_Rsp) {
    auto _Iter = _CallbackPool.find(_Nc);
    if (_Iter != _CallbackPool.end() && _Iter->second._On_Rsp != NULL)_Iter->second._On_Rsp(_Rsp);
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

void *HttpUtil::Client::_EvLoop(void *_Mgr) {
    while (1) {
        mg_mgr_poll((mg_mgr *) _Mgr, 1000);
    }

    return NULL;
}

int HttpUtil::Client::mg_http_common_url_parse(const char *url, const char *schema,
                                               const char *schema_tls, int *use_ssl,
                                               char **addr, int *port_i,
                                               const char **path) {
    int addr_len = 0;

    if (memcmp(url, schema, strlen(schema)) == 0) {
        url += strlen(schema);
    } else if (memcmp(url, schema_tls, strlen(schema_tls)) == 0) {
        url += strlen(schema_tls);
        *use_ssl = 1;
#ifndef MG_ENABLE_SSL
        return -1; /* SSL is not enabled, cannot do HTTPS URLs */
#endif
    }

    while (*url != '\0') {
        *addr = (char *) realloc(*addr, addr_len + 5 /* space for port too. */);
        if (*addr == NULL) {
            DBG(("OOM"));
            return -1;
        }
        if (*url == '/') {
            break;
        }
        if (*url == ':') *port_i = addr_len;
        (*addr)[addr_len++] = *url;
        (*addr)[addr_len] = '\0';
        url++;
    }
    if (addr_len == 0) goto cleanup;
    if (*port_i < 0) {
        *port_i = addr_len;
        strcpy(*addr + *port_i, *use_ssl ? ":443" : ":80");
    } else {
        *port_i = -1;
    }

    if (*path == NULL) *path = url;

    if (**path == '\0') *path = "/";

    DBG(("%s %s", *addr, *path));

    return 0;

    cleanup:
    free(*addr);
    return -1;
}

int HttpUtil::Client::mg_parse_address(const char *str, sockaddr_in *sa,
                                       int *proto, char *host, size_t host_len) {
    unsigned int a, b, c, d, port = 0;
    int ch, len = 0;
#ifdef MG_ENABLE_IPV6
    char buf[100];
#endif

    /*
     * MacOS needs that. If we do not zero it, subsequent bind() will fail.
     * Also, all-zeroes in the socket address means binding to all addresses
     * for both IPv4 and IPv6 (INADDR_ANY and IN6ADDR_ANY_INIT).
     */
    memset(sa, 0, sizeof(*sa));
    sa->sin_family = AF_INET;

    *proto = SOCK_STREAM;

    if (strncmp(str, "udp://", 6) == 0) {
        str += 6;
        *proto = SOCK_DGRAM;
    } else if (strncmp(str, "tcp://", 6) == 0) {
        str += 6;
    }

    if (sscanf(str, "%u.%u.%u.%u:%u%n", &a, &b, &c, &d, &port, &len) == 5) {
        /* Bind to a specific IPv4 address, e.g. 192.168.1.5:8080 */
        sa->sin_addr.s_addr =
                htonl(((uint32_t) a << 24) | ((uint32_t) b << 16) | c << 8 | d);
        sa->sin_port = htons((uint16_t) port);
#ifdef MG_ENABLE_IPV6
        } else if (sscanf(str, "[%99[^]]]:%u%n", buf, &port, &len) == 2 &&
             inet_pton(AF_INET6, buf, &sa->sin6.sin6_addr)) {
    /* IPv6 address, e.g. [3ffe:2a00:100:7031::1]:8080 */
    sa->sin6.sin6_family = AF_INET6;
    sa->sin.sin_port = htons((uint16_t) port);
#endif
#ifndef MG_DISABLE_RESOLVER
    } else if (strlen(str) < host_len &&
               sscanf(str, "%[^ :]:%u%n", host, &port, &len) == 2) {
        sa->sin_port = htons((uint16_t) port);
//        ////mark
//        if (mg_resolve_from_hosts_file(host, sa) != 0) {
//            return 0;
//        }
#endif
    } else if (sscanf(str, ":%u%n", &port, &len) == 1 ||
               sscanf(str, "%u%n", &port, &len) == 1) {
        /* If only port is specified, bind to IPv4, INADDR_ANY */
        sa->sin_port = htons((uint16_t) port);
    } else {
        return -1;
    }

    ch = str[len]; /* Character that follows the address */
    return port < 0xffffUL && (ch == '\0' || ch == ',' || isspace(ch)) ? len : -1;
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
    auto _Nc = mg_connect_http_base(_Mgr, _EvHandlerAsyn, opts, "http://", "https://", _Url.c_str(), &_Path, &_Addr);

    if (_Nc == NULL) {
        return false;
    }

    free(_Addr);

    _CallbackPool[_Nc] = _Callback;

    mg_printf(_Nc, "%s %s HTTP/1.1\r\n%s\r\n%s",
              _ToMethod(_Req).c_str(), _Path,
              _ToHeaders(_Req).c_str(),
              _Req->Body.c_str());

    return true;
}

int HttpUtil::Client::_Sync_InitialSock(char *_Addr, struct sockaddr_in *_SrvAddr) {
    int _Sockfd;
    char _Host[200];
    int _Proto;

    mg_parse_address(_Addr, _SrvAddr, &_Proto, _Host, sizeof(_Host));

    _Sockfd = socket(_SrvAddr->sin_family, _Proto, 0);

    if (_Sockfd == -1)return -1;

    timeval timeout = {20, 0};

    setsockopt(_Sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char *) &timeout, sizeof(timeout));
    setsockopt(_Sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &timeout, sizeof(timeout));

    return _Sockfd;
}

int HttpUtil::Client::_Sync_Connect(int _Sockfd, struct sockaddr_in *_SrvAddr) {
    return connect(_Sockfd, (struct sockaddr *) _SrvAddr, sizeof(struct sockaddr));//-1
}

char *HttpUtil::Client::_ToHttpStr(const HttpUtil::Http_Req *_Req, const char *_Path, unsigned int &_SendLen) {
    std::string _Method = _ToMethod(_Req);
    std::string _Headers = _ToHeaders(_Req);

    char *_SendStr;
    _SendLen = _Method.length() + _Headers.length() + _Req->Body.length() + strlen(_Path) + 15;

    _SendStr = (char *) malloc(_SendLen);

    sprintf(_SendStr, "%s %s HTTP/1.1\r\n%s\r\n%s",
            _Method.c_str(), _Path,
            _Headers.c_str(),
            _Req->Body.c_str());

    return _SendStr;
}

int HttpUtil::Client::_Sync_Send(int _Sockfd, const char *_SendStr, unsigned int _Len) {
    return send(_Sockfd, _SendStr, _Len, 0);//<0
}

char *HttpUtil::Client::_Sync_GetRecvStr(int _Sockfd, unsigned int *_RecvLen) {
    ssize_t _Ret;
    unsigned int _BufLeft = 5120, _Add = 128;
    char *_Buf = (char *) malloc(_BufLeft);

    *_RecvLen = 0;

    while (_Ret = recv(_Sockfd, _Buf + *_RecvLen, _BufLeft, 0), _Ret > 0) {
        *_RecvLen += _Ret;
        _BufLeft -= _Ret;

        if (_BufLeft < 64) {
            if (_Buf = (char *) realloc(_Buf, *_RecvLen + _Add), _Buf == NULL) {////mark
                return NULL;
            }
            _BufLeft = _Add;
            _Add += 128;
        }
    }

    if (_Ret < 0) {
        free(_Buf);

        return NULL;
    }

    _Buf[*_RecvLen] = '\0';

    return _Buf;
}

bool HttpUtil::Client::SendRequestSync(const Http_Req *_Req, Http_Rsp *_Rsp, ErrCode *_ErrCode) {
    int _Sockfd;
    struct sockaddr_in _SrvAddr;

    int _Ssl = 0;
    int _Port;

    char *_Addr = NULL;
    const char *_Path = NULL;

    char *_SendStr;
    unsigned int _SendLen;

    char *_Buf;
    unsigned int _RecvLen;

    http_message _Hm;

    std::string _Url = _ToUrl(_Req);
    if (mg_http_common_url_parse(_Url.c_str(), "http://", "https://", &_Ssl, &_Addr, &_Port, &_Path) == -1)
        return false;

    if ((_Sockfd = _Sync_InitialSock(_Addr, &_SrvAddr)) == -1) {
        *_ErrCode = ERR_CONNECT;

        goto clean3;
    }

    if (_Sync_Connect(_Sockfd, &_SrvAddr) == -1) {
        *_ErrCode = ERR_CONNECT;

        goto clean2;
    }

    _SendStr = _ToHttpStr(_Req, _Path, _SendLen);

    if (_Sync_Send(_Sockfd, _SendStr, _SendLen) < 0) {
        *_ErrCode = ERR_CONNECT;

        goto clean1;
    }

    if ((_Buf = _Sync_GetRecvStr(_Sockfd, &_RecvLen)) == NULL) {
        *_ErrCode = ERR_CONNECT;

        goto clean2;
    }

    close(_Sockfd);

    if (_Rsp != NULL && mg_parse_http(_Buf, _RecvLen, &_Hm, 0) > 0) {
        if (!(_Parse_Http_StatusCode(&_Hm, _Rsp) &&
              _Parse_Http_StatusMsg(&_Hm, _Rsp) &&
              _Parse_Http_Headers(&_Hm, _Rsp) &&
              _Parse_Http_Body(&_Hm, _Rsp))) {
            *_ErrCode = ERR_PARSING;

            goto clean0;
        }
    }

    *_ErrCode = OK;

#if(DEBUG_SHOW_REQ)
    _Show_Req(*_Req);
#endif

    free(_Buf);

#if(DEBUG_SHOW_RSP)
    _Show_Rsp(*_Rsp);
#endif

    return true;

    clean0:

    free(_Buf);

    clean1:

    free(_SendStr);

    clean2:

    close(_Sockfd);

    clean3:

    free(_Addr);

    return false;
}
