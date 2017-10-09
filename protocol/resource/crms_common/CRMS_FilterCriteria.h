#pragma once

#ifndef _CRMS_RESOURCE_ATTRIBUTE_FILTER_CRITERIA_H_
#define _CRMS_RESOURCE_ATTRIBUTE_FILTER_CRITERIA_H_

#include "../DEF.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace attribute {

                class CRMS_FilterCriteria {
                public:
                    CRMS_FilterCriteria() :
                            sts(DEFAULT_VALUE_INT),
                            stb(DEFAULT_VALUE_INT),
                            sza(DEFAULT_VALUE_INT),
                            szb(DEFAULT_VALUE_INT),
                            lim(DEFAULT_VALUE_INT) {
                    }

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(crb);
                                SET(cra);
                                SET(ms);
                                SET(us);
                                SET(sts);
                                SET(stb);
                                SET(exb);
                                SET(exa);
                                SET(lbl);
                                SET(rty);
                                SET(sza);
                                SET(szb);
                                SET(cty);
                                SET(lim);
                                SET(fu);
                            } else {
                                SET_IF_KEY(crb) SET_IF_KEY(cra) SET_IF_KEY(ms) SET_IF_KEY(us) SET_IF_KEY(
                                        sts) SET_IF_KEY(
                                        stb) SET_IF_KEY(exb) SET_IF_KEY(exa) SET_IF_KEY(lbl) SET_IF_KEY(rty) SET_IF_KEY(
                                        sza) SET_IF_KEY(szb) SET_IF_KEY(cty) SET_IF_KEY(lim) SET_IF_KEY(fu) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(crb);
                            GET(cra);
                            GET(ms);
                            GET(us);
                            GET(sts);
                            GET(stb);
                            GET(exb);
                            GET(exa);
                            GET(lbl);
                            GET(rty);
                            GET(sza);
                            GET(szb);
                            GET(cty);
                            GET(lim);
                            GET(fu);
                        }
                    }

                    ~CRMS_FilterCriteria() {
                    }

                DEFINE_MEMBER(crb, _DATETIME)

                DEFINE_MEMBER(cra, _DATETIME)

                DEFINE_MEMBER(ms, _DATETIME)

                DEFINE_MEMBER(us, _DATETIME)

                DEFINE_MEMBER(sts, _INT)

                DEFINE_MEMBER(stb, _INT)

                DEFINE_MEMBER(exb, _DATETIME)

                DEFINE_MEMBER(exa, _DATETIME)

                DEFINE_MEMBER(lbl, _LIST < _STRING >)

                DEFINE_MEMBER(rty, _LIST < _INT >)

                DEFINE_MEMBER(sza, _INT)

                DEFINE_MEMBER(szb, _INT)

                DEFINE_MEMBER(cty, _LIST < _STRING >)

                DEFINE_MEMBER(lim, _INT)

                DEFINE_MEMBER(fu, _STRING)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_ATTRIBUTE_FILTER_CRITERIA_H_