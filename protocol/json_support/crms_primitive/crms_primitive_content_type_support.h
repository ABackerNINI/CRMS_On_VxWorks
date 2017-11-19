#pragma once

#ifndef _CRMS_JSON_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_
#define _CRMS_JSON_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_primitive/CRMS_PrimitiveContentType.h"

template<typename T>
struct njson_support<crms::protocol::resource::primitive::CRMS_PrimitiveContentType<T> > {
    static bool is_default(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<T> &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<T> &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSET(ty);
            NJSON_NSET(val);
        }
        NJSON_RET;
    }

    static void
    deserialize(JSON_Value *njson_val, crms::protocol::resource::primitive::CRMS_PrimitiveContentType<T> *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NGET(ty);
            NJSON_NGET(val);
        }
    }
};

#endif //_CRMS_JSON_PRIMITIVE_CONTENT_TYPE_SUPPORT_H_
