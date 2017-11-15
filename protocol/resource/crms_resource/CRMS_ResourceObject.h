#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_OBJECT_H_
#define _CRMS_RESOURCE_RESOURCE_OBJECT_H_

#include "../DEF.h"

#include "CRMS_HasChildren.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_ResourceObject : public CRMS_HasChildren {
                public:
                    CRMS_ResourceObject() {
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        SERIALIZE_SUPER_CLASS(CRMS_HasChildren);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                            } else {
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
//                        }
//                    }

                    ~CRMS_ResourceObject() {
                    }
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RESOURCE_OBJECT_H_