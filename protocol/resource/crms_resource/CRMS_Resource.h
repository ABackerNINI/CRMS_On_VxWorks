#pragma once

#ifndef _CRMS_RESOURCE_RESOURCE_H_
#define _CRMS_RESOURCE_RESOURCE_H_

#include "../DEF.h"

#include "../../../utility/DateTime/DateTime.h"
#include "../crms_attribute/CRMS_Subscription.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_Resource {
                public:
                    CRMS_Resource() :
                            ty(DEFAULT_VALUE_INT) {
                    }

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(ri);
                                SET(pa);
                                SET(rn);
                                SET(ty);
                                SET(ct);
                                SET(lt);
                                SET(onto);
                                SET(subs);
                            } else {
                                SET_IF_KEY(ri) SET_IF_KEY(pa) SET_IF_KEY(rn) SET_IF_KEY(ty) SET_IF_KEY(ct) SET_IF_KEY(
                                        lt) SET_IF_KEY(onto) SET_IF_KEY(subs) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(ri);
                            GET(pa);
                            GET(rn);
                            GET(ty);
                            GET(ct);
                            GET(lt);
                            GET(onto);
                            GET(subs);
                        }
                    }

                    ~CRMS_Resource() {}

                DEFINE_MEMBER(ri, _STRING)

                DEFINE_MEMBER(pa, _STRING)

                DEFINE_MEMBER(rn, _STRING)

                DEFINE_MEMBER(ty, _INT)

                DEFINE_MEMBER(ct, _DATETIME)

                DEFINE_MEMBER(lt, _DATETIME)

                DEFINE_MEMBER(onto, _STRING)

                DEFINE_MEMBER(subs, _MAP < _STRING, attribute::CRMS_Subscription >)
                };
            }
        }
    }
}
#endif//_CRMS_RESOURCE_RESOURCE_H_