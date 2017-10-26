//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_COMMON_PAGINATION_H_
#define _CRMS_RESOURCE_COMMON_PAGINATION_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                struct CRMS_PaginationRetrieve {

                DEFINE_MEMBER(offset, _INT)

                DEFINE_MEMBER(len, _INT)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_COMMON_PAGINATION_H_
