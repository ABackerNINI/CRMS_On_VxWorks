#include "remote_attribute_handler.h"
#include "../resource_operator/resource_operator.h"

void crms::protocol::agent::resource_handler::remote_attribute_handler::Create(
        crms::protocol::resource::primitive::CRMS_Req *_Req, crms::protocol::resource::primitive::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    *_Rsp = crms::protocol::resource::primitive::CRMS_Rsp(_Req,
                                                         resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
}

void crms::protocol::agent::resource_handler::remote_attribute_handler::Retrieve(
        crms::protocol::resource::primitive::CRMS_Req *_Req, crms::protocol::resource::primitive::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::retrieve_resource(_Req, _Rsp, _Res);
}

void crms::protocol::agent::resource_handler::remote_attribute_handler::Update(
        crms::protocol::resource::primitive::CRMS_Req *_Req, crms::protocol::resource::primitive::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::update_resource(_Req, _Rsp, _Res);
}

void crms::protocol::agent::resource_handler::remote_attribute_handler::Delete(
        crms::protocol::resource::primitive::CRMS_Req *_Req, crms::protocol::resource::primitive::CRMS_Rsp *_Rsp,
        crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::delete_resource(_Req, _Rsp, _Res);
}
