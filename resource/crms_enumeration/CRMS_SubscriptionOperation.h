#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_
#define _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_

#include "EnumerationBase.h"

struct CRMS_SubscriptionOperation : public EnumerationBase {
	CRMS_SubscriptionOperation(){}
	CRMS_SubscriptionOperation(int val){this->val=val;}
};

#endif//_CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_