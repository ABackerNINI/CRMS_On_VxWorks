//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_COMMON_RETRIEVE_QUERY_H_
#define _CRMS_RESOURCE_COMMON_RETRIEVE_QUERY_H_

#include "CRMS_PartialRetrieve.h"
#include "CRMS_Pagination.h"
#include "CRMS_SubscriptionRetrieve.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                struct CRMS_RetrieveQuery {
                public:
                    enumeration::CRMS_RetrieveQueryType ty;

                    union {
                        CRMS_PartialRetrieve pr;

                        CRMS_Pagination pg;

                        CRMS_SubscriptionRetrieve sr;
                    } rq;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_COMMON_RETRIEVE_QUERY_H_
