//
// Created by nini on 10/26/17.
//

#ifndef _CRMS_PROTOCOL_RESOURCE_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_
#define _CRMS_PROTOCOL_RESOURCE_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_


#include "../../resource/crms_primitive/CRMS_PrimitiveContentType.h"

char *serialize_pc(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc);

int deserialize_pc(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, int ty, const char *cstr);

#endif //_CRMS_PROTOCOL_RESOURCE_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_
