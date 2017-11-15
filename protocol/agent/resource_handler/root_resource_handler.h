#pragma once

#ifndef CRMS_ON_VXWORKS_ROOT_RESOURCE_H
#define CRMS_ON_VXWORKS_ROOT_RESOURCE_H

#include "../../resource/crms_primitive/CRMS_Req.h"
#include "../../resource/crms_primitive/CRMS_Rsp.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace agent {

            namespace resource_handler {

                class root_resource_handler {
                public:
                    static void Create(resource::primitive::CRMS_Req *_Req, resource::primitive::CRMS_Rsp *_Rsp,
                                       resource::resource::CRMS_Resource *_Res);

                    static void Retrieve(resource::primitive::CRMS_Req *_Req, resource::primitive::CRMS_Rsp *_Rsp,
                                         resource::resource::CRMS_Resource *_Res);

                    static void Update(resource::primitive::CRMS_Req *_Req, resource::primitive::CRMS_Rsp *_Rsp,
                                       resource::resource::CRMS_Resource *_Res);

                    static void Delete(resource::primitive::CRMS_Req *_Req, resource::primitive::CRMS_Rsp *_Rsp,
                                       resource::resource::CRMS_Resource *_Res);

                    static void init_root_resource();
                };
            }
        }
    }
}

#endif //CRMS_ON_VXWORKS_ROOT_RESOURCE_H
