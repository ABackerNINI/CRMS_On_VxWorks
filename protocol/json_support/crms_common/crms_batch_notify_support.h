#pragma once

#ifndef _CRMS_JSON_BATCH_NOTIFY_SUPPORT_H_
#define _CRMS_JSON_BATCH_NOTIFY_SUPPORT_H_

#include "../support_base.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_BatchNotify> {
    static bool is_default_value(const crms::protocol::resource::common::CRMS_BatchNotify &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::common::CRMS_BatchNotify &njson_var) {
        SET(num);
        SET(dur);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_BatchNotify *njson_var) {
        GET(num);
        GET(dur);
    }
};

#endif //_CRMS_JSON_BATCH_NOTIFY_SUPPORT_H_
