#pragma once

#ifndef _CRMS_RESOURCE_AGGREGATED_RESPONSE_H_
#define _CRMS_RESOURCE_AGGREGATED_RESPONSE_H_

#include "../ResourceBase.h"
#include "../crms_primitive/CRMS_Rsp.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_AggregatedResponse {
                public:

                DEFINE_MEMBER(rsps, _LIST < crms::protocol::resource::primitive::CRMS_Rsp >)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_AGGREGATED_RESPONSE_H_
