#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_NODE_EXECUTION_STATE_H_
#define _CRMS_RESOURCE_ENUMERATION_NODE_EXECUTION_STATE_H_

#include "EnumerationBase.h"

struct CRMS_NodeExecutionState : public EnumerationBase {
	CRMS_NodeExecutionState(){}
	CRMS_NodeExecutionState(int val){this->val=val;}

	static const short RUN 		= 1;
	static const short PAUSE 	= 2;
	static const short RESTART 	= 3;
};

#endif//_CRMS_RESOURCE_ENUMERATION_NODE_EXECUTION_STATE_H_