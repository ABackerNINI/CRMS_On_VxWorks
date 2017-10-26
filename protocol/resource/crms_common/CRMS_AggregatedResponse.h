//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_COMMON_AGGREGATED_RESPONSE_H_
#define _CRMS_RESOURCE_COMMON_AGGREGATED_RESPONSE_H_

#include "../DEF.h"
#include "../crms_primitive/CRMS_Rsp.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_AggregatedResponse {
                public:
                    CRMS_AggregatedResponse() {
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(rsps);
//                            } else {
//                                SET_IF_KEY(rsps) {
//                                    return false;
//                                }
//                            }
//                        }
//
//                        return true;
//                    }
//
//                    void deserialize(JSON_Value *_doc_) {
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            GET(rsps);
//                        }
//                    }

                    ~CRMS_AggregatedResponse() {
                    }

                DEFINE_MEMBER(rsps, _LIST < crms::protocol::resource::primitive::CRMS_Rsp >)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_COMMON_AGGREGATED_RESPONSE_H_
