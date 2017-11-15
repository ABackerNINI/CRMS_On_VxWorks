#pragma once

#ifndef _CRMS_RESOURCE_DATE_SUPPORT_H_
#define _CRMS_RESOURCE_DATE_SUPPORT_H_

#include "../../utility/nJson/DEF.h"
#include "../../utility/TimeUtil/DateTime.h"

template<>
struct njson_support<DateTime> {
    static bool is_default_value(const DateTime &njson_var) {
        return njson_var.isUninitialized();
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name, const DateTime &njson_var) {
        njson_serialize(njson_val, njson_name, njson_var.to_string().c_str());
    }

    static void deserialize(JSON_Value *njson_val, DateTime *njson_var) {
        const char *s;
        njson_deserialize(njson_val, &s);
        *njson_var = DateTime(s);
    }
};

#endif//_CRMS_RESOURCE_DATE_SUPPORT_H_