#pragma once

#ifndef _CRMS_RESOURCE_GROUP_H_
#define _CRMS_RESOURCE_GROUP_H_

#include "../ResourceBase.h"
#include "../crms_enumeration/CRMS_MemberType.h"
#include "../crms_enumeration/CRMS_ConsistencyStrategy.h"
#include "CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Group : public CRMS_Resource {
                public:
                    CRMS_Group() :
                            CRMS_Resource(),
                            cnm(NJSON_DEFAULT_VALUE_INT),
                            mnm(NJSON_DEFAULT_VALUE_INT) {
                        memset(&mtv, -1, sizeof(mtv));
                    }

                DEFINE_MEMBER(mt, enumeration::CRMS_MemberType)

                DEFINE_MEMBER(cnm, _INT)

                DEFINE_MEMBER(mnm, _INT)

                DEFINE_MEMBER(mid, _LIST < _STRING >)

                DEFINE_MEMBER(mtv, _BOOL)

                DEFINE_MEMBER(csy, enumeration::CRMS_ConsistencyStrategy)

                DEFINE_MEMBER(gn, _STRING)

                DEFINE_MEMBER(cr, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_GROUP_H_