#pragma once

#ifndef _CRMS_RESOURCE_REQ_H_
#define _CRMS_RESOURCE_REQ_H_

#include "../Serialization.h"
#include "../DefMem.h"

#include "CRMS_PrimitiveContentType.h"
#include "../crms_enumeration/CRMS_Operation.h"
#include "../crms_enumeration/CRMS_ResultContent.h"
#include "../crms_enumeration/CRMS_SubscriptionOperation.h"
#include "../crms_attribute/CRMS_FilterCriteria.h"

class CRMS_Req {
public:
	CRMS_Req():
		ty(DEFAULT_VALUE_INT),
		/*proxy(DEFAULT_VALUE_BOOL)*/{
		memset(&proxy,-1,sizeof(bool));
	}

	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(op);
				SET(to);
				SET(fr);
				SET(rqi);
				SET(ty);
				SET(rn);
				SET(pc);
				SET(ot);
				SET(rqet);
				SET(rset);
				SET(oet);
				SET(rcn);
				SET(da);
				SET(gid);
				SET(fc);
				SET(so);
				SET(proxy);
			} else {
				SET_IF_KEY(op)
				SET_IF_KEY(to)
				SET_IF_KEY(fr)
				SET_IF_KEY(rqi)
				SET_IF_KEY(ty)
				SET_IF_KEY(rn)
				SET_IF_KEY(pc)
				SET_IF_KEY(ot)
				SET_IF_KEY(rqet)
				SET_IF_KEY(rset)
				SET_IF_KEY(oet)
				SET_IF_KEY(rcn)
				SET_IF_KEY(da)
				SET_IF_KEY(gid)
				SET_IF_KEY(fc)
				SET_IF_KEY(so)
				SET_IF_KEY(proxy)
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
			GET(op);
			GET(to);
			GET(fr);
			GET(rqi);
			GET(ty);
			GET(rn);
			GET(pc);
			GET(ot);
			GET(rqet);
			GET(rset);
			GET(oet);
			GET(rcn);
			GET(da);
			GET(gid);
			GET(fc);
			GET(so);
			GET(proxy);
		}
	}

	~CRMS_Req(){
	}

	DEFINE_MEMBER(op,CRMS_Operation)
	DEFINE_MEMBER(to,std::string)
	DEFINE_MEMBER(fr,std::string)
	DEFINE_MEMBER(rqi,std::string)
	DEFINE_MEMBER(ty,int)
	DEFINE_MEMBER(rn,std::string)
	DEFINE_MEMBER(pc,CRMS_PrimitiveContentType)
	DEFINE_MEMBER(ot,Date)
	DEFINE_MEMBER(rqet,Date)
	DEFINE_MEMBER(rset,Date)
	DEFINE_MEMBER(oet,Date)
	DEFINE_MEMBER(rcn,CRMS_ResultContent)
	DEFINE_MEMBER(da,std::string)
	DEFINE_MEMBER(gid,std::string)
	DEFINE_MEMBER(fc,CRMS_FilterCriteria)
	DEFINE_MEMBER(so,CRMS_SubscriptionOperation)
	DEFINE_MEMBER(proxy,bool)

// private:
// 	CRMS_Operation					op;
// 	std::string						to;
// 	std::string						fr;
// 	std::string						rqi;
// 	int								ty;
// 	std::string						rn;
// 	CRMS_PrimitiveContentType 		pc;
// 	Date							ot;
// 	Date							rqet;
// 	Date							rset;
// 	Date							oet;
// 	CRMS_ResultContent				rcn;
// 	std::string						da;
// 	std::string						gid;
// 	CRMS_FilterCriteria				fc;
// 	CRMS_SubscriptionOperation 		so;
// 	bool							proxy;
};

#endif//_CRMS_RESOURCE_REQ_H_