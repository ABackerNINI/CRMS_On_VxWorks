#pragma once

#ifndef _CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_
#define _CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_

#include "../ResourceBase.h"
#include "CRMS_Attribute.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_RemoteAttribute : public CRMS_Attribute {
                public:
                    CRMS_RemoteAttribute() :
                            CRMS_Attribute(),
                            rm(NJSON_DEFAULT_VALUE_INT) {
                        memset(&proxy, -1, sizeof(proxy));
                    }

                DEFINE_MEMBER(rm, _INT)

                DEFINE_MEMBER(rri, _STRING)

                DEFINE_MEMBER(proxy, _BOOL)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_