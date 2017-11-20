#pragma once

#ifndef _CRMS_RESOURCE_COMMAND_H_
#define _CRMS_RESOURCE_COMMAND_H_

#include "../ResourceBase.h"
#include "CRMS_HasChildren.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Command : public CRMS_HasChildren {
                public:
                    CRMS_Command() :
                            CRMS_HasChildren() {
                    }

                DEFINE_MEMBER(desc, _STRING)

                DEFINE_MEMBER(con, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_COMMAND_H_