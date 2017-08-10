#pragma once

#ifndef _CRMS_RESOURCE_NODE_H_
#define _CRMS_RESOURCE_NODE_H_

#include "../DEF.h"

#include "CRMS_Resource.h"
#include "../crms_enumeration/CRMS_NodeExecutionState.h"

class CRMS_Node : public CRMS_Resource {
public:
	CRMS_Node() {
	}

	bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
		SERIALIZE_SUPER_CLASS(CRMS_Resource);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if (_key_ == NULL) {
				SET(desc);
				SET(params);
				SET(nno);
				SET(re);
				SET(st);
			}
			else {
				SET_IF_KEY(desc)
				SET_IF_KEY(params)
				SET_IF_KEY(nno)
				SET_IF_KEY(re)
				SET_IF_KEY(st)
				{
					return false;
				}
			}
		}

		return true;
	}
	void deserialize(JSON_Value *_doc_) {
		DESERIALIZE_SUPER_CLASS(CRMS_Resource);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			GET(desc);
			GET(params);
			GET(nno);
			GET(re);
			GET(st);
		}
	}

	~CRMS_Node() {
	}

	DEFINE_MEMBER(desc, std::string)
	DEFINE_MEMBER(params, std::string)//Object
	DEFINE_MEMBER(nno, std::string)
	DEFINE_MEMBER(re, std::string)//Object
	DEFINE_MEMBER(st, CRMS_NodeExecutionState)
};

#endif//_CRMS_RESOURCE_NODE_H_