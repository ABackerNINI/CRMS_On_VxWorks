#pragma once

#ifndef _CRMS_JSON_RESOURCE_SUPPORT_H_
#define _CRMS_JSON_RESOURCE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Resource> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_Resource &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::resource::CRMS_Resource &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSET(ri);
            NJSON_NSET(pa);
            NJSON_NSET(rn);
            NJSON_NSET(ty);
            NJSON_NSET(ct);
            NJSON_NSET(lt);
            NJSON_NSET(onto);
            NJSON_NSET(subs);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Resource *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NGET(lt);
            NJSON_NGET(onto);
            NJSON_NGET(subs);
        }
    }
};

#endif //_CRMS_JSON_RESOURCE_SUPPORT_H_
