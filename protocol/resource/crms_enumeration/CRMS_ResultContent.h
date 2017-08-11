#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_
#define _CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_

#include "EnumerationBase.h"

struct CRMS_ResultContent : public EnumerationBase {
	CRMS_ResultContent(){}
	CRMS_ResultContent(int val){this->val=val;}

	static const _SHORT Nothing 					= 1;
	static const _SHORT Attributes 					= 2;
	static const _SHORT childResources 				= 3;
	static const _SHORT attribute_childResources 	= 4;
	static const _SHORT originalResources 			= 5;
};

#endif//_CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_