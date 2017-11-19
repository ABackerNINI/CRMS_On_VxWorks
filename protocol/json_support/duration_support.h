#pragma once

#ifndef _CRMS_JSON_DURATION_SUPPORT_H_
#define _CRMS_JSON_DURATION_SUPPORT_H_

#include "../../utility/nJson/DEF.h"
#include "../../utility/TimeUtil/Duration.h"

template<>
struct njson_support<Duration> {
    static bool is_default(const Duration &njson_var) {
        return true;
    }

    static JSON_Value *serialize(const Duration &njson_var) {
        //TODO
        return NULL;
    }

    static void deserialize(JSON_Value *njson_val, Duration *njson_var) {
        //TODO
    }
};

#endif//_CRMS_JSON_DURATION_SUPPORT_H_