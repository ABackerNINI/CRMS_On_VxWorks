#pragma once

#ifndef _CRMS_RESOURCE_REMOTE_RESOURCE_OBJECT_H_
#define _CRMS_RESOURCE_REMOTE_RESOURCE_OBJECT_H_

#include "../DEF.h"

#include "CRMS_ResouceObject.h"

class CRMS_RemoteResouceObject : public CRMS_ResouceObject {
public:
	CRMS_RemoteResouceObject() :
		rm(DEFAULT_VALUE_INT){
			memset(alive,-1,sizeof(bool));
			memset(proxy,-1,sizeof(bool));
	}

	bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
		SERIALIZE_SUPER_CLASS(CRMS_ResouceObject);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if (_key_ == NULL) {
				SET(rm);
				SET(rri);
				SET(alive);
				SET(proxy);
			}
			else {
				SET_IF_KEY(rm)
				SET_IF_KEY(rri)
				SET_IF_KEY(alive)
				SET_IF_KEY(proxy)
				{
					return false;
				}
			}
		}

		return true;
	}
	void deserialize(JSON_Value *_doc_) {
		DESERIALIZE_SUPER_CLASS(CRMS_ResouceObject);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			GET(rm);
			GET(rri);
			GET(alive);
			GET(proxy);
		}
	}

	~CRMS_RemoteResouceObject() {
	}

	DEFINE_MEMBER(rm, _INT)
	DEFINE_MEMBER(rri, _STRING)
	DEFINE_MEMBER(alive, _BOOL)
	DEFINE_MEMBER(proxy, _BOOL)
};

#endif//_CRMS_RESOURCE_REMOTE_RESOURCE_OBJECT_H_