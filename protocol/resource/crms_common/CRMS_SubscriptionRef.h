#pragma once

#ifndef _CRMS_RESOURCE_SUBSCRIPTION_REF_H_
#define _CRMS_RESOURCE_SUBSCRIPTION_REF_H_

#include "../ResourceBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {
                class CRMS_SubscriptionRef {
                public:

                DEFINE_MEMBER(id, _STRING);
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_SUBSCRIPTION_REF_H_
