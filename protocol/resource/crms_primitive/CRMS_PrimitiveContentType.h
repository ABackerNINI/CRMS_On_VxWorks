#pragma once

#ifndef _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_
#define _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {

                class CRMS_PrimitiveContentType {
                public:
                    CRMS_PrimitiveContentType() {
                    }

                    CRMS_PrimitiveContentType(const _STRING &value) :
                            value(value) {
                    }

                    CRMS_PrimitiveContentType(const _STRING &value, const _STRING &type) :
                            value(value),
                            type(type) {
                    }

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(value);
                                SET(type);
                            } else {
                                SET_IF_KEY(value) SET_IF_KEY(type) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(value);
                            GET(type);
                        }
                    }

                    ~CRMS_PrimitiveContentType() {
                    }

                DEFINE_MEMBER(value, _STRING)

                DEFINE_MEMBER(type, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_