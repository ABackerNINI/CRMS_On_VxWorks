#pragma once

#ifndef _CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_
#define _CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_

#include "../Serialization.h"
#include "../DefMem.h"

#include "../../utility/DateTime/Duration.h"

class CRMS_BatchNotify {
public:
	CRMS_BatchNotify():
		num(DEFAULT_VALUE_INT){
	}

	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(num);
				SET(dur);
			} else {
				SET_IF_KEY(num)
				SET_IF_KEY(dur)
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
			GET(num);
			GET(dur);
		}
	}

	~CRMS_BatchNotify(){
	}

	DEFINE_MEMBER(num,int)
	DEFINE_MEMBER(dur,Duration)
};

#endif//_CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_