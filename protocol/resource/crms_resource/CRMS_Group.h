#pragma once

#ifndef _CRMS_RESOURCE_GROUP_H_
#define _CRMS_RESOURCE_GROUP_H_

#include "../DEF.h"
#include "../crms_enumeration/CRMS_MemberType.h"
#include "../crms_enumeration/CRMS_ConsistencyStrategy.h"
#include "CRMS_Resource.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Group : public CRMS_Resource {
                public:
                    CRMS_Group() :
                            cnm(NJSON_DEFAULT_VALUE_INT),
                            mnm(NJSON_DEFAULT_VALUE_INT) {
                        memset(&mtv, -1, sizeof(mtv));
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        SERIALIZE_SUPER_CLASS(CRMS_Resource);
//
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(mt);
//                                SET(cnm);
//                                SET(mnm);
//                                SET(mid);
//                                SET(mtv);
//                                SET(csy);
//                                SET(gn);
//                                SET(cr);
//                            } else {
//                                SET_IF_KEY(mt) SET_IF_KEY(cnm) SET_IF_KEY(mnm) SET_IF_KEY(mid) SET_IF_KEY(
//                                        mtv) SET_IF_KEY(
//                                        csy) SET_IF_KEY(gn) SET_IF_KEY(cr) {
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
//                            GET(mt);
//                            GET(cnm);
//                            GET(mnm);
//                            GET(mid);
//                            GET(mtv);
//                            GET(csy);
//                            GET(gn);
//                            GET(cr);
//                        }
//                    }

                    ~CRMS_Group() {
                    }

                DEFINE_MEMBER(mt, enumeration::CRMS_MemberType)

                DEFINE_MEMBER(cnm, _INT)

                DEFINE_MEMBER(mnm, _INT)

                DEFINE_MEMBER(mid, _LIST < _STRING >)

                DEFINE_MEMBER(mtv, _BOOL)

                DEFINE_MEMBER(csy, enumeration::CRMS_ConsistencyStrategy)

                DEFINE_MEMBER(gn, _STRING)

                DEFINE_MEMBER(cr, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_GROUP_H_