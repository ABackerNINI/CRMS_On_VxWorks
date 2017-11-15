#pragma once

#ifndef _CRMS_RESOURCE_RESULT_CONTENT_H_
#define _CRMS_RESOURCE_RESULT_CONTENT_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_ResultContent : public EnumerationBase {
                    CRMS_ResultContent() {}

                    CRMS_ResultContent(int val) { this->val = val; }

                    static const _SHORT Nothing = 1;
                    static const _SHORT Attributes = 2;
                    static const _SHORT ChildResources = 3;
                    static const _SHORT Attribute_childResources = 4;
                    static const _SHORT OriginalResources = 5;
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RESULT_CONTENT_H_