#include "group_handler.h"
#include "../resource_operator/resource_operator.h"

void crms::protocol::agent::resource_handler::group_hanler::Create(crms::protocol::resource::primitive::CRMS_Req *req,
                                                                   crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                                                   crms::protocol::resource::resource::CRMS_Resource *res) {
    *rsp = crms::protocol::resource::primitive::CRMS_Rsp(req,
                                                         resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
}

void crms::protocol::agent::resource_handler::group_hanler::Retrieve(crms::protocol::resource::primitive::CRMS_Req *req,
                                                                     crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                                                     crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::retrieve_resource(req, rsp, res);
}

void crms::protocol::agent::resource_handler::group_hanler::Update(crms::protocol::resource::primitive::CRMS_Req *req,
                                                                   crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                                                   crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::update_resource(req, rsp, res);
}

void crms::protocol::agent::resource_handler::group_hanler::Delete(crms::protocol::resource::primitive::CRMS_Req *req,
                                                                   crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                                                   crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::delete_resource(req, rsp, res);
}
