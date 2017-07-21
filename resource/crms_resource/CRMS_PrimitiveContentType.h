#pragma once

#ifndef _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_
#define _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_

#include "../Serialization.h"

class CRMS_PrimitiveContentType {
public:
	CRMS_PrimitiveContentType():
		foo(DEFAULT_VALUE_INT){
	}

	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(foo);
			} else {
				SET_IF_KEY(foo)
				{
					return false;
				}
			}
		}

		return true;
	}
	void deserialize(JSON_Value *_doc_){
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			GET(foo);
		}
	}

	~CRMS_PrimitiveContentType(){
	}

private:
	int foo;
};

#endif//_CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_