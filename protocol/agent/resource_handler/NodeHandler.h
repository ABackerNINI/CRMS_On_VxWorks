#pragma once

#ifndef _CRMS_RESOURCE_HANDLER_NODE_HANDLER_H_
#define _CRMS_RESOURCE_HANDLER_NODE_HANDLER_H_

#include "HandlerBase.h"

class NodeHandler : public HandlerBase {
public:
	void Create(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) override {
		CreateResource(_Req,_Rsp,_Res);
	}

	void Retrieve(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) override {

	}

	void Update(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) override {

	}

	void Delete(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) override {

	}
};

#endif//_CRMS_RESOURCE_HANDLER_NODE_HANDLER_H_