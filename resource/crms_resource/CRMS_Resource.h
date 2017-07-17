#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_H_
#define _CRMS_RESOURCE_RESOURCE_H_

#include "../Resource.h"

#include "../Date/Date.h"
#include "../crms_attribute/CRMS_Subscription.h"

class CRMS_Resource {
public:
	CRMS_Resource():
		ty(DEFAULT_VALUE_INT){
	}

	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(ri);
				SET(pa);
				SET(rn);
				SET(ty);
				SET(ct);
				SET(lt);
				SET(onto);
				SET(subs);
			} else {
				SET_IF_KEY(ri)
				SET_IF_KEY(pa)
				SET_IF_KEY(rn)
				SET_IF_KEY(ty)
				SET_IF_KEY(ct)
				SET_IF_KEY(lt)
				SET_IF_KEY(onto)
				SET_IF_KEY(subs)
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
			GET(ri);
			GET(pa);
			GET(rn);
			GET(ty);
			GET(ct);
			GET(lt);
			GET(onto);
			GET(subs);
		}
	}

	std::string &get_ri(){return ri;}
	std::string &get_pa(){return pa;}
	std::string &get_rn(){return rn;}
	int &get_ty(){return ty;}
	Date &get_ct(){return ct;}
	Date &get_lt(){return lt;}
	std::string &get_onto(){return onto;}
	std::map<std::string,CRMS_Subscription> &get_subs(){return subs;}

	void set_ri(const std::string &ri){this->ri = ri;}
	void set_pa(const std::string &pa){this->pa = pa;}
	void set_rn(const std::string &rn){this->rn = rn;}
	void set_ty(int ty){this->ty = ty;}
	void set_ct(const Date &ct){this->ct = ct;}
	void set_lt(const Date &lt){this->lt = lt;}
	void set_onto(const std::string &onto){this->onto = onto;}
	void set_subs(const std::map<std::string,CRMS_Subscription>&subs){this->subs = subs;}

	~CRMS_Resource(){}

private:
	std::string 								ri;
	std::string 								pa;
	std::string 								rn;
	int											ty;
	Date										ct;
	Date										lt;
	std::string 								onto;
	std::map<std::string,CRMS_Subscription> 	subs;
};

#endif//_CRMS_RESOURCE_RESOURCE_H_