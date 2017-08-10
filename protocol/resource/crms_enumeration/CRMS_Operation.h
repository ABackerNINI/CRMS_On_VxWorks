#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_OPERATION_H_
#define _CRMS_RESOURCE_ENUMERATION_OPERATION_H_

#include "EnumerationBase.h"

struct CRMS_Operation : public EnumerationBase {
	CRMS_Operation(){}
	CRMS_Operation(int val){this->val=val;}

	static const short Create 			= 1;
	static const short Retrieve 		= 2;
	static const short Update 			= 3;
	static const short Delete 			= 4;
	static const short Notify 			= 5;
	static const short ForwardNotify 	= 6;
};

#endif//_CRMS_RESOURCE_ENUMERATION_OPERATION_H_