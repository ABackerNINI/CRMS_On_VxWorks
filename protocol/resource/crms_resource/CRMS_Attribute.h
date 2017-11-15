#pragma once

#ifndef _CRMS_RESOURCE_ATTRIBUTE_H_
#define _CRMS_RESOURCE_ATTRIBUTE_H_

#include "../DEF.h"
#include "CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Attribute : public CRMS_Resource {
                public:
                    CRMS_Attribute() {
                        memset(&ro, -1, sizeof(ro));
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        SERIALIZE_SUPER_CLASS(CRMS_Resource);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(nm);
//                                SET(ro);
//                                SET(data);
//                            } else {
//                                SET_IF_KEY(nm) SET_IF_KEY(ro) SET_IF_KEY(data) {
//                                    return false;
//                                }
//                            }
//                        }
//
//                        return true;
//                    }
//
//                    void deserialize(JSON_Value *_doc_) {
//                        DESERIALIZE_SUPER_CLASS(CRMS_Resource);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            GET(nm);
//                            GET(ro);
//                            GET(data);
//                        }
//                    }

                    ~CRMS_Attribute() {
                    }

                DEFINE_MEMBER(nm, _STRING)

                DEFINE_MEMBER(ro, _BOOL)

                DEFINE_MEMBER(data, _STRING)////mark:byte[]
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_ATTRIBUTE_H_