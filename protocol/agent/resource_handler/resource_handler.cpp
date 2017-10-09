//
// Created by nini on 9/27/17.
//

#include "resource_handler.h"
#include "node_handler.h"
#include "root_resource_handler.h"
#include "resource_object_handler.h"
#include "attribute_handler.h"
#include "command_handler.h"
#include "data_table_handler.h"
#include "group_handler.h"
#include "remote_resource_object_handler.h"
#include "remote_attribute_handler.h"
#include "remote_command_handler.h"

//#define HANDLE_CRUD(HANDLER, REQ, RSP, RES)                                                                \
//    switch (_Req->get_op().get_val()){                                                                  \
//        case crms::protocol::resource::enumeration::CRMS_Operation::Create:                             \
//            HANDLER::Create(REQ,RSP,RES);                                                               \
//            break;                                                                                      \
//        case crms::protocol::resource::enumeration::CRMS_Operation::Retrieve:                           \
//            HANDLER::Retrieve(REQ,RSP,RES);                                                             \
//            break;                                                                                      \
//        case crms::protocol::resource::enumeration::CRMS_Operation::Update:                             \
//            HANDLER::Update(REQ,RSP,RES);                                                               \
//            break;                                                                                      \
//        case crms::protocol::resource::enumeration::CRMS_Operation::Delete:                             \
//            HANDLER::Delete(REQ,RSP,RES);                                                               \
//            break;                                                                                      \
//    }
//
//
//template<typename T>
//void handle_crud(T *resource_handler, crms::protocol::resource::primitive::CRMS_Req *_Req,
//                 crms::protocol::resource::primitive::CRMS_Rsp *_Rsp,
//                 crms::protocol::resource::resource::CRMS_Resource *_Res) {
//    switch (_Req->get_op().get_val()) {
//        case crms::protocol::resource::enumeration::CRMS_Operation::Create:
//            resource_handler->Create(_Req, _Rsp, _Res);
//            break;
//        case crms::protocol::resource::enumeration::CRMS_Operation::Retrieve:
//            resource_handler->Retrieve(_Req, _Rsp, _Res);
//            break;
//        case crms::protocol::resource::enumeration::CRMS_Operation::Update:
//            resource_handler->Update(_Req, _Rsp, _Res);
//            break;
//        case crms::protocol::resource::enumeration::CRMS_Operation::Delete:
//            resource_handler->Delete(_Req, _Rsp, _Res);
//            break;
//        default:
//            break;
//    }
//}

void
crms::protocol::agent::resource_handler::resource_handler::handle_crud(
        crms::protocol::resource::primitive::CRMS_Req *_Req,
        crms::protocol::resource::primitive::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    typedef void (*handler_crud_type)(crms::protocol::resource::primitive::CRMS_Req *_Req,
                                      crms::protocol::resource::primitive::CRMS_Rsp *_Rsp,
                                      crms::protocol::resource::resource::CRMS_Resource *_Res);
    static handler_crud_type handlers[] = {
            root_resource_handler::Create,
            root_resource_handler::Retrieve,
            root_resource_handler::Update,
            root_resource_handler::Delete,
            resource_object_handler::Create,
            resource_object_handler::Retrieve,
            resource_object_handler::Update,
            resource_object_handler::Delete,
            attribute_handler::Create,
            attribute_handler::Retrieve,
            attribute_handler::Update,
            attribute_handler::Delete,
            command_handler::Create,
            command_handler::Retrieve,
            command_handler::Update,
            command_handler::Delete,
            node_handler::Create,
            node_handler::Retrieve,
            node_handler::Update,
            node_handler::Delete,
            data_table_handler::Create,
            data_table_handler::Retrieve,
            data_table_handler::Update,
            data_table_handler::Delete,
            group_hanler::Create,
            group_hanler::Retrieve,
            group_hanler::Update,
            group_hanler::Delete,
            remote_resource_object_handler::Create,
            remote_resource_object_handler::Retrieve,
            remote_resource_object_handler::Update,
            remote_resource_object_handler::Delete,
            remote_attribute_handler::Create,
            remote_attribute_handler::Retrieve,
            remote_attribute_handler::Update,
            remote_attribute_handler::Delete,
            remote_command_handler::Create,
            remote_command_handler::Retrieve,
            remote_command_handler::Update,
            remote_command_handler::Delete
    };

    handlers[(((_Res->get_ty()) - 1) << 2) + (_Req->get_op().get_val() - 1)](_Req, _Rsp, _Res);

//    switch (_Res->get_ty()) {
//        case resource::enumeration::CRMS_MemberType::rootResource:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::resourceObject:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::attribute:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::command:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::node:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::dataTable:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::group:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::remoteResourceObject:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::remoteAttribute:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        case resource::enumeration::CRMS_MemberType::remoteCommand:
//            HANDLE_CRUD(NodeHandler, _Req, _Rsp, _Res);
//            break;
//        default:
//            break;
//    }
}
