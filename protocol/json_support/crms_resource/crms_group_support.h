#pragma once

#ifndef _CRMS_JSON_GROUP_SUPPORT_H_
#define _CRMS_JSON_GROUP_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Group.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Group> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_Group &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::resource::CRMS_Group &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NSET(mt);
            NJSON_NSET(cnm);
            NJSON_NSET(mnm);
            NJSON_NSET(mid);
            NJSON_NSET(mtv);
            NJSON_NSET(csy);
            NJSON_NSET(gn);
            NJSON_NSET(cr);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Group *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NGET(mt);
            NJSON_NGET(cnm);
            NJSON_NGET(mnm);
            NJSON_NGET(mid);
            NJSON_NGET(mtv);
            NJSON_NGET(csy);
            NJSON_NGET(gn);
            NJSON_NGET(cr);
        }
    }
};

#endif //_CRMS_JSON_GROUP_SUPPORT_H_