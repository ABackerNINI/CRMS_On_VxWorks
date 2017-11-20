#pragma once

#ifndef _CRMS_RESOURCE_AGGREGATED_NOTIFICATION_H_
#define _CRMS_RESOURCE_AGGREGATED_NOTIFICATION_H_

#include "../ResourceBase.h"
#include "CRMS_Notification.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_AggregatedNotification {
                public:

                DEFINE_MEMBER(nfs, _LIST < CRMS_Notification >)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_AGGREGATED_NOTIFICATION_H_
