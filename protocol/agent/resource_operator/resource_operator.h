#pragma once

#ifndef CRMS_ON_VXWORKS_CREATOR_H
#define CRMS_ON_VXWORKS_CREATOR_H

#include "../../resource/crms_primitive/CRMS_Req.h"
#include "../../resource/crms_primitive/CRMS_Rsp.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace agent {

            namespace resource_operator {

                class resource_operator {
                public:
                    static void create_resource(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                                resource::resource::CRMS_Resource *parent);

                    static void
                    retrieve_resource(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                      resource::resource::CRMS_Resource *resource);

                    static void update_resource(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                                resource::resource::CRMS_Resource *resource);

                    static void delete_resource(resource::primitive::CRMS_Req *req, resource::primitive::CRMS_Rsp *rsp,
                                                resource::resource::CRMS_Resource *resource);
                };
            }
        }
    }
}

#endif //CRMS_ON_VXWORKS_CREATOR_H
