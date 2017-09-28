//
// Created by nini on 9/27/17.
//

#ifndef CRMS_ON_VXWORKS_CRMS_REQ_RSP_H
#define CRMS_ON_VXWORKS_CRMS_REQ_RSP_H

#include "../DEF.h"
#include "CRMS_Resource.h"
#include "CRMS_Req.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                template<typename T>
                class CRMS_Req_Rsp {
                public:
                    CRMS_Req_Rsp() : ty(DEFAULT_VALUE_INT), val(NULL), retrieve_query(NULL) {}

                    CRMS_Req_Rsp(int ty, T *val) : ty(ty), val(val), retrieve_query(NULL) {}

                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
                        {
                            if (retrieve_query == NULL || retrieve_query->ty == CRMS_Req::NON) {//NON
                                SET(ty);
                                SET(val);
                            } else if (retrieve_query->ty == CRMS_Req::PR) {//PR
                                if (retrieve_query->retrieve_query_pr.ty == CRMS_Req::IN) {
                                    SET(ty);

                                    if (!is_default_value(val)) {
                                        char *keys = strdup(retrieve_query->retrieve_query_pr.pr);
                                        JSON_Value *doc = serialize_to_doc(*val, keys);
                                        json_object_set_value(_root_obj_, "val", doc);
                                        delete[]keys;
                                    }
                                } else if (retrieve_query->retrieve_query_pr.ty == CRMS_Req::EX) {
                                    SET(ty);
                                    SET(val);

                                    JSON_Value *val_val = json_object_get_value(_root_obj_, "val");
                                    JSON_Object *val_obj = json_value_get_object(val_val);

                                    bool cut = true;
                                    char *keys = strdup(retrieve_query->retrieve_query_pr.pr);
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
                            } else if (retrieve_query->ty == CRMS_Req::PG) {//PG

                            } else if (retrieve_query->ty == CRMS_Req::SR) {//SR

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

                public:
                    CRMS_Req::retrieve_query_t *retrieve_query;

                    void set_ty(int ty) {
                        this->ty = ty;
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
                };
            }
        }
    }
}

#endif //CRMS_ON_VXWORKS_CRMS_REQ_RSP_H
