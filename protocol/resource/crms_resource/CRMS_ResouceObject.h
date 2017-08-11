#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_OBJECT_H_
#define _CRMS_RESOURCE_RESOURCE_OBJECT_H_

#include "../DEF.h"

#include "CRMS_Resource.h"
#include "CRMS_ChildResourceRef.h"

class CRMS_ResourceObject : public CRMS_Resource {
public:
	CRMS_ResourceObject(){
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

	~CRMS_ResourceObject(){
	}

	DEFINE_MEMBER(children,_LIST<CRMS_ChildResourceRef>)
};

#endif//_CRMS_RESOURCE_RESOURCE_OBJECT_H_