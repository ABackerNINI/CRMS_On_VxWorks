#pragma once

#ifndef _CRMS_RESOURCE_DATA_TABLE_H_
#define _CRMS_RESOURCE_DATA_TABLE_H_

#include "../ResourceBase.h"
#include "CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_DataTable : public CRMS_Resource {
                public:
                    CRMS_DataTable() :
                            CRMS_Resource(),
                            count(NJSON_DEFAULT_VALUE_INT) {
                    }

                DEFINE_MEMBER(desc, _STRING)

                DEFINE_MEMBER(columns, _LIST < _STRING >)

                DEFINE_MEMBER(con, _LIST < _MAP < _STRING, _STRING > >)//std::list<std::map<_STRING,Object>

                DEFINE_MEMBER(count, _INT)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_DATA_TABLE_H_