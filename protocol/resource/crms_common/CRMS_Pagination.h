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

                struct CRMS_Pagination {
                    _INT offset;
                    _INT len;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_COMMON_PAGINATION_H_
