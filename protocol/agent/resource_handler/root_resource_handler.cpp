#include "root_resource_handler.h"
#include "../resource_operator/resource_operator.h"
#include "../../resource/crms_resource/CRMS_RootResource.h"
#include "../../keyword.h"
#include "../../resource/crms_enumeration/CRMS_MemberType.h"
#include "../../../utility/resource_pool/resource_pool.h"

void crms::protocol::agent::resource_handler::root_resource_handler::Create(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::create_resource(req, rsp, res);
}

void crms::protocol::agent::resource_handler::root_resource_handler::Retrieve(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    resource_operator::resource_operator::retrieve_resource(req, rsp, res);
}

void crms::protocol::agent::resource_handler::root_resource_handler::Update(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    *rsp = crms::protocol::resource::primitive::CRMS_Rsp(req,
                                                         resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
}

void crms::protocol::agent::resource_handler::root_resource_handler::Delete(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *res) {
    *rsp = crms::protocol::resource::primitive::CRMS_Rsp(req,
                                                         resource::enumeration::CRMS_ResponseStatusCodeType::Bad_request);////mark
}

void crms::protocol::agent::resource_handler::root_resource_handler::init_root_resource() {
    resource::resource::CRMS_RootResource *rootResource = new resource::resource::CRMS_RootResource();
    rootResource->set_rn(KV_CRMS_ROOT_RESOURCE_RN);
    rootResource->set_ri(KV_CRMS_ROOT_RESOURCE_RI);
    rootResource->set_ty(resource::enumeration::CRMS_MemberType::rootResource);
    rootResource->set_ct(DateTime::now());
    rootResource->set_lt(rootResource->get_ct());

    resource_pool::get_instance().register_resource(KV_CRMS_ROOT_RESOURCE_RI, rootResource);
}
