#pragma once

#ifndef _CRMS_RESOURCE_NOTIFICATION_H_
#define _CRMS_RESOURCE_NOTIFICATION_H_

#include "../DEF.h"
#include "../crms_primitive/CRMS_PrimitiveContentType.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_Notification {
                public:
                    CRMS_Notification() {
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(pc);
//                                SET(nfu);
//                            } else {
//                                SET_IF_KEY(pc) SET_IF_KEY(nfu) {
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
//                            GET(pc);
//                            GET(nfu);
//                        }
//                    }

                    ~CRMS_Notification() {
                    }

                DEFINE_MEMBER(pc, crms::protocol::resource::primitive::CRMS_PrimitiveContentType<>)////mark:pc

                DEFINE_MEMBER(nfu, _LIST < _STRING >)
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_NOTIFICATION_H_
