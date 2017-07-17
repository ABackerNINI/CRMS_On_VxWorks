#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_NODE_EXECUTION_STATE_H_
#define _CRMS_RESOURCE_ENUMERATION_NODE_EXECUTION_STATE_H_

#include "EnumerationBase.h"

struct CRMS_NodeExecutionState : public EnumerationBase {
	CRMS_NodeExecutionState(){}
	CRMS_NodeExecutionState(int val){this->val=val;}
};

#endif//_CRMS_RESOURCE_ENUMERATION_NODE_EXECUTION_STATE_H_