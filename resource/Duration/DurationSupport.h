#pragma once

#ifndef _CRMS_RESOURCE_DURATION_SUPPORT_H_
#define _CRMS_RESOURCE_DURATION_SUPPORT_H_

#include "Duration.h"

inline bool is_default_value(const Duration &res){
	return false;
}

inline void set_key_value(JSON_Object *obj,const char *key,const Duration &res){
	json_object_set(obj,key,"");//TODO
}
inline void set_key_value(JSON_Array *arr,const Duration &res){
	json_array_append(arr,"");//TODO
}

inline void get_value(JSON_Object *obj,const char *key,Duration *res){
	//TODO
}
inline void get_value(JSON_Array *arr,size_t index,Duration *res){
	//TODO
}

#endif//_CRMS_RESOURCE_DURATION_SUPPORT_H_