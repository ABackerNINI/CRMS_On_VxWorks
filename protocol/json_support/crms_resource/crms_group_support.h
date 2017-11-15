#pragma once

#ifndef _CRMS_JSON_GROUP_SUPPORT_H_
#define _CRMS_JSON_GROUP_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Group.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Group> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_Group &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_Group &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        SET(mt);
        SET(cnm);
        SET(mnm);
        SET(mid);
        SET(mtv);
        SET(csy);
        SET(gn);
        SET(cr);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Group *njson_var) {
        DESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        GET(mt);
        GET(cnm);
        GET(mnm);
        GET(mid);
        GET(mtv);
        GET(csy);
        GET(gn);
        GET(cr);
    }
};

#endif //_CRMS_JSON_GROUP_SUPPORT_H_