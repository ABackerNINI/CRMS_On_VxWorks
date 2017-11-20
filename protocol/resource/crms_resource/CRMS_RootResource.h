#pragma once

#ifndef _CRMS_RESOURCE_ROOT_RESOURCE_H_
#define _CRMS_RESOURCE_ROOT_RESOURCE_H_

#include "../ResourceBase.h"
#include "CRMS_HasChildren.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_RootResource : public CRMS_HasChildren {
                public:
                    CRMS_RootResource() :
                            CRMS_HasChildren() {
                    }
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_ROOT_RESOURCE_H_