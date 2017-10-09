//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_CRMS_RETRIEVE_QUERY_TYPE_H_
#define _CRMS_RESOURCE_CRMS_RETRIEVE_QUERY_TYPE_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_RetrieveQueryType : public EnumerationBase {
                    CRMS_RetrieveQueryType() {}

                    CRMS_RetrieveQueryType(int val) { this->val = val; }

                    static const _SHORT None = 1;
                    static const _SHORT PartialRetrieve = 2;
                    static const _SHORT Pagination = 3;
                    static const _SHORT SubscriptionRetrieve = 4;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_CRMS_RETRIEVE_QUERY_TYPE_H_
