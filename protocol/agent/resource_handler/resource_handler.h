#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_HANDLER_H_
#define _CRMS_RESOURCE_RESOURCE_HANDLER_H_

#include "../../resource/crms_primitive/CRMS_Req.h"
#include "../../resource/crms_primitive/CRMS_Rsp.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace agent {

            namespace resource_handler {

                class resource_handler {
                public:
                    static void handle_crud(resource::primitive::CRMS_Req *_Req, resource::primitive::CRMS_Rsp *_Rsp,
                                            resource::resource::CRMS_Resource *_Res);
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RESOURCE_HANDLER_H_