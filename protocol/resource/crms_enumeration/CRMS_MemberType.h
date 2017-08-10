#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_MEMBER_TYPE_H_
#define _CRMS_RESOURCE_ENUMERATION_MEMBER_TYPE_H_

#include "EnumerationBase.h"

struct CRMS_MemberType : public EnumerationBase {
public:
	CRMS_MemberType(){}
	CRMS_MemberType(int val){this->val=val;}

	static const short rootResource 			= 1;
	static const short resourceObject  			= 2;
	static const short attribute	  			= 3;
	static const short command	  				= 4;
	static const short node	  					= 5;
	static const short group	  				= 6;
	static const short remoteResourceObject		= 7;
	static const short remoteAttribute	  		= 8;
	static const short remoteCommand	  		= 9;
};

#endif//_CRMS_RESOURCE_ENUMERATION_MEMBER_TYPE_H_