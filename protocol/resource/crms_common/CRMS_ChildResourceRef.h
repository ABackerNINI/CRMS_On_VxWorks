#pragma once

#ifndef _CRMS_RESOURCE_CHILD_RESOURCE_REF_H_
#define _CRMS_RESOURCE_CHILD_RESOURCE_REF_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_ChildResourceRef {
                public:
                    CRMS_ChildResourceRef() :
                            ty(DEFAULT_VALUE_INT) {
                    }

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(v);
                                SET(ty);
                                SET(rn);
                            } else {
                                SET_IF_KEY(v) SET_IF_KEY(ty) SET_IF_KEY(rn) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(v);
                            GET(ty);
                            GET(rn);
                        }
                    }

                    ~CRMS_ChildResourceRef() {
                    }

                private:
                DEFINE_MEMBER(v, _STRING)

                DEFINE_MEMBER(ty, _INT)

                DEFINE_MEMBER(rn, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_CHILD_RESOURCE_REF_H_