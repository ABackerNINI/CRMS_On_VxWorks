#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_
#define _CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_

#include "EnumerationBase.h"

struct CRMS_ResultContent : public EnumerationBase {
	CRMS_ResultContent(){}
	CRMS_ResultContent(int val){this->val=val;}

	static const short Nothing 					= 1;
	static const short Attributes 				= 2;
	static const short childResources 			= 3;
	static const short attribute_childResources = 4;
	static const short originalResources 		= 5;
};

#endif//_CRMS_RESOURCE_ENUMERATION_RESULT_CONTENT_H_