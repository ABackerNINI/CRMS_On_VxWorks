#pragma once

#ifndef _CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_
#define _CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_

#include "../DEF.h"

#include "../../../utility/DateTime/Duration.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace attribute {

                class CRMS_BatchNotify {
                public:
                    CRMS_BatchNotify() :
                            num(DEFAULT_VALUE_INT) {
                    }

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(num);
                                SET(dur);
                            } else {
                                SET_IF_KEY(num) SET_IF_KEY(dur) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(num);
                            GET(dur);
                        }
                    }

                    ~CRMS_BatchNotify() {
                    }

                DEFINE_MEMBER(num, _INT)

                DEFINE_MEMBER(dur, _DURATION)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_ATTRIBUTE_BATCH_NOTIFY_H_