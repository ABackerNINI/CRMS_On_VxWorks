//
// Created by nini on 11/15/17.
//

#ifndef _CRMS_RESOURCE_BATCH_NOTIFY_SUPPORT_H_
#define _CRMS_RESOURCE_BATCH_NOTIFY_SUPPORT_H_

#include "../SupportBase.h"

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

#endif //_CRMS_RESOURCE_BATCH_NOTIFY_SUPPORT_H_
