#pragma once

#ifndef _CRMS_RESOURCE_DURATION_SUPPORT_H_
#define _CRMS_RESOURCE_DURATION_SUPPORT_H_

#include "../../../utility/DateTime/Duration.h"

inline bool is_default_value(const Duration &res) {
    return true;
}

inline void njson_set_value(JSON_Object *obj, const char *key, const Duration &res) {
    json_object_set(obj, key, "");//TODO
}

inline void njson_set_value(JSON_Array *arr, const Duration &res) {
    json_array_append(arr, "");//TODO
}

inline void njson_get_value(JSON_Object *obj, const char *key, Duration *res) {
    if (json_object_has_value(obj, key)) {
        //TODO
    }
}

inline void njson_get_value(JSON_Array *arr, size_t index, Duration *res) {
    //TODO
}

#endif//_CRMS_RESOURCE_DURATION_SUPPORT_H_