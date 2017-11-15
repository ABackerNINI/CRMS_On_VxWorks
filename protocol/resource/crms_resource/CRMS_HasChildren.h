#pragma once

#ifndef _CRMS_RESOURCE_HAS_CHILDREN_H
#define _CRMS_RESOURCE_HAS_CHILDREN_H

#include "../ResourceBase.h"
#include "../crms_common/CRMS_ChildResourceRef.h"
#include "CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_HasChildren : public CRMS_Resource {
                public:
                    CRMS_HasChildren() : acid(1) {
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        SERIALIZE_SUPER_CLASS(CRMS_Resource);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(ch);
//                            } else {
//                                SET_IF_KEY(ch) {
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
//                            GET(ch);
//                        }
//                    }

                    ~CRMS_HasChildren() {
                    }

                    void add_child_ref(const crms::protocol::resource::common::CRMS_ChildResourceRef &child_ref) {
                        ch.push_back(child_ref);
                    }

                    void remove_child_ref(const std::string &child_ri) {
                        for (_LIST<crms::protocol::resource::common::CRMS_ChildResourceRef>::iterator it = ch.begin();
                             it != ch.end(); ++it) {
                            if (it->get_v() == child_ri) {
                                ch.erase(it);
                                break;
                            }
                        }
                    }

                DEFINE_MEMBER(ch, _LIST < crms::protocol::resource::common::CRMS_ChildResourceRef >)

                DEFINE_MEMBER(acid, _UINT)//automatic children id
                };
            }
        }
    }
}

#endif //_CRMS_RESOURCE_HAS_CHILDREN_H
