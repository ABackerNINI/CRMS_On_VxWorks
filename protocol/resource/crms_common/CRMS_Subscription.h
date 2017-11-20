#pragma once

#ifndef _CRMS_RESOURCE_SUBSCRIPTION_H_
#define _CRMS_RESOURCE_SUBSCRIPTION_H_

#include "../ResourceBase.h"
#include "CRMS_BatchNotify.h"
#include "../crms_enumeration/CRMS_SubscriptionEventType.h"
#include "../crms_enumeration/CRMS_NotificationContentType.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_Subscription {
                public:
                    CRMS_Subscription() :
                            id(NJSON_DEFAULT_VALUE_INT),
                            exc(NJSON_DEFAULT_VALUE_INT) {
                        memset(&ln, -1, sizeof(bool));
                    }

                DEFINE_MEMBER(ri, _STRING)

                DEFINE_MEMBER(id, _INT)

                DEFINE_MEMBER(ct, _DATETIME)

                DEFINE_MEMBER(ety, std::list<enumeration::CRMS_SubscriptionEventType>)

                DEFINE_MEMBER(exc, _INT)

                DEFINE_MEMBER(nu, _LIST < _STRING >)

                DEFINE_MEMBER(nfu, _LIST < _STRING >)

                DEFINE_MEMBER(gi, _STRING)

                DEFINE_MEMBER(bn, CRMS_BatchNotify)

                DEFINE_MEMBER(ln, _BOOL)

                DEFINE_MEMBER(nct, enumeration::CRMS_NotificationContentType)

                DEFINE_MEMBER(cr, _STRING)

                DEFINE_MEMBER(su, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_SUBSCRIPTION_H_