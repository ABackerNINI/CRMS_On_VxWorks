#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_
#define _CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_

#include "../../utility/nJson/DEF.h"

#define GETTER(M) 				\
template<typename _T>			\
const _T &get_##M() const {		\
	return M;					\
}


struct EnumerationBase {
public:
	EnumerationBase():
		val(DEFAULT_VALUE_SHORT){
		}
	EnumerationBase(int val){
		this->val=(short)val;
	}

	short &get_val() {return val;}
	const short &get_val() const {return val;}
	//GETTER(val)
	void set_val(short val){this->val=val;}

protected:
	short val;
};

#endif//_CRMS_RESOURCE_ENUMERATION_ENUMERATION_BASE_H_