#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_STATUS_H_
#define _CRMS_RESOURCE_RESOURCE_STATUS_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_ResourceStatus : public EnumerationBase {
                    CRMS_ResourceStatus() {}

                    CRMS_ResourceStatus(int val) { this->val = val; }

                    static const _SHORT childCreated = 1;
                    static const _SHORT childDeleted = 2;
                    static const _SHORT updated = 3;
                    static const _SHORT deleted = 4;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_RESOURCE_STATUS_H_
