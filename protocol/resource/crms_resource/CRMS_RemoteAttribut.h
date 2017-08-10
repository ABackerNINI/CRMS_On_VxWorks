#pragma once

#ifndef _CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_
#define _CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_

#include "../DEF.h"

#include "CRMS_Attribute.h"

class CRMS_RemoteAttribute : public CRMS_Attribute {
public:
	CRMS_RemoteAttribute() :
		rm(DEFAULT_VALUE_INT){
			memset(proxy,-1,sizeof(bool));
	}

	bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
		SERIALIZE_SUPER_CLASS(CRMS_Attribute);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if (_key_ == NULL) {
				SET(rm);
				SET(rri);
				SET(proxy);
			}
			else {
				SET_IF_KEY(rm)
				SET_IF_KEY(rri)
				SET_IF_KEY(proxy)
				{
					return false;
				}
			}
		}

		return true;
	}
	void deserialize(JSON_Value *_doc_) {
		DESERIALIZE_SUPER_CLASS(CRMS_Attribute);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			GET(rm);
			GET(rri);
			GET(proxy);
		}
	}

	~CRMS_RemoteAttribute() {
	}

	DEFINE_MEMBER(rm, int)
	DEFINE_MEMBER(rri, std::string)
	DEFINE_MEMBER(proxy, bool)
};

#endif//_CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_