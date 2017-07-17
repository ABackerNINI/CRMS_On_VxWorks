#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_OPERATION_H_
#define _CRMS_RESOURCE_ENUMERATION_OPERATION_H_

#include "EnumerationBase.h"

struct CRMS_Operation : public EnumerationBase {
	CRMS_Operation(){}
	CRMS_Operation(int val){this->val=val;}
};

#endif//_CRMS_RESOURCE_ENUMERATION_OPERATION_H_