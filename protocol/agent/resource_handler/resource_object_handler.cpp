#include "resource_object_handler.h"
#include "../resource_operator/resource_operator.h"

void crms::protocol::agent::resource_handler::resource_object_handler::Create(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::create_resource(req, rsp, res);
}

void crms::protocol::agent::resource_handler::resource_object_handler::Retrieve(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::retrieve_resource(req, rsp, res);
}

void crms::protocol::agent::resource_handler::resource_object_handler::Update(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::update_resource(req, rsp, res);
}

void crms::protocol::agent::resource_handler::resource_object_handler::Delete(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::delete_resource(req, rsp, res);
}
