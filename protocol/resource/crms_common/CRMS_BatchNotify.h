#pragma once

#ifndef _CRMS_RESOURCE_BATCH_NOTIFY_H_
#define _CRMS_RESOURCE_BATCH_NOTIFY_H_

#include "../ResourceBase.h"

#include "../../../utility/TimeUtil/Duration.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_BatchNotify {
                public:
                    CRMS_BatchNotify() :
                            num(NJSON_DEFAULT_VALUE_INT) {
                    }

                DEFINE_MEMBER(num, _INT)

                DEFINE_MEMBER(dur, _DURATION)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_BATCH_NOTIFY_H_