#pragma once

#ifndef _CRMS_JSON_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_
#define _CRMS_JSON_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_

#include "../../resource/crms_primitive/CRMS_PrimitiveContentType.h"

char *serialize_pc(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc);

int deserialize_pc(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, int ty, const char *cstr);

#endif //_CRMS_JSON_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_
