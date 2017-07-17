#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_RESPONSE_STATUS_CODE_TYPE_H_
#define _CRMS_RESOURCE_ENUMERATION_RESPONSE_STATUS_CODE_TYPE_H_

#include "EnumerationBase.h"

struct CRMS_ResponseStatusCodeType : public EnumerationBase {
	CRMS_ResponseStatusCodeType(){}
	CRMS_ResponseStatusCodeType(int val){this->val=val;}
};

#endif//_CRMS_RESOURCE_ENUMERATION_RESPONSE_STATUS_CODE_TYPE_H_