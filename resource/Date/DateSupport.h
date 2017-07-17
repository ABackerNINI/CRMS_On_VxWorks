#pragma once

#ifndef _CRMS_RESOURCE_DATE_SUPPORT_H_
#define _CRMS_RESOURCE_DATE_SUPPORT_H_

#include "Date.h"

inline bool is_default_value(const Date &res){
	return false;
}

inline void set_key_value(JSON_Object *obj,const char *key,const Date &res){
	json_object_set(obj,key,"");//TODO
}
inline void set_key_value(JSON_Array *arr,const Date &res){
	json_array_append(arr,"");//TODO
}

inline void get_value(JSON_Object *obj,const char *key,Date *res){
	//TODO
}
inline void get_value(JSON_Array *arr,size_t index,Date *res){
	//TODO
}

#endif//_CRMS_RESOURCE_DATE_SUPPORT_H_