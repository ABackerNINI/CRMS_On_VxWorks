#pragma once

#ifndef _CRMS_JSON_SUPPORT_BASE_H_
#define _CRMS_JSON_SUPPORT_BASE_H_

#include "../../utility/nJson/nJson.h"

#define SET(M) _NJSON_SET(njson_val,#M,njson_var.get_##M())
#define GET(M) _NJSON_GET(njson_val,#M,&(njson_var->get_##M()))
#define SERIALIZE_SUPER_CLASS(S) _NJSON_SERIALIZE_SUPER_CLASS((S *)&njson_var,njson_val)

#endif //_CRMS_JSON_SUPPORT_BASE_H_
