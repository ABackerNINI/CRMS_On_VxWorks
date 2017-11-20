#pragma once

#ifndef _CRMS_RESOURCE_REQUEST_H_
#define _CRMS_RESOURCE_REQUEST_H_

#include "../ResourceBase.h"
#include "CRMS_PrimitiveContentType.h"
#include "../crms_enumeration/CRMS_Operation.h"
#include "../crms_enumeration/CRMS_ResultContent.h"
#include "../crms_enumeration/CRMS_SubscriptionOperation.h"
#include "../crms_common/CRMS_FilterCriteria.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {

                class CRMS_Req {
                public:
                    CRMS_Req() :
                            ty(NJSON_DEFAULT_VALUE_INT) {
                        memset(&proxy, -1, sizeof(proxy));
                    }

                DEFINE_MEMBER(op, enumeration::CRMS_Operation)

                DEFINE_MEMBER(to, _STRING)

                DEFINE_MEMBER(fr, _STRING)

                DEFINE_MEMBER(rqi, _STRING)

                DEFINE_MEMBER(ty, _INT)

                DEFINE_MEMBER(rn, _STRING)

                DEFINE_MEMBER(pc, CRMS_PrimitiveContentType<void>)

                DEFINE_MEMBER(ot, _DATETIME)

                DEFINE_MEMBER(rqet, _DATETIME)

                DEFINE_MEMBER(rset, _DATETIME)

                DEFINE_MEMBER(oet, _DATETIME)

                DEFINE_MEMBER(rcn, enumeration::CRMS_ResultContent)

                DEFINE_MEMBER(da, _STRING)

                DEFINE_MEMBER(gid, _STRING)

                DEFINE_MEMBER(fc, common::CRMS_FilterCriteria)

                DEFINE_MEMBER(so, enumeration::CRMS_SubscriptionOperation)

                DEFINE_MEMBER(proxy, _BOOL)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_REQUEST_H_