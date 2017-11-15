#pragma once

#ifndef _CRMS_JSON_COMMAND_SUPPORT_H_
#define _CRMS_JSON_COMMAND_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Command.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Command> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_Command &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_Command &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_HasChildren);

        SET(desc);
        SET(con);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Command *njson_var) {
        DESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_HasChildren);

        GET(desc);
        GET(con);
    }
};

#endif //_CRMS_JSON_COMMAND_SUPPORT_H_