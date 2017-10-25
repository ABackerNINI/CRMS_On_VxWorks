#pragma once

#ifndef _CRMS_RESOURCE_RSP_H_
#define _CRMS_RESOURCE_RSP_H_

#include "../DEF.h"

#include "../../../utility/DateTime/DateTime.h"
#include "CRMS_PrimitiveContentType.h"
#include "../crms_enumeration/CRMS_ResponseStatusCodeType.h"
#include "CRMS_Req.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {

                class CRMS_Rsp {
                public:
                    CRMS_Rsp() {
                    }

                    CRMS_Rsp(const CRMS_Req *crms_req,enumeration::CRMS_ResponseStatusCodeType rsc){
                        this->to = crms_req->get_fr();
                        this->fr = crms_req->get_to();
                        this->rqi = crms_req->get_rqi();
                        this->rsc = rsc;
                    }

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(to);
//                                SET(fr);
//                                SET(rqi);
//                                SET(pc);
//                                SET(ot);
//                                SET(rset);
//                                SET(rsc);
//                            } else {
//                                SET_IF_KEY(to) SET_IF_KEY(fr) SET_IF_KEY(rqi) SET_IF_KEY(pc) SET_IF_KEY(ot) SET_IF_KEY(
//                                        rset) SET_IF_KEY(rsc) {
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
//                            GET(to);
//                            GET(fr);
//                            GET(rqi);
//                            GET(pc);
//                            GET(ot);
//                            GET(rset);
//                            GET(rsc);
//                        }
//                    }

                    ~CRMS_Rsp() {
                    }

                DEFINE_MEMBER(to, _STRING)

                DEFINE_MEMBER(fr, _STRING)

                DEFINE_MEMBER(rqi, _STRING)

                DEFINE_MEMBER(pc, CRMS_PrimitiveContentType<void>)

                DEFINE_MEMBER(ot, _DATETIME)

                DEFINE_MEMBER(rset, _DATETIME)

                DEFINE_MEMBER(rsc, enumeration::CRMS_ResponseStatusCodeType)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RSP_H_