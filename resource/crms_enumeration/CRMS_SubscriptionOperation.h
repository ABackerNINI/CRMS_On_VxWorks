#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_
#define _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_

#include "EnumerationBase.h"

struct CRMS_SubscriptionOperation : public EnumerationBase {
	CRMS_SubscriptionOperation(){}
	CRMS_SubscriptionOperation(int val){this->val=val;}

	static const short Create = 1;
	static const short Update = 2;
	static const short Delete = 3;
};

#endif//_CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_