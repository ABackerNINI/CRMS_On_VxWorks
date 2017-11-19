#pragma once

#ifndef _CRMS_JSON_CHILD_RESOURCE_REF_SUPPORT_H_
#define _CRMS_JSON_CHILD_RESOURCE_REF_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_common/CRMS_ChildResourceRef.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_ChildResourceRef> {
    static bool is_default(const crms::protocol::resource::common::CRMS_ChildResourceRef &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::common::CRMS_ChildResourceRef &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSET(v);
            NJSON_NSET(ty);
            NJSON_NSET(rn);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_ChildResourceRef *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NGET(v);
            NJSON_NGET(ty);
            NJSON_NGET(rn);
        }
    }
};

#endif //_CRMS_JSON_CHILD_RESOURCE_REF_SUPPORT_H_