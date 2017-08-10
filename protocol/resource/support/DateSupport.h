#pragma once

#ifndef _CRMS_RESOURCE_DATE_SUPPORT_H_
#define _CRMS_RESOURCE_DATE_SUPPORT_H_

#include "../../../utility/DateTime/Date.h"

inline bool is_default_value(const Date &res){
	return res.isUninitialized();
}

inline void njson_set_value(JSON_Object *obj,const char *key,const Date &res){
	json_object_set(obj,key,res.to_string().c_str());
}
inline void njson_set_value(JSON_Array *arr,const Date &res){
	json_array_append(arr,res.to_string().c_str());
}

inline void njson_get_value(JSON_Object *obj,const char *key,Date *res){
	if(json_object_has_value(obj,key)){
		const char *s;
		s = json_object_get<const char *>(obj,key);
		*res = Date(s);
	}
}
inline void njson_get_value(JSON_Array *arr,size_t index,Date *res){
	const char *s;
	s = json_array_get<const char *>(arr,index);
	*res = Date(s);
}

#endif//_CRMS_RESOURCE_DATE_SUPPORT_H_