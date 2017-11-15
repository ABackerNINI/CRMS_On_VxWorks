#pragma once

#ifndef _CRMS_JSON_ATTRIBUTE_SUPPORT_H_
#define _CRMS_JSON_ATTRIBUTE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Attribute.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Attribute> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_Attribute &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_Attribute &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        SET(nm);
        SET(ro);
        SET(data);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Attribute *njson_var) {
        DESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        GET(nm);
        GET(ro);
        GET(data);
    }
};

#endif //_CRMS_JSON_ATTRIBUTE_SUPPORT_H_
