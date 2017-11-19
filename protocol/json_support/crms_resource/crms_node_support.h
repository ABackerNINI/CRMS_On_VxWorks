#pragma once

#ifndef _CRMS_JSON_NODE_SUPPORT_H_
#define _CRMS_JSON_NODE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Node.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Node> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_Node &njson_var) {
        return false;
    }

    static JSON_Value * serialize(const crms::protocol::resource::resource::CRMS_Node &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NSET(desc);
            NJSON_NSET(params);
            NJSON_NSET(nno);
            NJSON_NSET(re);
            NJSON_NSET(st);
        }
      NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Node *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NGET(desc);
            NJSON_NGET(params);
            NJSON_NGET(nno);
            NJSON_NGET(re);
            NJSON_NGET(st);
        }
    }
};

#endif //_CRMS_JSON_NODE_SUPPORT_H_