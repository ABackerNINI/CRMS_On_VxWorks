#pragma once

#ifndef _CRMS_RESOURCE_ATTRIBUTE_FILTER_CRITERIA_H_
#define _CRMS_RESOURCE_ATTRIBUTE_FILTER_CRITERIA_H_

#include "../Serialization.h"
#include "../DefMem.h"

#include "../../utility/DateTime/Date.h"

class CRMS_FilterCriteria {
public:
	CRMS_FilterCriteria():
		sts(DEFAULT_VALUE_INT),
		stb(DEFAULT_VALUE_INT),
		sza(DEFAULT_VALUE_INT),
		szb(DEFAULT_VALUE_INT),
		lim(DEFAULT_VALUE_INT){
	}

	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(crb);
				SET(cra);
				SET(ms);
				SET(us);
				SET(sts);
				SET(stb);
				SET(exb);
				SET(exa);
				SET(lbl);
				SET(rty);
				SET(sza);
				SET(szb);
				SET(cty);
				SET(lim);
				SET(fu);
			} else {
				SET_IF_KEY(crb)
				SET_IF_KEY(cra)
				SET_IF_KEY(ms)
				SET_IF_KEY(us)
				SET_IF_KEY(sts)
				SET_IF_KEY(stb)
				SET_IF_KEY(exb)
				SET_IF_KEY(exa)
				SET_IF_KEY(lbl)
				SET_IF_KEY(rty)
				SET_IF_KEY(sza)
				SET_IF_KEY(szb)
				SET_IF_KEY(cty)
				SET_IF_KEY(lim)
				SET_IF_KEY(fu)
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
			GET(crb);
			GET(cra);
			GET(ms);
			GET(us);
			GET(sts);
			GET(stb);
			GET(exb);
			GET(exa);
			GET(lbl);
			GET(rty);
			GET(sza);
			GET(szb);
			GET(cty);
			GET(lim);
			GET(fu);
		}
	}

	~CRMS_FilterCriteria(){
	}

	DEFINE_MEMBER(crb,Date)
	DEFINE_MEMBER(cra,Date)
	DEFINE_MEMBER(ms,Date)
	DEFINE_MEMBER(us,Date)
	DEFINE_MEMBER(sts,int)
	DEFINE_MEMBER(stb,int)
	DEFINE_MEMBER(exb,Date)
	DEFINE_MEMBER(exa,Date)
	DEFINE_MEMBER(lbl,std::list<std::string>)
	DEFINE_MEMBER(rty,std::list<int>)
	DEFINE_MEMBER(sza,int)
	DEFINE_MEMBER(szb,int)
	DEFINE_MEMBER(cty,std::list<std::string>)
	DEFINE_MEMBER(lim,int)
	DEFINE_MEMBER(fu,std::string)
};

#endif//_CRMS_RESOURCE_ATTRIBUTE_FILTER_CRITERIA_H_