#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_ENUMERATION_SUPPORT_H_
#define _CRMS_RESOURCE_ENUMERATION_ENUMERATION_SUPPORT_H_

#include "../../utility/nJson/DEF.h"

#include "CRMS_ConsistencyStrategy.h"
#include "CRMS_MemberType.h"
#include "CRMS_NodeExecutionState.h"
#include "CRMS_Operation.h"
#include "CRMS_ResponseStatusCodeType.h"
#include "CRMS_ResultContent.h"
#include "CRMS_SubscriptionOperation.h"

#define SUPPORT_ENUMERATION(ENUM) 																			\
inline bool is_default_value(const ENUM &res){																\
	return false;																							\
}																											\
inline void set_key_value(JSON_Object *obj,const char *key,const ENUM &res){								\
	json_object_set(obj,key,res.get_val());																	\
}																											\
inline void set_key_value(JSON_Array *arr,const ENUM &res){													\
	json_array_append(arr,res.get_val());																	\
}																											\
inline void get_value(JSON_Object *obj,const char *key,ENUM *res){											\
	res->set_val(json_object_get<short>(obj,key));															\
}																											\
inline void get_value(JSON_Array *arr,size_t index,ENUM *res){												\
	res->set_val(json_array_get<short>(arr,index));															\
}

SUPPORT_ENUMERATION(CRMS_ConsistencyStrategy)
SUPPORT_ENUMERATION(CRMS_MemberType)
SUPPORT_ENUMERATION(CRMS_NodeExecutionState)
SUPPORT_ENUMERATION(CRMS_Operation)
SUPPORT_ENUMERATION(CRMS_ResponseStatusCodeType)
SUPPORT_ENUMERATION(CRMS_ResultContent)
SUPPORT_ENUMERATION(CRMS_SubscriptionOperation)

#endif//_CRMS_RESOURCE_ENUMERATION_ENUMERATION_SUPPORT_H_