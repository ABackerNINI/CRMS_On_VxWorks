#pragma once

#ifndef _CRMS_RESOURCE_RESPONSE_H_
#define _CRMS_RESOURCE_RESPONSE_H_

#include "../ResourceBase.h"
#include "../crms_enumeration/CRMS_ResponseStatusCodeType.h"
#include "../crms_enumeration/CRMS_ResourceType.h"
#include "CRMS_PrimitiveContentType.h"
#include "CRMS_Req.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {

                class CRMS_Rsp {
                public:
                    CRMS_Rsp() {
                    }

                    CRMS_Rsp(const CRMS_Req *crms_req, enumeration::CRMS_ResponseStatusCodeType rsc) {
                        this->to = crms_req->get_fr();
                        this->fr = crms_req->get_to();
                        this->rqi = crms_req->get_rqi();
                        this->rsc = rsc;

                        this->pc.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::string);
                        this->pc.set_val(
                                (void *) &crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::get_msg(
                                        rsc.get_val()));
                    }

                DEFINE_MEMBER(to, _STRING)

                DEFINE_MEMBER(fr, _STRING)

                DEFINE_MEMBER(rqi, _STRING)

                DEFINE_MEMBER(pc, CRMS_PrimitiveContentType < void >)

                DEFINE_MEMBER(ot, _DATETIME)

                DEFINE_MEMBER(rset, _DATETIME)

                DEFINE_MEMBER(rsc, enumeration::CRMS_ResponseStatusCodeType)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RESPONSE_H_