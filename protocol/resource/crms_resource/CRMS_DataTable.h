#pragma once

#ifndef _CRMS_RESOURCE_DATA_TABLE_H_
#define _CRMS_RESOURCE_DATA_TABLE_H_

#include "../DEF.h"

#include "CRMS_Resource.h"

class CRMS_DataTable : public CRMS_Resource {
public:
	CRMS_DataTable() :
		count(DEFAULT_VALUE_INT){
	}

	bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
		SERIALIZE_SUPER_CLASS(CRMS_Resource);

		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if (_key_ == NULL) {
				SET(desc);
				SET(columns);
				SET(con);
				SET(count);
			}
			else {
				SET_IF_KEY(desc)
				SET_IF_KEY(columns)
				SET_IF_KEY(con)
				SET_IF_KEY(count)
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
			GET(columns);
			GET(con);
			GET(count);
		}
	}

	~CRMS_DataTable() {
	}

	DEFINE_MEMBER(desc, _STRING)
	DEFINE_MEMBER(columns, _LIST<_STRING>)
	DEFINE_MEMBER(con, _LIST<_MAP<_STRING,_STRING>)//std::list<std::map<_STRING,Object>
	DEFINE_MEMBER(count, _INT)
};

#endif//_CRMS_RESOURCE_DATA_TABLE_H_