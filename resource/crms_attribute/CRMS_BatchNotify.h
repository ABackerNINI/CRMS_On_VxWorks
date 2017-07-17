#pragma once

#ifndef _CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_
#define _CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_

#include "../Resource.h"

class CRMS_BatchNotify {
public:
	CRMS_BatchNotify(){
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

	~CRMS_BatchNotify(){
	}

private:
	int foo;
};

#endif//_CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_