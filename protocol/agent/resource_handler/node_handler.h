#pragma once

#ifndef _CRMS_RESOURCE_HANDLER_NODE_HANDLER_H_
#define _CRMS_RESOURCE_HANDLER_NODE_HANDLER_H_


#include "../../resource/crms_resource/CRMS_Req.h"
#include "../../resource/crms_resource/CRMS_Rsp.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace agent {

            namespace resource_handler {

                class node_handler {
                public:
                    static void Create(resource::resource::CRMS_Req *_Req, resource::resource::CRMS_Rsp *_Rsp,
                                       resource::resource::CRMS_Resource *_Res);

                    static void Retrieve(resource::resource::CRMS_Req *_Req, resource::resource::CRMS_Rsp *_Rsp,
                                         resource::resource::CRMS_Resource *_Res);

                    static void Update(resource::resource::CRMS_Req *_Req, resource::resource::CRMS_Rsp *_Rsp,
                                       resource::resource::CRMS_Resource *_Res);

                    static void Delete(resource::resource::CRMS_Req *_Req, resource::resource::CRMS_Rsp *_Rsp,
                                       resource::resource::CRMS_Resource *_Res);
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_HANDLER_NODE_HANDLER_H_