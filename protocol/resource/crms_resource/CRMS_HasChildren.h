//
// Created by nini on 9/27/17.
//

#ifndef CRMS_ON_VXWORKS_CRMS_HASCHILDREN_H
#define CRMS_ON_VXWORKS_CRMS_HASCHILDREN_H

#include "CRMS_ChildResourceRef.h"
#include "CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_HasChildren : public CRMS_Resource {
                public:
                    CRMS_HasChildren() : acid(1) {
                    }

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        SERIALIZE_SUPER_CLASS(CRMS_Resource);

                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(children);
                            } else {
                                SET_IF_KEY(children) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        DESERIALIZE_SUPER_CLASS(CRMS_Resource);

                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(children);
                        }
                    }

                    ~CRMS_HasChildren() {
                    }

                    void add_child_ref(const CRMS_ChildResourceRef &child_ref) {
                        children.push_back(child_ref);
                    }

                DEFINE_MEMBER(children, _LIST < CRMS_ChildResourceRef >)

                DEFINE_MEMBER(acid, _UINT)//automatic children id
                };
            }
        }
    }
}


#endif //CRMS_ON_VXWORKS_CRMS_HASCHILDREN_H
