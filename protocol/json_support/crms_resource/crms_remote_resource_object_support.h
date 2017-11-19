#pragma once

#ifndef _CRMS_JSON_REMOTE_RESOURCE_OBJECT_SUPPORT_H_
#define _CRMS_JSON_REMOTE_RESOURCE_OBJECT_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_RemoteResourceObject.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_RemoteResourceObject> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_Resource &njson_var) {
        return false;
    }

    static JSON_Value * serialize(const crms::protocol::resource::resource::CRMS_RemoteResourceObject &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_ResourceObject);

            NJSON_NSET(rm);
            NJSON_NSET(rri);
            NJSON_NSET(alive);
            NJSON_NSET(proxy);
        }
      NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val,
                            crms::protocol::resource::resource::CRMS_RemoteResourceObject *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_ResourceObject);

            NJSON_NGET(rm);
            NJSON_NGET(rri);
            NJSON_NGET(alive);
            NJSON_NGET(proxy);
        }
    }
};

#endif //_CRMS_JSON_REMOTE_RESOURCE_OBJECT_SUPPORT_H_