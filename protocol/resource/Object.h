//
// Created by nini on 10/25/17.
//

#ifndef CRMS_ON_VXWORKS_OBJECT_H
#define CRMS_ON_VXWORKS_OBJECT_H

#include "DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            template <typename T = void>
            class Object {
            public:
                Object() :
                        val(DEFAULT_VALUE_POINTER) {
                }

                Object(T *val) :
                        val(val) {
                }

                bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                    JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                    {
                        if (_key_ == NULL) {
                            SET(val);
                        } else {
                            SET_IF_KEY(val) {
                                return false;
                            }
                        }
                    }

                    return true;
                }

                void deserialize(JSON_Value *_doc_) {
                    JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                    {
                        GET(val);
                    }
                }

                ~Object() {
                }

            public:
                T *get_val() {
                    return val;
                }

                const T *get_val() const {
                    return val;
                }

                void set_val(T *val) {
                    this->val = val;
                }

            private:
                T *val;
            };
        }
    }
}


#endif //CRMS_ON_VXWORKS_OBJECT_H