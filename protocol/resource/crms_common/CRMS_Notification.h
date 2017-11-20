#pragma once

#ifndef _CRMS_RESOURCE_NOTIFICATION_H_
#define _CRMS_RESOURCE_NOTIFICATION_H_

#include "../ResourceBase.h"
#include "../crms_primitive/CRMS_PrimitiveContentType.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_Notification {
                public:

                DEFINE_MEMBER(pc, crms::protocol::resource::primitive::CRMS_PrimitiveContentType<>)////mark:pc

                DEFINE_MEMBER(nfu, _LIST < _STRING >)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_NOTIFICATION_H_
