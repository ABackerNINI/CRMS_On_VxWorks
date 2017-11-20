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
                    CRMS_HasChildren() :
                            CRMS_Resource(),
                            acid(1) {
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
