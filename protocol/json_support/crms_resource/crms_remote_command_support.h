#pragma once

#ifndef _CRMS_JSON_REMOTE_COMMAND_SUPPORT_H_
#define _CRMS_JSON_REMOTE_COMMAND_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_RemoteCommand.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_RemoteCommand> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_RemoteCommand &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::resource::CRMS_RemoteCommand &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Command);

            NJSON_NSET(rm);
            NJSON_NSET(rri);
            NJSON_NSET(proxy);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_RemoteCommand *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Command);

            NJSON_NGET(rm);
            NJSON_NGET(rri);
            NJSON_NGET(proxy);
        }
    }
};

#endif //_CRMS_JSON_REMOTE_COMMAND_SUPPORT_H_