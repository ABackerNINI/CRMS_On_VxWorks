#pragma once

#ifndef _CRMS_RESOURCE_ROOT_RESOURCE_H_
#define _CRMS_RESOURCE_ROOT_RESOURCE_H_

#include "../DEF.h"

#include "CRMS_Resource.h"
#include "CRMS_ChildResourceRef.h"

class CRMS_RootResource : public CRMS_Resource {
public:
	CRMS_RootResource(){
	}

	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		SERIALIZE_SUPER_CLASS(CRMS_Resource);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(children);
			} else {
				SET_IF_KEY(children)
				{
					return false;
				}
			}
		}

		return true;
	}
	void deserialize(JSON_Value *_doc_){
		DESERIALIZE_SUPER_CLASS(CRMS_Resource);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			GET(children);
		}
	}

	~CRMS_RootResource(){
	}

	DEFINE_MEMBER(children,CRMS_ChildResourceRef)
};

#endif//_CRMS_RESOURCE_ROOT_RESOURCE_H_