#pragma once

#ifndef _CRMS_RESOURCE_REQ_H_
#define _CRMS_RESOURCE_REQ_H_

#include "../DEF.h"

#include "../../../utility/DateTime/DateTime.h"
#include "CRMS_PrimitiveContentType.h"
#include "../crms_enumeration/CRMS_Operation.h"
#include "../crms_enumeration/CRMS_ResultContent.h"
#include "../crms_enumeration/CRMS_SubscriptionOperation.h"
#include "../crms_attribute/CRMS_FilterCriteria.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {

                class CRMS_Req {
                public:
                    CRMS_Req() :
                            ty(DEFAULT_VALUE_INT) {
                        memset(&proxy, -1, sizeof(proxy));
                    }

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(op);
                                SET(to);
                                SET(fr);
                                SET(rqi);
                                SET(ty);
                                SET(rn);
                                SET(pc);
                                SET(ot);
                                SET(rqet);
                                SET(rset);
                                SET(oet);
                                SET(rcn);
                                SET(da);
                                SET(gid);
                                SET(fc);
                                SET(so);
                                SET(proxy);
                            } else {
                                SET_IF_KEY(op) SET_IF_KEY(to) SET_IF_KEY(fr) SET_IF_KEY(rqi) SET_IF_KEY(ty) SET_IF_KEY(
                                        rn) SET_IF_KEY(pc) SET_IF_KEY(ot) SET_IF_KEY(rqet) SET_IF_KEY(rset) SET_IF_KEY(
                                        oet) SET_IF_KEY(rcn) SET_IF_KEY(da) SET_IF_KEY(gid) SET_IF_KEY(fc) SET_IF_KEY(
                                        so) SET_IF_KEY(proxy) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(op);
                            GET(to);
                            GET(fr);
                            GET(rqi);
                            GET(ty);
                            GET(rn);
                            GET(pc);
                            GET(ot);
                            GET(rqet);
                            GET(rset);
                            GET(oet);
                            GET(rcn);
                            GET(da);
                            GET(gid);
                            GET(fc);
                            GET(so);
                            GET(proxy);
                        }
                    }

                    ~CRMS_Req() {
                    }

                public:
                    enum retrieve_query_type {
                        NON,
                        PR,
                        PG,
                        SR
                    };

                    enum retrieve_query_pr_type {
                        IN,
                        EX
                    };

                    struct retrieve_query_t {
                        retrieve_query_type ty;

                        union {
                            struct {
                                retrieve_query_pr_type ty;
                                const char *pr;
                            } retrieve_query_pr;

                            struct {
                                int offset;
                                int len;
                            } retrieve_query_pg;

                            struct {
                                const char *id;
                            } retrieve_query_sr;
                        };
                    } retrieve_query;

                public:

                DEFINE_MEMBER(op, enumeration::CRMS_Operation)

                DEFINE_MEMBER(to, _STRING)

                DEFINE_MEMBER(fr, _STRING)

                DEFINE_MEMBER(rqi, _STRING)

                DEFINE_MEMBER(ty, _INT)

                DEFINE_MEMBER(rn, _STRING)

                DEFINE_MEMBER(pc, CRMS_PrimitiveContentType)

                DEFINE_MEMBER(ot, _DATETIME)

                DEFINE_MEMBER(rqet, _DATETIME)

                DEFINE_MEMBER(rset, _DATETIME)

                DEFINE_MEMBER(oet, _DATETIME)

                DEFINE_MEMBER(rcn, enumeration::CRMS_ResultContent)

                DEFINE_MEMBER(da, _STRING)

                DEFINE_MEMBER(gid, _STRING)

                DEFINE_MEMBER(fc, attribute::CRMS_FilterCriteria)

                DEFINE_MEMBER(so, enumeration::CRMS_SubscriptionOperation)

                DEFINE_MEMBER(proxy, _BOOL)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_REQ_H_