#pragma once

#ifndef _RESOURCES_INNER_RES_H_
#define _RESOURCES_INNER_RES_H_

#include <string.h>

#include "../utility/nJson/json.h"

#define SET(M) _SET(root_obj,M)
#define GET(M) _GET(root_obj,M)

struct InnerRes{
public:
	InnerRes():
		type(DEFAULT_VALUE_INT){
		}

	// bool isUninitialized() const {
	// 	return type==DEFAULT_VALUE_INT && key==DEFAULT_VALUE_CSTR && val == DEFAULT_VALUE_CSTR;
	// }

	JSON_Value *serialize() const {
		JSON_Value *doc = json_value_init_object();
		{
			JSON_Object *root_obj = json_value_get_object(doc);
			{
				SET(type);
				SET(key);
				SET(val);
			}
		}
		
		return doc;
	}
	void deserialize(JSON_Value *doc){
		JSON_Object *root_obj = json_value_get_object(doc);
		{
			GET(type);
			GET(key);
			GET(val);
		}
	}

	int &get_type(){return type;}
	std::string &get_key(){return key;}
	std::string &get_val(){return val;}

	void set_type(int type){this->type = type;}
	void set_key(const std::string &key){this->key = key;}
	void set_val(const std::string &val){this->val = val;}

	~InnerRes(){
	}

private:
	int 												type;
	std::string 										key;
	std::string											val;
};

#endif//_RESOURCES_INNER_RES_H_