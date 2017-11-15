#pragma once

#ifndef _CRMS_JSON_NODE_SUPPORT_H_
#define _CRMS_JSON_NODE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Node.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Node> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_Node &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_Node &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        SET(desc);
        SET(params);
        SET(nno);
        SET(re);
        SET(st);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Node *njson_var) {
        DESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        GET(desc);
        GET(params);
        GET(nno);
        GET(re);
        GET(st);
    }
};

#endif //_CRMS_JSON_NODE_SUPPORT_H_