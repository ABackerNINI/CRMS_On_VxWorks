#pragma once

#ifndef _CRMS_JSON_SUBSCRIPTION_SUPPORT_H_
#define _CRMS_JSON_SUBSCRIPTION_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_common/CRMS_Subscription.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_Subscription> {
    static bool is_default(const crms::protocol::resource::common::CRMS_Subscription &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::common::CRMS_Subscription &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSET(ri);
            NJSON_NSET(id);
            NJSON_NSET(ct);
            NJSON_NSET(ety);
            NJSON_NSET(exc);
            NJSON_NSET(nu);
            NJSON_NSET(nfu);
            NJSON_NSET(gi);
            NJSON_NSET(bn);
            NJSON_NSET(ln);
            NJSON_NSET(nct);
            NJSON_NSET(cr);
            NJSON_NSET(su);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_Subscription *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NGET(ri);
            NJSON_NGET(id);
            NJSON_NGET(ct);
            NJSON_NGET(ety);
            NJSON_NGET(exc);
            NJSON_NGET(nu);
            NJSON_NGET(nfu);
            NJSON_NGET(gi);
            NJSON_NGET(bn);
            NJSON_NGET(ln);
            NJSON_NGET(nct);
            NJSON_NGET(cr);
            NJSON_NGET(su);
        }
    }
};

#endif //_CRMS_JSON_SUBSCRIPTION_SUPPORT_H_
