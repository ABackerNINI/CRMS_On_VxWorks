//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_ENUMERATION_RESOURCE_TYPE_H_
#define _CRMS_RESOURCE_ENUMERATION_RESOURCE_TYPE_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_ResourceType : public EnumerationBase {
                    CRMS_ResourceType() {}

                    CRMS_ResourceType(int val) { this->val = val; }

                    static const _SHORT rootResource = 1;
                    static const _SHORT resourceObject = 2;
                    static const _SHORT attribute = 3;
                    static const _SHORT command = 4;
                    static const _SHORT dataTable = 5;
                    static const _SHORT node = 6;
                    static const _SHORT group = 7;
                    static const _SHORT subscription = 8;
                    static const _SHORT childResourceRef = 9;
                    static const _SHORT pagination = 10;
                    static const _SHORT partialRetrieve = 11;
                    static const _SHORT subscriptionRetrieve = 12;
                    static const _SHORT notification = 13;
                    static const _SHORT aggregatedNotification = 14;
                    static const _SHORT aggregatedResponse = 15;
                    static const _SHORT string = 16;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_ENUMERATION_RESOURCE_TYPE_H_
