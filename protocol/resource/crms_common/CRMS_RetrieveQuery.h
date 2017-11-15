#pragma once

#ifndef _CRMS_RESOURCE_RETRIEVE_QUERY_H_
#define _CRMS_RESOURCE_RETRIEVE_QUERY_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                struct CRMS_PartialRetrieveType {
                    static const _SHORT In = 1;
                    static const _SHORT Ex = 2;
                };

                struct CRMS_RetrieveQueryType {
                    static const _SHORT None = 1;
                    static const _SHORT PartialRetrieve = 2;
                    static const _SHORT PaginationRetrieve = 3;
                    static const _SHORT SubscriptionRetrieve = 4;
                };

                struct CRMS_PartialRetrieve {

                DEFINE_MEMBER(ty, _INT) //CRMS_PartialRetrieveType

                DEFINE_POINTER_MEMBER(val, const _CSTR)
                };

                struct CRMS_PaginationRetrieve {

                DEFINE_MEMBER(offset, _INT)

                DEFINE_MEMBER(len, _INT)
                };

                struct CRMS_SubscriptionRetrieve {

                DEFINE_POINTER_MEMBER(id, const _CSTR)
                };

                union _CRMS_RetrieveQueryUnion {

                DEFINE_MEMBER(pr, CRMS_PartialRetrieve)

                DEFINE_MEMBER(pg, CRMS_PaginationRetrieve)

                DEFINE_MEMBER(sr, CRMS_SubscriptionRetrieve)
//                    CRMS_PartialRetrieve pr;
//                    CRMS_PaginationRetrieve pg;
//                    CRMS_SubscriptionRetrieve sr;
                };

                class CRMS_RetrieveQuery {
                public:
                    CRMS_RetrieveQuery() :
                            ty(crms::protocol::resource::common::CRMS_RetrieveQueryType::None) {}

                DEFINE_MEMBER(ty, _INT) //CRMS_RetrieveQueryType

                DEFINE_MEMBER(val, _CRMS_RetrieveQueryUnion)
                };

            }
        }
    }
}

#endif //_CRMS_RESOURCE_RETRIEVE_QUERY_H_
