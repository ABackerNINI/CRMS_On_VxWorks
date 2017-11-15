//
// Created by nini on 10/9/17.
//

#include "EnumerationBase.h"

#ifndef _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_EVENT_TYPE_H_
#define _CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_EVENT_TYPE_H_

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_SubscriptionEventType : public EnumerationBase {
                    CRMS_SubscriptionEventType() {}

                    CRMS_SubscriptionEventType(int val) { this->val = val; }

                    static const _SHORT childCreated = 1;
                    static const _SHORT childDeleted = 2;
                    static const _SHORT updated = 3;
                    static const _SHORT deleted = 4;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_ENUMERATION_SUBSCRIPTION_EVENT_TYPE_H_
