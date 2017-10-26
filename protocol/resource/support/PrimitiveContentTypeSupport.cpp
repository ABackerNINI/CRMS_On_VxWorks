//
// Created by nini on 10/26/17.
//

#include <assert.h>
#include "PrimitiveContentTypeSupport.h"

#include "../crms_resource/CRMS_RootResource.h"
#include "../crms_resource/CRMS_ResourceObject.h"
#include "../crms_resource/CRMS_Attribute.h"
#include "../crms_resource/CRMS_Command.h"
#include "../crms_resource/CRMS_DataTable.h"
#include "../crms_resource/CRMS_Node.h"
#include "../crms_resource/CRMS_Group.h"
#include "../crms_common/CRMS_PaginationRetrieve.h"
#include "../crms_common/CRMS_PartialRetrieve.h"
#include "../crms_common/CRMS_SubscriptionRetrieve.h"
#include "../crms_common/CRMS_Notification.h"
#include "../crms_common/CRMS_AggregatedNotification.h"
#include "../crms_common/CRMS_AggregatedResponse.h"

char *serialize_1(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_RootResource> *) pc);
}

char *serialize_2(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_ResourceObject> *) pc);
}

char *serialize_3(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Attribute> *) pc);
}

char *serialize_4(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Command> *) pc);
}

char *serialize_5(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_DataTable> *) pc);
}

char *serialize_6(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Node> *) pc);
}

char *serialize_7(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Group> *) pc);
}

char *serialize_8(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_Subscription> *) pc);
}

char *serialize_9(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_ChildResourceRef> *) pc);
}

char *serialize_10(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
//    return serialize(
//            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_PaginationRetrieve> *) pc);
}

char *serialize_11(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
//    return serialize(
//            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_PartialRetrieve> *) pc);
}

char *serialize_12(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
//    return serialize(
//            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_SubscriptionRetrieve> *) pc);
}

char *serialize_13(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
//    return serialize(
//            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_Notification> *) pc);
}

char *serialize_14(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
//    return serialize(
//            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_AggregatedNotification> *) pc);
}

char *serialize_15(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
//    return serialize(
//            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_AggregatedResponse> *) pc);
}

char *serialize_16(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    return serialize(
            *(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<std::string> *) pc);
}

char *serialize_pc(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc) {
    typedef char *(*serialize_func)(const crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *);
    static serialize_func funcs[] = {
            NULL,
            serialize_1,
            serialize_2,
            serialize_3,
            serialize_4,
            serialize_5,
            serialize_6,
            serialize_7,
            serialize_8,
            serialize_9,
            serialize_10,
            serialize_11,
            serialize_12,
            serialize_13,
            serialize_14,
            serialize_15,
            serialize_16
    };

    if (pc->get_ty() > 0 && pc->get_ty() < 17) {
        return funcs[pc->get_ty()](pc);
    }

    assert(false);

    return NULL;
}

int deserialize_1(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_RootResource> *) pc,
            cstr);

    return 0;
}

int deserialize_2(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_ResourceObject> *) pc,
            cstr);

    return 0;
}

int deserialize_3(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Attribute> *) pc,
            cstr);

    return 0;
}

int deserialize_4(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Command> *) pc,
            cstr);

    return 0;
}

int deserialize_5(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_DataTable> *) pc,
            cstr);

    return 0;
}

int deserialize_6(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Node> *) pc,
            cstr);

    return 0;
}

int deserialize_7(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::resource::CRMS_Group> *) pc,
            cstr);

    return 0;
}


int deserialize_8(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_Subscription> *) pc,
            cstr);

    return 0;
}

int deserialize_9(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_ChildResourceRef> *) pc,
            cstr);

    return 0;
}

int deserialize_10(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
//    deserialize(
//            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_PaginationRetrieve> *) pc,
//            cstr);

    return 0;
}

int deserialize_11(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
//    deserialize(
//            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_PartialRetrieve> *) pc,
//            cstr);

    return 0;
}

int deserialize_12(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
//    deserialize(
//            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_SubscriptionRetrieve> *) pc,
//            cstr);

    return 0;
}

int deserialize_13(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
//    deserialize(
//            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_Notification> *) pc,
//            cstr);

    return 0;
}

int deserialize_14(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
//    deserialize(
//            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_AggregatedNotification> *) pc,
//            cstr);

    return 0;
}

int deserialize_15(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
//    deserialize(
//            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<crms::protocol::resource::common::CRMS_AggregatedResponse> *) pc,
//            cstr);

    return 0;
}

int deserialize_16(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, const char *cstr) {
    deserialize(
            (crms::protocol::resource::primitive::CRMS_PrimitiveContentType<std::string> *) pc, cstr);

    return 0;
}

int deserialize_pc(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *pc, int ty, const char *cstr) {
    typedef int (*deserialize_func)(crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> *, const char *);

    static const deserialize_func funcs[] = {
            NULL,
            deserialize_1,
            deserialize_2,
            deserialize_3,
            deserialize_4,
            deserialize_5,
            deserialize_6,
            deserialize_7,
            deserialize_8,
            deserialize_9,
            deserialize_10,
            deserialize_11,
            deserialize_12,
            deserialize_13,
            deserialize_14,
            deserialize_15,
            deserialize_16
    };

    if (ty > 0 && ty < 17) {
        return funcs[ty](pc, cstr);
    }

    assert(false);

    return -1;
}