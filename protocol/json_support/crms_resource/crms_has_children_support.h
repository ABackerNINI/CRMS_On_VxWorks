#pragma once

#ifndef _CRMS_JSON_HAS_CHILDREN_SUPPORT_H_
#define _CRMS_JSON_HAS_CHILDREN_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_HasChildren.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_HasChildren> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_HasChildren &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::resource::CRMS_HasChildren &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NSET(ch);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_HasChildren *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NGET(ch);
        }

    }
};

#endif //_CRMS_JSON_HAS_CHILDREN_SUPPORT_H_