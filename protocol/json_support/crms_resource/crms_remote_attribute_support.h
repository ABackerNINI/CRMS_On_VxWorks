#pragma once

#ifndef _CRMS_JSON_REMOTE_ATTRIBUTE_SUPPORT_H_
#define _CRMS_JSON_REMOTE_ATTRIBUTE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_RemoteAttribute.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_RemoteAttribute> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_RemoteAttribute &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_RemoteAttribute &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Attribute);

        SET(rm);
        SET(rri);
        SET(proxy);
    }

    static void deserialize(JSON_Value *njson_val,
                            crms::protocol::resource::resource::CRMS_RemoteAttribute *njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Attribute);

        GET(rm);
        GET(rri);
        GET(proxy);
    }
};

#endif //_CRMS_JSON_REMOTE_ATTRIBUTE_SUPPORT_H_