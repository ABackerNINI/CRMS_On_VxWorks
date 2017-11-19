#pragma once

#ifndef _CRMS_JSON_DATE_SUPPORT_H_
#define _CRMS_JSON_DATE_SUPPORT_H_

#include "../../utility/nJson/DEF.h"
#include "../../utility/TimeUtil/DateTime.h"

template<>
struct njson_support<DateTime> {
    static bool is_default(const DateTime &njson_var) {
        return njson_var.isUninitialized();
    }

    static JSON_Value *serialize(const DateTime &njson_var) {
        return njson_support_serialize(njson_var.to_string().c_str());
    }

    static void deserialize(JSON_Value *njson_val, DateTime *njson_var) {
        const char *s;
        njson_support_deserialize(njson_val, &s);
        *njson_var = DateTime(s);
    }
};

#endif//_CRMS_JSON_DATE_SUPPORT_H_