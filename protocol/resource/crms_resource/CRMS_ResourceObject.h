#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_OBJECT_H_
#define _CRMS_RESOURCE_RESOURCE_OBJECT_H_

#include "../ResourceBase.h"
#include "CRMS_HasChildren.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_ResourceObject : public CRMS_HasChildren {
                public:
                    CRMS_ResourceObject() :
                            CRMS_HasChildren() {
                    }
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RESOURCE_OBJECT_H_