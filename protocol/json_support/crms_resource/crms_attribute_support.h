#pragma once

#ifndef _CRMS_JSON_ATTRIBUTE_SUPPORT_H_
#define _CRMS_JSON_ATTRIBUTE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Attribute.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Attribute> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_Attribute &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::resource::CRMS_Attribute &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NSET(nm);
            NJSON_NSET(ro);
            NJSON_NSET(data);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Attribute *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NGET(nm);
            NJSON_NGET(ro);
            NJSON_NGET(data);
        }
    }
};

#endif //_CRMS_JSON_ATTRIBUTE_SUPPORT_H_
