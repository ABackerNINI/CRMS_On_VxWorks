#pragma once

#ifndef _CRMS_JSON_BATCH_NOTIFY_SUPPORT_H_
#define _CRMS_JSON_BATCH_NOTIFY_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_common/CRMS_BatchNotify.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_BatchNotify> {
    static bool is_default(const crms::protocol::resource::common::CRMS_BatchNotify &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::common::CRMS_BatchNotify &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSET(num);
            NJSON_NSET(dur);
        }

        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_BatchNotify *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NGET(num);
            NJSON_NGET(dur);
        }
    }
};

#endif //_CRMS_JSON_BATCH_NOTIFY_SUPPORT_H_
