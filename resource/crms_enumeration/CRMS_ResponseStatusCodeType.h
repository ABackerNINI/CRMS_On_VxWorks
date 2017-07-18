#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_RESPONSE_STATUS_CODE_TYPE_H_
#define _CRMS_RESOURCE_ENUMERATION_RESPONSE_STATUS_CODE_TYPE_H_

#include "EnumerationBase.h"

struct CRMS_ResponseStatusCodeType : public EnumerationBase {
	CRMS_ResponseStatusCodeType(){}
	CRMS_ResponseStatusCodeType(int val){this->val=val;}

	static const short Success 									= 1;
	static const short Accepted 								= 2;
	static const short Unsupported_resource 					= 3;
	static const short Unsupported_attribute 					= 4;
	static const short Create_error_no_privilege 				= 5;
	static const short Create_error_already_exists 				= 6;
	static const short Create_error_missing_mandatory_parameter = 7;
	static const short Retrieve_error_no_privilege 				= 7;
	static const short Retrieve_error_does_not_exist 			= 8;
	static const short Update_error_no_privilege 				= 9;
	static const short Update_error_does_not_exist 				= 10;
	static const short Update_error_unacceptable_contents 		= 11;
	static const short Delete_error_does_not_exist 				= 12;
	static const short Delete_error_no_privilege 				= 13;
};

#endif//_CRMS_RESOURCE_ENUMERATION_RESPONSE_STATUS_CODE_TYPE_H_