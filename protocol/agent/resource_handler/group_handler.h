#pragma once

#ifndef _CRMS_RESOURCE_GROUP_HANDLER_H_
#define _CRMS_RESOURCE_GROUP_HANDLER_H_

#include "../../resource/crms_primitive/CRMS_Req.h"
#include "../../resource/crms_primitive/CRMS_Rsp.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace agent {

            namespace resource_handler {

                class group_hanler {
                public:
                    static void Create(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                       resource::resource::CRMS_Resource *res);

                    static void Retrieve(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                         resource::resource::CRMS_Resource *res);

                    static void Update(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                       resource::resource::CRMS_Resource *res);

                    static void Delete(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                       resource::resource::CRMS_Resource *res);
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_GROUP_HANDLER_H_
