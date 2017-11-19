#pragma once

#ifndef _CRMS_JSON_FILTER_CRITERIA_SUPPORT_H_
#define _CRMS_JSON_FILTER_CRITERIA_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_common/CRMS_FilterCriteria.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_FilterCriteria> {
    static bool is_default(const crms::protocol::resource::common::CRMS_FilterCriteria &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::common::CRMS_FilterCriteria &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSET(crb);
            NJSON_NSET(cra);
            NJSON_NSET(ms);
            NJSON_NSET(us);
            NJSON_NSET(sts);
            NJSON_NSET(stb);
            NJSON_NSET(exb);
            NJSON_NSET(exa);
            NJSON_NSET(lbl);
            NJSON_NSET(rty);
            NJSON_NSET(sza);
            NJSON_NSET(szb);
            NJSON_NSET(cty);
            NJSON_NSET(lim);
            NJSON_NSET(fu);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_FilterCriteria *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NGET(crb);
            NJSON_NGET(cra);
            NJSON_NGET(ms);
            NJSON_NGET(us);
            NJSON_NGET(sts);
            NJSON_NGET(stb);
            NJSON_NGET(exb);
            NJSON_NGET(exa);
            NJSON_NGET(lbl);
            NJSON_NGET(rty);
            NJSON_NGET(sza);
            NJSON_NGET(szb);
            NJSON_NGET(cty);
            NJSON_NGET(lim);
            NJSON_NGET(fu);
        }
    }
};

#endif //_CRMS_JSON_FILTER_CRITERIA_SUPPORT_H_