#pragma once

#ifndef _CRMS_RESOURCE_HANDLER_HANDLER_BASE_H_
#define _CRMS_RESOURCE_HANDLER_HANDLER_BASE_H_

#include "../resource/crms_resource/CRMS_Req.h"
#include "../resource/crms_resource/CRMS_Rsp.h"

class HandlerBase {
public:
	virtual void Create(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) = 0;
	virtual void Retrieve(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) = 0;
	virtual void Update(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) = 0;
	virtual void Delete(CRMS_Req *_Req,CRMS_Rsp *_Rsp,CRMS_Resource *_Res) = 0;
};

#endif//_CRMS_RESOURCE_HANDLER_HANDLER_BASE_H_