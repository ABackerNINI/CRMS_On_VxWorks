//
// Created by nini on 9/27/17.
//

#include "node_handler.h"
#include "../resource_operator/resource_operator.h"

void crms::protocol::agent::resource_handler::node_handler::Create(resource::resource::CRMS_Req *_Req,
                                                                  resource::resource::CRMS_Rsp *_Rsp,
                                                                  resource::resource::CRMS_Resource *_Res) {
    *_Rsp = crms::protocol::resource::resource::CRMS_Rsp(_Req,
                                                         resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
}

void crms::protocol::agent::resource_handler::node_handler::Retrieve(crms::protocol::resource::resource::CRMS_Req *_Req,
                                                                    crms::protocol::resource::resource::CRMS_Rsp *_Rsp,
                                                                    crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::retrieve_resource(_Req, _Rsp, _Res);
}

void crms::protocol::agent::resource_handler::node_handler::Update(crms::protocol::resource::resource::CRMS_Req *_Req,
                                                                  crms::protocol::resource::resource::CRMS_Rsp *_Rsp,
                                                                  crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::update_resource(_Req, _Rsp, _Res);
}

void crms::protocol::agent::resource_handler::node_handler::Delete(crms::protocol::resource::resource::CRMS_Req *_Req,
                                                                  crms::protocol::resource::resource::CRMS_Rsp *_Rsp,
                                                                  crms::protocol::resource::resource::CRMS_Resource *_Res) {
    resource_operator::resource_operator::delete_resource(_Req, _Rsp, _Res);
}
