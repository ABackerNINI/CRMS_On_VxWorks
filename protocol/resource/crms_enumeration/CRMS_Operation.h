#pragma once

#ifndef _CRMS_RESOURCE_ENUMERATION_OPERATION_H_
#define _CRMS_RESOURCE_ENUMERATION_OPERATION_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_Operation : public EnumerationBase {
                    CRMS_Operation() {}

                    CRMS_Operation(int val) { this->val = val; }

                    static const _SHORT Create = 1;
                    static const _SHORT Retrieve = 2;
                    static const _SHORT Update = 3;
                    static const _SHORT Delete = 4;
                    static const _SHORT Notify = 5;
                    static const _SHORT ForwardNotify = 6;
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_ENUMERATION_OPERATION_H_