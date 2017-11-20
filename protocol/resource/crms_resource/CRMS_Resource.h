#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_H_
#define _CRMS_RESOURCE_RESOURCE_H_

#include "../ResourceBase.h"

#include "../crms_common/CRMS_Subscription.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Resource {
                public:
                    CRMS_Resource() :
                            ty(NJSON_DEFAULT_VALUE_INT) {
                    }

                DEFINE_MEMBER(ri, _STRING)

                DEFINE_MEMBER(pa, _STRING)

                DEFINE_MEMBER(rn, _STRING)

                DEFINE_MEMBER(ty, _INT)

                DEFINE_MEMBER(ct, _DATETIME)

                DEFINE_MEMBER(lt, _DATETIME)

                DEFINE_MEMBER(onto, _STRING)

                DEFINE_MEMBER(subs, _MAP < _STRING, common::CRMS_Subscription >)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RESOURCE_H_