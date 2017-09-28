//
// Created by nini on 9/27/17.
//

#ifndef CRMS_ON_VXWORKS_DATATABLE_HANDLER_H
#define CRMS_ON_VXWORKS_DATATABLE_HANDLER_H

#include "../../resource/crms_resource/CRMS_Req.h"
#include "../../resource/crms_resource/CRMS_Rsp.h"
#include "../../resource/crms_resource/CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace agent {

            namespace resource_handler {

                class data_table_handler {
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


#endif //CRMS_ON_VXWORKS_DATATABLE_HANDLER_H
