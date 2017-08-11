#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_
#define _CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_

#include "../../../utility/nJson/DEF.h"
#include "../DefMem.h"
#include "../Type.h"

struct EnumerationBase {
public:
	EnumerationBase():
		val(DEFAULT_VALUE_SHORT){
		}
	EnumerationBase(int val){
		this->val=(_SHORT)val;
	}

	_DEFINE_MEMBER(protected,val,_SHORT)
};

#endif//_CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_