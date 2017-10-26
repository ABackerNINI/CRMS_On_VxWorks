#pragma once

#ifndef _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_
#define _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_

#include "../DEF.h"
#include "../Object.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {

                template<typename T = void>
                class CRMS_PrimitiveContentType {
                public:
                    CRMS_PrimitiveContentType() : ty(DEFAULT_VALUE_INT), val(NULL) {}

                    CRMS_PrimitiveContentType(int ty, T *val) : ty(ty), val(val) {}

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(ty);
                                SET(val);
                            } else {
                                SET_IF_KEY(ty) SET_IF_KEY(val) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(ty);
                            GET(val);
                        }
                    }

                    ~CRMS_PrimitiveContentType() {
//                        if (val)delete[] val;////mark:may raise some problems.
                    }

                DEFINE_MEMBER(ty, _INT)

                DEFINE_POINTER_MEMBER(val, T *)

//                DEFINE_MEMBER(val, Object)

//                private:
//                    T *val;
//                public:
//                    T *get_val() { return val; }
//
//                    const T *get_val() const { return val; }
//
//                    void set_val(T *val) { this->val = val; }

//                DEFINE_MEMBER(val, T*)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_