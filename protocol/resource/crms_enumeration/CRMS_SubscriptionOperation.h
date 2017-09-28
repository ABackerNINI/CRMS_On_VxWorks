#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_
#define _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_SubscriptionOperation : public EnumerationBase {
                    CRMS_SubscriptionOperation() {}

                    CRMS_SubscriptionOperation(int val) { this->val = val; }

                    static const _SHORT Create = 1;
                    static const _SHORT Update = 2;
                    static const _SHORT Delete = 3;
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_OPERATION_H_