#pragma once

#ifndef _CRMS_RESOURCE_NODE_EXECUTION_STATE_H_
#define _CRMS_RESOURCE_NODE_EXECUTION_STATE_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_NodeExecutionState : public EnumerationBase {
                    CRMS_NodeExecutionState() {}

                    CRMS_NodeExecutionState(int val) { this->val = val; }

                    static const _SHORT RUN = 1;
                    static const _SHORT PAUSE = 2;
                    static const _SHORT RESTART = 3;
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_NODE_EXECUTION_STATE_H_