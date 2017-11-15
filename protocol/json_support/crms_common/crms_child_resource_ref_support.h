#pragma once

#ifndef _CRMS_JSON_CHILD_RESOURCE_REF_SUPPORT_H_
#define _CRMS_JSON_CHILD_RESOURCE_REF_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_common/CRMS_ChildResourceRef.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_ChildResourceRef> {
    static bool is_default_value(const crms::protocol::resource::common::CRMS_ChildResourceRef &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::common::CRMS_ChildResourceRef &njson_var) {
        SET(v);
        SET(ty);
        SET(rn);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_ChildResourceRef *njson_var) {
        GET(v);
        GET(ty);
        GET(rn);
    }
};

#endif //_CRMS_JSON_CHILD_RESOURCE_REF_SUPPORT_H_