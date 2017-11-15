#pragma once

#ifndef _CRMS_JSON_HAS_CHILDREN_SUPPORT_H_
#define _CRMS_JSON_HAS_CHILDREN_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_HasChildren.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_HasChildren> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_HasChildren &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_HasChildren &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        SET(ch);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_HasChildren *njson_var) {
        DESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        GET(ch);
    }
};

#endif //_CRMS_JSON_HAS_CHILDREN_SUPPORT_H_