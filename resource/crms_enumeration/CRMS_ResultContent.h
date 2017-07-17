#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_
#define _CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_

#include "EnumerationBase.h"

struct CRMS_ResultContent : public EnumerationBase {
	CRMS_ResultContent(){}
	CRMS_ResultContent(int val){this->val=val;}
};

#endif//_CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_