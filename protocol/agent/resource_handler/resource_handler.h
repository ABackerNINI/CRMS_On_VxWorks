#pragma once

#ifndef _CRMS_RESOURCE_HANDLER_HANDLER_BASE_H_
#define _CRMS_RESOURCE_HANDLER_HANDLER_BASE_H_

#include "../../resource/crms_resource/CRMS_Req.h"
#include "../../resource/crms_resource/CRMS_Rsp.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace agent {

            namespace resource_handler {

                class resource_handler {
                public:
                    static void handle_crud(resource::resource::CRMS_Req *_Req, resource::resource::CRMS_Rsp *_Rsp,
                                            resource::resource::CRMS_Resource *_Res);
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_HANDLER_HANDLER_BASE_H_