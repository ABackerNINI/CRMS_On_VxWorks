#pragma once

#ifndef _CRMS_PROTOCOL_KEYWORD_H_
#define _CRMS_PROTOCOL_KEYWORD_H_

//KW:Key Word
//KV:Key Value

#define KV_CRMS_ROOT_RESOURCE_RN "crms_on_vxworks_root_resource"
#define KV_CRMS_ROOT_RESOURCE_RI "/root"

#define KW_HEADERS_HOST "Host"
#define KV_HEADERS_HOST "crms_on_vxworks"
#define KW_HEADERS_X_CRMS_RI "x-crms-ri"
#define KW_HEADERS_X_CRMS_RSC "x-crms-rsc"

#define KW_QUERY_Q "q"
#define KV_QUERY_Q_PR "pr"
#define KV_QUERY_Q_PG "pg"
#define KV_QUERY_Q_SR "sr"
#define KW_QUERY_Q_PR_IN "in"
#define KW_QUERY_Q_PR_EX "ex"
#define KW_QUERY_Q_PG_OFFSET "offset"
#define KW_QUERY_Q_PG_LEN "len"
#define KW_QUERY_Q_SR_ID "id"

#define KW_TYPE_SHORT "ty"
#define KW_RESOURCE_NAME_SHORT "rn"

#define KV_DELETE_RESPOND_FORMAT_STRING "{\n    \"ty\": %d,\n    \"val\": \"Success\"\n}"

#define KV_STATUS_MESSAGE_BAD_REQUEST "Bad Request"
#define KV_STATUS_MESSAGE_OK "OK"

#endif //_CRMS_PROTOCOL_KEYWORD_H_
