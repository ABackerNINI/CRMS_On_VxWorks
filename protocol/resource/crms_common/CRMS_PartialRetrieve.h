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

                class CRMS_PartialRetrieve {

                DEFINE_MEMBER(ty, enumeration::CRMS_PartialRetrieveType)

                DEFINE_POINTER_MEMBER(val,const _CSTR)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_COMMON_PARTIAL_RETRIEVE_H_
