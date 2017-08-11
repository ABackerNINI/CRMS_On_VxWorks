#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_CONSISTENCY_STRATEGY_H_
#define _CRMS_RESOURCE_ENUMERATION_CONSISTENCY_STRATEGY_H_

#include "EnumerationBase.h"

struct CRMS_ConsistencyStrategy : public EnumerationBase {
public:
	CRMS_ConsistencyStrategy(){}
	CRMS_ConsistencyStrategy(int val){this->val=val;}

	static const _SHORT ABANDON_MEMBER 	= 1;
	static const _SHORT ABANDON_GROUP  	= 2;
	static const _SHORT MODIFY_TYPE	  	= 3;
};

#endif//_CRMS_RESOURCE_ENUMERATION_CONSISTENCY_STRATEGY_H_