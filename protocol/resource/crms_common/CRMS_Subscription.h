#pragma once

#ifndef _CRMS_RESOURCE_SUBSCRIPTION_H_
#define _CRMS_RESOURCE_SUBSCRIPTION_H_

#include "../DEF.h"
#include "CRMS_BatchNotify.h"
#include "../crms_enumeration/CRMS_SubscriptionEventType.h"
#include "../crms_enumeration/CRMS_NotificationContentType.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace common {

                class CRMS_Subscription {
                public:
                    CRMS_Subscription() :
                            id(NJSON_DEFAULT_VALUE_INT),
                            exc(NJSON_DEFAULT_VALUE_INT) {
                        memset(&ln, -1, sizeof(bool));
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(ri);
//                                SET(id);
//                                SET(ct);
//                                SET(ety);
//                                SET(exc);
//                                SET(nu);
//                                SET(nfu);
//                                SET(gi);
//                                SET(bn);
//                                SET(ln);
//                                SET(nct);
//                                SET(cr);
//                                SET(su);
//                            } else {
//                                SET_IF_KEY(ri) SET_IF_KEY(id) SET_IF_KEY(ct)
//                                    // SET_IF_KEY(ety)
//                                SET_IF_KEY(exc) SET_IF_KEY(nu) SET_IF_KEY(nfu) SET_IF_KEY(gi) SET_IF_KEY(bn) SET_IF_KEY(
//                                        ln)
//                                    // SET_IF_KEY(nct)
//                                SET_IF_KEY(cr) SET_IF_KEY(su) {
//                                    return false;
//                                }
//                            }
//                        }
//
//                        return true;
//                    }
//
//                    void deserialize(JSON_Value *_doc_) {
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            GET(ri);
//                            GET(id);
//                            GET(ct);
//                            GET(ety);
//                            GET(exc);
//                            GET(nu);
//                            GET(nfu);
//                            GET(gi);
//                            GET(bn);
//                            GET(ln);
//                            GET(nct);
//                            GET(cr);
//                            GET(su);
//                        }
//                    }

                    ~CRMS_Subscription() {
                    }

                DEFINE_MEMBER(ri, _STRING)

                DEFINE_MEMBER(id, _INT)

                DEFINE_MEMBER(ct, _DATETIME)

                DEFINE_MEMBER(ety, std::list<enumeration::CRMS_SubscriptionEventType>)

                DEFINE_MEMBER(exc, _INT)

                DEFINE_MEMBER(nu, _LIST < _STRING >)

                DEFINE_MEMBER(nfu, _LIST < _STRING >)

                DEFINE_MEMBER(gi, _STRING)

                DEFINE_MEMBER(bn, CRMS_BatchNotify)

                DEFINE_MEMBER(ln, _BOOL)

                DEFINE_MEMBER(nct, enumeration::CRMS_NotificationContentType)

                DEFINE_MEMBER(cr, _STRING)

                DEFINE_MEMBER(su, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_SUBSCRIPTION_H_