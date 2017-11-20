#pragma once

#ifndef _CRMS_RESOURCE_FILTER_CRITERIA_H_
#define _CRMS_RESOURCE_FILTER_CRITERIA_H_

#include "../ResourceBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_FilterCriteria {
                public:
                    CRMS_FilterCriteria() :
                            sts(NJSON_DEFAULT_VALUE_INT),
                            stb(NJSON_DEFAULT_VALUE_INT),
                            sza(NJSON_DEFAULT_VALUE_INT),
                            szb(NJSON_DEFAULT_VALUE_INT),
                            lim(NJSON_DEFAULT_VALUE_INT) {
                    }

                DEFINE_MEMBER(crb, _DATETIME)

                DEFINE_MEMBER(cra, _DATETIME)

                DEFINE_MEMBER(ms, _DATETIME)

                DEFINE_MEMBER(us, _DATETIME)

                DEFINE_MEMBER(sts, _INT)

                DEFINE_MEMBER(stb, _INT)

                DEFINE_MEMBER(exb, _DATETIME)

                DEFINE_MEMBER(exa, _DATETIME)

                DEFINE_MEMBER(lbl, _LIST < _STRING >)

                DEFINE_MEMBER(rty, _LIST < _INT >)

                DEFINE_MEMBER(sza, _INT)

                DEFINE_MEMBER(szb, _INT)

                DEFINE_MEMBER(cty, _LIST < _STRING >)

                DEFINE_MEMBER(lim, _INT)

                DEFINE_MEMBER(fu, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_FILTER_CRITERIA_H_