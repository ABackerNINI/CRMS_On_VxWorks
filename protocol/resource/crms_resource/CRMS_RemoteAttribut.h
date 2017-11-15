#pragma once

#ifndef _CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_
#define _CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_

#include "../DEF.h"

#include "CRMS_Attribute.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_RemoteAttribute : public CRMS_Attribute {
                public:
                    CRMS_RemoteAttribute() :
                            rm(DEFAULT_VALUE_INT) {
                        memset(&proxy, -1, sizeof(proxy));
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        SERIALIZE_SUPER_CLASS(CRMS_Attribute);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(rm);
//                                SET(rri);
//                                SET(proxy);
//                            } else {
//                                SET_IF_KEY(rm) SET_IF_KEY(rri) SET_IF_KEY(proxy) {
//                                    return false;
//                                }
//                            }
//                        }
//
//                        return true;
//                    }
//
//                    void deserialize(JSON_Value *_doc_) {
//                        DESERIALIZE_SUPER_CLASS(CRMS_Attribute);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            GET(rm);
//                            GET(rri);
//                            GET(proxy);
//                        }
//                    }

                    ~CRMS_RemoteAttribute() {
                    }

                DEFINE_MEMBER(rm, _INT)

                DEFINE_MEMBER(rri, _STRING)

                DEFINE_MEMBER(proxy, _BOOL)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_REMOTE_ATTRIBUTE_H_