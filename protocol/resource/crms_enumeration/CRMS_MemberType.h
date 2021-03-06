#pragma once

#ifndef _CRMS_RESOURCE_MEMBER_TYPE_H_
#define _CRMS_RESOURCE_MEMBER_TYPE_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_MemberType : public EnumerationBase {
                public:
                    CRMS_MemberType() {}

                    CRMS_MemberType(int val) { this->val = val; }

                    static const _SHORT rootResource = 1;
                    static const _SHORT resourceObject = 2;
                    static const _SHORT attribute = 3;
                    static const _SHORT command = 4;
                    static const _SHORT dataTable = 5;
                    static const _SHORT node = 6;
                    static const _SHORT group = 7;
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_MEMBER_TYPE_H_