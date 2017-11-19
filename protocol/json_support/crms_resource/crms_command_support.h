#pragma once

#ifndef _CRMS_JSON_COMMAND_SUPPORT_H_
#define _CRMS_JSON_COMMAND_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_Command.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_Command> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_Command &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::resource::CRMS_Command &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_HasChildren);

            NJSON_NSET(desc);
            NJSON_NSET(con);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_Command *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_HasChildren);

            NJSON_NGET(desc);
            NJSON_NGET(con);
        }
    }
};

#endif //_CRMS_JSON_COMMAND_SUPPORT_H_