//
// Created by nini on 11/15/17.
//

#ifndef _CRMS_RESOURCE_SUBSCRIPTION_SUPPORT_H_
#define _CRMS_RESOURCE_SUBSCRIPTION_SUPPORT_H_

#include "../SupportBase.h"
#include "../../resource/crms_common/CRMS_Subscription.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_Subscription> {
    static bool is_default_value(const crms::protocol::resource::common::CRMS_Subscription &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::common::CRMS_Subscription &njson_var) {
        SET(ri);
        SET(id);
        SET(ct);
        SET(ety);
        SET(exc);
        SET(nu);
        SET(nfu);
        SET(gi);
        SET(bn);
        SET(ln);
        SET(nct);
        SET(cr);
        SET(su);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_Subscription *njson_var) {
        GET(ri);
        GET(id);
        GET(ct);
        GET(ety);
        GET(exc);
        GET(nu);
        GET(nfu);
        GET(gi);
        GET(bn);
        GET(ln);
        GET(nct);
        GET(cr);
        GET(su);
    }
};

#endif //_CRMS_RESOURCE_SUBSCRIPTION_SUPPORT_H_
