#pragma once

#ifndef _CRMS_JSON_FILTER_CRITERIA_SUPPORT_H_
#define _CRMS_JSON_FILTER_CRITERIA_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_common/CRMS_FilterCriteria.h"

template<>
struct njson_support<crms::protocol::resource::common::CRMS_FilterCriteria> {
    static bool is_default_value(const crms::protocol::resource::common::CRMS_FilterCriteria &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::common::CRMS_FilterCriteria &njson_var) {
        SET(crb);
        SET(cra);
        SET(ms);
        SET(us);
        SET(sts);
        SET(stb);
        SET(exb);
        SET(exa);
        SET(lbl);
        SET(rty);
        SET(sza);
        SET(szb);
        SET(cty);
        SET(lim);
        SET(fu);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::common::CRMS_FilterCriteria *njson_var) {
        GET(crb);
        GET(cra);
        GET(ms);
        GET(us);
        GET(sts);
        GET(stb);
        GET(exb);
        GET(exa);
        GET(lbl);
        GET(rty);
        GET(sza);
        GET(szb);
        GET(cty);
        GET(lim);
        GET(fu);
    }
};

#endif //_CRMS_JSON_FILTER_CRITERIA_SUPPORT_H_