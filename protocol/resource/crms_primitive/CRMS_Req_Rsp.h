//
// Created by nini on 9/27/17.
//

#ifndef CRMS_ON_VXWORKS_CRMS_REQ_RSP_H
#define CRMS_ON_VXWORKS_CRMS_REQ_RSP_H

#include "../ResourceBase.h"
#include "../crms_resource/CRMS_Resource.h"
#include "CRMS_Req.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {
                template<typename T>
                class CRMS_Req_Rsp {
                public:
                    CRMS_Req_Rsp() : ty(DEFAULT_VALUE_INT), val(NULL), rq(NULL) {}

                    CRMS_Req_Rsp(int ty, T *val) : ty(ty), val(val), rq(NULL) {}

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (rq == NULL || rq->ty.get_val() == enumeration::CRMS_RetrieveQueryType::None) {//NON
                                SET(ty);
                                SET(val);
                            } else if (rq->ty.get_val() == enumeration::CRMS_RetrieveQueryType::PartialRetrieve) {//PR
                                if (rq->rq.pr.ty.get_val() == enumeration::CRMS_PartialRetrieveType::In) {
                                    SET(ty);

                                    if (!is_default_value(val)) {
                                        char *keys = strdup(rq->rq.pr.pr.in);
                                        JSON_Value *doc = serialize_to_doc(*val, keys);
                                        json_object_set_value(_root_obj_, "val", doc);
                                        delete[]keys;
                                    }
                                } else if (rq->rq.pr.ty.get_val() == enumeration::CRMS_PartialRetrieveType::Ex) {
                                    SET(ty);
                                    SET(val);

                                    JSON_Value *val_val = json_object_get_value(_root_obj_, "val");
                                    JSON_Object *val_obj = json_value_get_object(val_val);

                                    bool cut = true;
                                    char *keys = strdup(rq->rq.pr.pr.ex);
                                    int n = cut_string(keys, ',');
                                    if (n > 0) {
                                        for (char *key = keys; n > 0; ++key) {
                                            if (*key == '\0') {
                                                cut = true;
                                            } else if (cut) {
                                                json_object_remove(val_obj, key);
                                                --n;
                                                cut = false;
                                            }
                                        }
                                    }
                                    delete[]keys;
                                } else {
                                    ////TODO:handle error
                                }
                            } else if (rq->ty.get_val() == enumeration::CRMS_RetrieveQueryType::Pagination) {//PG

                            } else if (rq->ty.get_val() ==
                                       enumeration::CRMS_RetrieveQueryType::SubscriptionRetrieve) {//SR

                            }
                        }

                        return true;
                    }

                    void deserialize(JSON_Value *_doc_) {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            GET(ty);
                            GET(val);
                        }
                    }

                    ~CRMS_Req_Rsp() {
                    }

                private:
                    int ty;
                    T *val;

                    const common::CRMS_RetrieveQuery *rq;

                public:
                    void set_ty(int ty) {
                        this->ty = ty;
                    }

                    int get_ty() const {
                        return ty;
                    }

                    void set_val(T *val) {
                        this->val = val;
                    }

                    T *get_val() {
                        return val;
                    }

                    const T *get_val() const {
                        return val;
                    }

                    void set_rq(const common::CRMS_RetrieveQuery *rq) {
                        this->rq = rq;
                    }

                    const common::CRMS_RetrieveQuery *get_rq() const {
                        return rq;
                    }
                };

                template<>
                class CRMS_Req_Rsp<_STRING> {
                public:
                    CRMS_Req_Rsp() : ty(DEFAULT_VALUE_INT), val(NULL) {}

                    CRMS_Req_Rsp(int ty, const _STRING *val) : ty(ty), val(val) {}

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (_key_ == NULL) {
                                SET(ty);
                                SET(val);
                            } else {
                                SET_IF_KEY(ty) SET_IF_KEY(val) {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }

//                    void deserialize(JSON_Value *_doc_) {
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            GET(ty);
//                            GET(val);
//                        }
//                    }

                    ~CRMS_Req_Rsp() {
                    }

                private:
                    int ty;
                    const _STRING *val;

                public:
                    void set_ty(int ty) {
                        this->ty = ty;
                    }

                    int get_ty() const {
                        return ty;
                    }

                    void set_val(const _STRING *val) {
                        this->val = val;
                    }

//                    _STRING *get_val() {
//                        return val;
//                    }

                    const _STRING *get_val() const {
                        return val;
                    }
                };
            }
        }
    }
}

#endif //CRMS_ON_VXWORKS_CRMS_REQ_RSP_H
