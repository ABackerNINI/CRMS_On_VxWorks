#pragma once

#ifndef _CRMS_RESOURCE_CHILD_RESOURCE_REF_H_
#define _CRMS_RESOURCE_CHILD_RESOURCE_REF_H_

#include "../ResourceBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_ChildResourceRef {
                public:
                    CRMS_ChildResourceRef() :
                            ty(NJSON_DEFAULT_VALUE_INT) {
                    }

                DEFINE_MEMBER(v, _STRING)

                DEFINE_MEMBER(ty, _INT)

                DEFINE_MEMBER(rn, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_CHILD_RESOURCE_REF_H_