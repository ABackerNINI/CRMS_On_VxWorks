//
// Created by nini on 9/27/17.
//

#include "remote_resource_object_handler.h"
#include "../resource_operator/resource_operator.h"

void crms::protocol::agent::resource_handler::remote_resource_object_handler::Create(
        crms::protocol::resource::resource::CRMS_Req *_Req, crms::protocol::resource::resource::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::create_resource(_Req, _Rsp, _Res);
}

void crms::protocol::agent::resource_handler::remote_resource_object_handler::Retrieve(
        crms::protocol::resource::resource::CRMS_Req *_Req, crms::protocol::resource::resource::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::retrieve_resource(_Req, _Rsp, _Res);
}

void crms::protocol::agent::resource_handler::remote_resource_object_handler::Update(
        crms::protocol::resource::resource::CRMS_Req *_Req, crms::protocol::resource::resource::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::update_resource(_Req, _Rsp, _Res);
}

void crms::protocol::agent::resource_handler::remote_resource_object_handler::Delete(
        crms::protocol::resource::resource::CRMS_Req *_Req, crms::protocol::resource::resource::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::delete_resource(_Req, _Rsp, _Res);
}
