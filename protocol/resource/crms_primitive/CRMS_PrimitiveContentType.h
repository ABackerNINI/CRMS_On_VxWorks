#pragma once

#ifndef _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_
#define _CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_

#include "../ResourceBase.h"
#include "../crms_common/CRMS_RetrieveQuery.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace primitive {

                template<typename T = void>
                class CRMS_PrimitiveContentType {
                public:
                    CRMS_PrimitiveContentType() : ty(NJSON_DEFAULT_VALUE_INT), val(NULL) {}

                    CRMS_PrimitiveContentType(int ty, T *val) : ty(ty), val(val) {}

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (rq.get_ty() == crms::protocol::resource::common::CRMS_RetrieveQueryType::None) {//NON
//                                SET(ty);
//                                SET(val);
//                            } else if (rq.get_ty() ==
//                                       crms::protocol::resource::common::CRMS_RetrieveQueryType::PartialRetrieve) {//PR
//                                if (rq.get_val().get_pr().get_ty() ==
//                                    crms::protocol::resource::common::CRMS_PartialRetrieveType::In) {
//                                    SET(ty);
//
//                                    if (!is_default_value(val)) {
//                                        char *keys = strdup(rq.get_val().get_pr().get_val());
//                                        JSON_Value *doc = serialize_to_doc(*val, keys);
//                                        json_object_set_value(_root_obj_, "val", doc);
//                                        delete[]keys;
//                                    }
//                                } else if (rq.get_val().get_pr().get_ty() ==
//                                           crms::protocol::resource::common::CRMS_PartialRetrieveType::Ex) {
//                                    SET(ty);
//                                    SET(val);
//
//                                    JSON_Value *val_val = json_object_get_value(_root_obj_, "val");
//                                    JSON_Object *val_obj = json_value_get_object(val_val);
//
//                                    bool cut = true;
//                                    char *keys = strdup(rq.get_val().get_pr().get_val());
//                                    int n = cut_string(keys, ',');
//                                    if (n > 0) {
//                                        for (char *key = keys; n > 0; ++key) {
//                                            if (*key == '\0') {
//                                                cut = true;
//                                            } else if (cut) {
//                                                json_object_remove(val_obj, key);
//                                                --n;
//                                                cut = false;
//                                            }
//                                        }
//                                    }
//                                    delete[]keys;
//                                } else {
//                                    ////TODO:handle error
//                                }
//                            } else if (rq.get_ty() ==
//                                       crms::protocol::resource::common::CRMS_RetrieveQueryType::PaginationRetrieve) {//PG
//
//                            } else if (rq.get_ty() ==
//                                       crms::protocol::resource::common::CRMS_RetrieveQueryType::SubscriptionRetrieve) {//SR
//
//                            }
//                        }
//
//                        return true;
//                    }
//
//                    void deserialize(JSON_Value *_doc_) {
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            GET(ty);
//                            GET(val);
//                        }
//                    }

                    ~CRMS_PrimitiveContentType() {
//                        if (val)delete[] val;////mark:may raise some problems.
                    }

                DEFINE_MEMBER(ty, _INT) //CRMS_ResourceType

                DEFINE_POINTER_MEMBER(val, T *)

                DEFINE_MEMBER(rq, crms::protocol::resource::common::CRMS_RetrieveQuery)

//                DEFINE_MEMBER(val, Object)
                };

                template<>
                class CRMS_PrimitiveContentType<_STRING> {
                public:
                    CRMS_PrimitiveContentType() : ty(NJSON_DEFAULT_VALUE_INT), val(NULL) {}

                    CRMS_PrimitiveContentType(int ty, _STRING *val) : ty(ty), val(val) {}

//                    bool serialize(JSON_Value *_doc_, const char *_key_ = NULL) const {
//                        JSON_Object *_root_obj_ = json_value_get_object(_doc_);
//                        {
//                            if (_key_ == NULL) {
//                                SET(ty);
//                                SET(val);
//                            } else {
//                                SET_IF_KEY(ty) SET_IF_KEY(val) {
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
//                            GET(ty);
//                            GET(val);
//                        }
//                    }

                    ~CRMS_PrimitiveContentType() {
                    }

                DEFINE_MEMBER(ty, _INT) //CRMS_ResourceType

                DEFINE_POINTER_MEMBER(val, _STRING *)

                DEFINE_MEMBER(rq, crms::protocol::resource::common::CRMS_RetrieveQuery)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_PRIMITIVE_CONTENT_TYPE_H_