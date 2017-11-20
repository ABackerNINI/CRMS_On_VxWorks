#pragma once

#ifndef _CRMS_RESOURCE_REMOTE_RESOURCE_OBJECT_H_
#define _CRMS_RESOURCE_REMOTE_RESOURCE_OBJECT_H_

#include "../ResourceBase.h"
#include "CRMS_ResourceObject.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_RemoteResourceObject : public CRMS_ResourceObject {
                public:
                    CRMS_RemoteResourceObject() :
                            CRMS_ResourceObject(),
                            rm(NJSON_DEFAULT_VALUE_INT) {
                        memset(&alive, -1, sizeof(alive));
                        memset(&proxy, -1, sizeof(proxy));
                    }

                DEFINE_MEMBER(rm, _INT)

                DEFINE_MEMBER(rri, _STRING)

                DEFINE_MEMBER(alive, _BOOL)

                DEFINE_MEMBER(proxy, _BOOL)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_REMOTE_RESOURCE_OBJECT_H_