#pragma once

#ifndef _CRMS_RESOURCE_COMMAND_H_
#define _CRMS_RESOURCE_COMMAND_H_

#include "../Serialization.h"
#include "../DefMem.h"

#include "CRMS_Resource.h"
#include "CRMS_ChildResourceRef.h"

class CRMS_Command : public CRMS_Resource {
public:
	CRMS_Command(){
	}

	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		SERIALIZE_SUPER_CLASS(CRMS_Resource);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(desc);
				SET(con);
				SET(children);
			} else {
				SET_IF_KEY(desc)
				SET_IF_KEY(con)
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
			GET(desc);
			GET(con);
			GET(children);
		}
	}

	~CRMS_Command(){
	}

	DEFINE_MEMBER(desc,std::string)
	DEFINE_MEMBER(con,std::string)
	DEFINE_MEMBER(children,std::list<CRMS_ChildResourceRef>)
};

#endif//_CRMS_RESOURCE_COMMAND_H_