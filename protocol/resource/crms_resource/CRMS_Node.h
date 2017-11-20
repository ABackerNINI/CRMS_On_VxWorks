#pragma once

#ifndef _CRMS_RESOURCE_NODE_H_
#define _CRMS_RESOURCE_NODE_H_

#include "../ResourceBase.h"
#include "CRMS_Resource.h"
#include "../crms_enumeration/CRMS_NodeExecutionState.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Node : public CRMS_Resource {
                public:
                    CRMS_Node() :
                            CRMS_Resource() {
                    }

                DEFINE_MEMBER(desc, _STRING)

                DEFINE_MEMBER(params, _STRING)//Object

                DEFINE_MEMBER(nno, _STRING)

                DEFINE_MEMBER(re, _STRING)//Object

                DEFINE_MEMBER(st, enumeration::CRMS_NodeExecutionState)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_NODE_H_