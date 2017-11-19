#pragma once

#ifndef _CRMS_JSON_ENUMERATION_SUPPORT_H_
#define _CRMS_JSON_ENUMERATION_SUPPORT_H_

#include "../../../utility/nJson/DEF.h"

#include "../../resource/crms_enumeration/CRMS_ConsistencyStrategy.h"
#include "../../resource/crms_enumeration/CRMS_MemberType.h"
#include "../../resource/crms_enumeration/CRMS_NodeExecutionState.h"
#include "../../resource/crms_enumeration/CRMS_Operation.h"
#include "../../resource/crms_enumeration/CRMS_PartialRetrieveType.h"
#include "../../resource/crms_enumeration/CRMS_ResponseStatusCodeType.h"
#include "../../resource/crms_enumeration/CRMS_ResultContent.h"
#include "../../resource/crms_enumeration/CRMS_SubscriptionOperation.h"
#include "../../resource/crms_enumeration/CRMS_NotificationContentType.h"
#include "../../resource/crms_enumeration/CRMS_ResourceStatus.h"
#include "../../resource/crms_enumeration/CRMS_ResourceType.h"
#include "../../resource/crms_enumeration/CRMS_SubscriptionEventType.h"
#include "../../resource/crms_enumeration/CRMS_RetrieveQueryType.h"

#define SUPPORT_ENUMERATION(ENUM)\
template<>\
struct njson_support<ENUM> {\
    static bool is_default(const ENUM &njson_var) {\
        return njson_var.get_val() == NJSON_DEFAULT_VALUE_SHORT;\
    }\
\
    static JSON_Value *serialize(const ENUM &njson_var) {\
        return njson_support_serialize(njson_var.get_val());\
    }\
\
    static void deserialize(JSON_Value *njson_val, ENUM *njson_var) {\
       njson_support_deserialize(njson_val,&njson_var->get_val());\
    }\
};

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_ConsistencyStrategy)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_MemberType)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_NodeExecutionState)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_NotificationContentType)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_Operation)

//SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_PartialRetrieveType)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_ResourceStatus)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_ResourceType)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_ResultContent)

//SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_RetrieveQueryType)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_SubscriptionEventType)

SUPPORT_ENUMERATION(crms::protocol::resource::enumeration::CRMS_SubscriptionOperation)

#endif//_CRMS_JSON_ENUMERATION_SUPPORT_H_