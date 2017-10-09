//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_ENUMERATION_NOTIFICATION_CONTENT_TYPE_H_
#define _CRMS_RESOURCE_ENUMERATION_NOTIFICATION_CONTENT_TYPE_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_NotificationContentType : public EnumerationBase {
                    CRMS_NotificationContentType() {}

                    CRMS_NotificationContentType(int val) { this->val = val; }

                    static const _SHORT modifiedAttributes = 1;
                    static const _SHORT wholeResource = 2;
                    static const _SHORT referenceOnly = 3;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_ENUMERATION_NOTIFICATION_CONTENT_TYPE_H_
