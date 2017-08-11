#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_MEMBER_TYPE_H_
#define _CRMS_RESOURCE_ENUMERATION_MEMBER_TYPE_H_

#include "EnumerationBase.h"

struct CRMS_MemberType : public EnumerationBase {
public:
	CRMS_MemberType(){}
	CRMS_MemberType(int val){this->val=val;}

	static const _SHORT rootResource 			= 1;
	static const _SHORT resourceObject  		= 2;
	static const _SHORT attribute	  			= 3;
	static const _SHORT command	  				= 4;
	static const _SHORT node	  				= 5;
	static const _SHORT group	  				= 6;
	static const _SHORT remoteResourceObject	= 7;
	static const _SHORT remoteAttribute	  		= 8;
	static const _SHORT remoteCommand	  		= 9;
};

#endif//_CRMS_RESOURCE_ENUMERATION_MEMBER_TYPE_H_