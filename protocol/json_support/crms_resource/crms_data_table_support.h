#pragma once

#ifndef _CRMS_JSON_DATA_TABLE_SUPPORT_H_
#define _CRMS_JSON_DATA_TABLE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_DataTable.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_DataTable> {
    static bool is_default_value(const crms::protocol::resource::resource::CRMS_DataTable &njson_var) {
        return false;
    }

    static void serialize(JSON_Value *njson_val, const char *njson_name,
                          const crms::protocol::resource::resource::CRMS_DataTable &njson_var) {
        SERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        SET(desc);
        SET(columns);
        SET(con);
        SET(count);
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_DataTable *njson_var) {
        DESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

        GET(desc);
        GET(columns);
        GET(con);
        GET(count);
    }
};

#endif //_CRMS_JSON_DATA_TABLE_SUPPORT_H_