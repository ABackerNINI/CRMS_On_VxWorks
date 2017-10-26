//
// Created by nini on 10/9/17.
//

#ifndef _CRMS_RESOURCE_COMMON_AGGREGATED_NOTIFICATION_H_
#define _CRMS_RESOURCE_COMMON_AGGREGATED_NOTIFICATION_H_

#include "../DEF.h"
#include "CRMS_Notification.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_AggregatedNotification {
                public:
                    CRMS_AggregatedNotification() {
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(nfs);
//                            } else {
//                                SET_IF_KEY(nfs) {
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
//                            GET(nfs);
//                        }
//                    }

                    ~CRMS_AggregatedNotification() {
                    }

                DEFINE_MEMBER(nfs, _LIST < CRMS_Notification >)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_COMMON_AGGREGATED_NOTIFICATION_H_
