//
// Created by nini on 11/15/17.
//

#ifndef _CRMS_RESOURCE_RESOURCE_SUPPORT_H_
#define _CRMS_RESOURCE_RESOURCE_SUPPORT_H_


#include "../SupportBase.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Resource> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_Resource &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_Resource &njson_var) {
        SET(ri);
        SET(pa);
        SET(rn);
        SET(ty);
        SET(ct);
        SET(lt);
        SET(onto);
        SET(subs);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Resource *njson_var) {
//                            GET(ri);
//                            GET(pa);
//                            GET(rn);////mark:read only?
//                            GET(ty);
//                            GET(ct);
        GET(lt);
        GET(onto);
        GET(subs);
    }
};


#endif //_CRMS_RESOURCE_RESOURCE_SUPPORT_H_
