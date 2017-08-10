#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_
#define _CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_

#include "../../../utility/nJson/DEF.h"
#include "../DefMem.h"

struct EnumerationBase {
public:
	EnumerationBase():
		val(DEFAULT_VALUE_SHORT){
		}
	EnumerationBase(int val){
		this->val=(short)val;
	}

	_DEFINE_MEMBER(protected,val,short)

// 	short &get_val() {return val;}
// 	const short &get_val() const {return val;}
// 	//GETTER(val)
// 	void set_val(short val){this->val=val;}

// protected:
// 	short val;
};

#endif//_CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_