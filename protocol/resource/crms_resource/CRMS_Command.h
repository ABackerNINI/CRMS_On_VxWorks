#pragma once

#ifndef _CRMS_RESOURCE_COMMAND_H_
#define _CRMS_RESOURCE_COMMAND_H_

#include "../ResourceBase.h"
#include "CRMS_HasChildren.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Command : public CRMS_HasChildren {
                public:
                    CRMS_Command() {
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        SERIALIZE_SUPER_CLASS(CRMS_HasChildren);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(desc);
//                                SET(con);
//                            } else {
//                                SET_IF_KEY(desc) SET_IF_KEY(con) {
//                                    return false;
//                                }
//                            }
//                        }
//
//                        return true;
//                    }
//
//                    void deserialize(JSON_Value *_doc_) {
//                        DESERIALIZE_SUPER_CLASS(CRMS_HasChildren);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            GET(desc);
//                            GET(con);
//                        }
//                    }

                    ~CRMS_Command() {
                    }

                DEFINE_MEMBER(desc, _STRING)

                DEFINE_MEMBER(con, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_COMMAND_H_