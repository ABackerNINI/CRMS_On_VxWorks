//
// Created by abacker on 11/26/16.
//

#ifndef FBS_SERVER_COMMON_H
#define FBS_SERVER_COMMON_H

#include <iostream>
#include <map>
#include <string.h>

namespace HttpUtil {

    enum Http_Mtd {
        GET,
        POST,
        PUT,
        DELETE,
        UNDEFINED
    };

    struct Http_Req {
        Http_Mtd Method;
        std::string Uri;
        std::string Protocol;
        std::map<std::string, std::string> Queries;
        std::map<std::string, std::string> Headers;
        std::string Body;
    };

    struct Http_Rsp {
        int Status_Code;
        std::string Status_Msg;
        std::map<std::string, std::string> Headers;
        std::string Body;
    };

    inline bool _Strcmp(const char *_Str1, const char *_Str2, size_t _Count) {
        while (_Count--) {
            if (*(_Str1++) != *(_Str2++))
                return true;
        }
        return false;
    }

    inline const char *MtdToString(Http_Mtd _Mtd) {
        static const char *_Mtds[] = {"GET", "POST", "PUT", "DELETE", "UNDEFINED"};

        return _Mtds[_Mtd];
    }

    inline Http_Mtd ToHttpMtd(const char *_Mtd) {
        if (!strcmp(_Mtd, "GET")) {
            return GET;
        } else if (!strcmp(_Mtd, "POST")) {
            return POST;
        } else if (!strcmp(_Mtd, "PUT")) {
            return PUT;
        } else if (!strcmp(_Mtd, "DELETE")) {
            return DELETE;
        } else {
            return UNDEFINED;
        }
    }

    inline Http_Mtd ToHttpMtd(const char *_Mtd, size_t _Count) {
        if (!_Strcmp("GET", _Mtd, _Count)) {
            return GET;
        } else if (!_Strcmp("POST", _Mtd, _Count)) {
            return POST;
        } else if (!_Strcmp("PUT", _Mtd, _Count)) {
            return PUT;
        } else if (!_Strcmp("DELETE", _Mtd, _Count)) {
            return DELETE;
        } else {
            return UNDEFINED;
        }
    }
}

#endif //FBS_SERVER_COMMON_H
