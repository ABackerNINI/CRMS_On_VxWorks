//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_COMMON_PARTIAL_RETRIEVE_H_
#define _CRMS_RESOURCE_COMMON_PARTIAL_RETRIEVE_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                struct CRMS_PartialRetrieve {
                    enumeration::CRMS_PartialRetrieveType ty;

                    union {////mark:not use list-type here.cut original string afterwards.
                        const _CSTR in;
                        const _CSTR ex;
                    } pr;
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_COMMON_PARTIAL_RETRIEVE_H_
