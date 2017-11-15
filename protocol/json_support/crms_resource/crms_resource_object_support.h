#pragma once

#ifndef _CRMS_JSON_RESOURCE_OBJECT_SUPPORT_H_
#define _CRMS_JSON_RESOURCE_OBJECT_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_ResourceObject.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_ResourceObject> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_ResourceObject &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_ResourceObject &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_HasChildren);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_ResourceObject *njson_var) {
        DESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_HasChildren);
    }
};

#endif //_CRMS_JSON_RESOURCE_OBJECT_SUPPORT_H_