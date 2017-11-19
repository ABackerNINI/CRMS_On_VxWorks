#pragma once

#ifndef _CRMS_JSON_DATA_TABLE_SUPPORT_H_
#define _CRMS_JSON_DATA_TABLE_SUPPORT_H_

#include "../support_base.h"
#include "../../resource/crms_resource/CRMS_DataTable.h"

template<>
struct njson_support<crms::protocol::resource::resource::CRMS_DataTable> {
    static bool is_default(const crms::protocol::resource::resource::CRMS_DataTable &njson_var) {
        return false;
    }

    static JSON_Value *serialize(const crms::protocol::resource::resource::CRMS_DataTable &njson_var) {
        NJSON_SERIALIZE_INIT;
        {
            NJSON_NSERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NSET(desc);
            NJSON_NSET(columns);
            NJSON_NSET(con);
            NJSON_NSET(count);
        }
        NJSON_RET;
    }

    static void deserialize(JSON_Value *njson_val, crms::protocol::resource::resource::CRMS_DataTable *njson_var) {
        NJSON_DESERIALIZE_INIT;
        {
            NJSON_NDESERIALIZE_SUPER_CLASS(crms::protocol::resource::resource::CRMS_Resource);

            NJSON_NGET(desc);
            NJSON_NGET(columns);
            NJSON_NGET(con);
            NJSON_NGET(count);
        }
    }
};

#endif //_CRMS_JSON_DATA_TABLE_SUPPORT_H_