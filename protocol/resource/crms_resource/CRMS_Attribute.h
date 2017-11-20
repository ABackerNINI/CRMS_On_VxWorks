#pragma once

#ifndef _CRMS_RESOURCE_ATTRIBUTE_H_
#define _CRMS_RESOURCE_ATTRIBUTE_H_

#include "../ResourceBase.h"
#include "CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Attribute : public CRMS_Resource {
                public:
                    CRMS_Attribute() :
                            CRMS_Resource() {
                        memset(&ro, -1, sizeof(ro));
                    }

                DEFINE_MEMBER(nm, _STRING)

                DEFINE_MEMBER(ro, _BOOL)

                DEFINE_MEMBER(data, _STRING)////mark:byte[]
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_ATTRIBUTE_H_