#include "resource_operator.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../resource/crms_resource/CRMS_Attribute.h"
#include "../../resource/crms_common/CRMS_ChildResourceRef.h"
#include "../../resource/crms_resource/CRMS_Command.h"
#include "../../resource/crms_resource/CRMS_DataTable.h"
#include "../../resource/crms_resource/CRMS_Group.h"
#include "../../resource/crms_resource/CRMS_Node.h"
#include "../../resource/crms_resource/CRMS_RemoteAttribut.h"
#include "../../resource/crms_resource/CRMS_RemoteCommand.h"
#include "../../resource/crms_resource/CRMS_RemoteResourceObject.h"
#include "../../resource/crms_resource/CRMS_RootResource.h"
#include "../../../utility/resource_pool/resource_pool.h"
#include "../../json_support/crms_primitive/PrimitiveContentTypeSupport.h"

void build_corresponding_rsp(crms::protocol::resource::primitive::CRMS_Req *req,
                             crms::protocol::resource::primitive::CRMS_Rsp *rsp) {
    rsp->set_fr(req->get_to());
    rsp->set_to(req->get_fr());
    rsp->set_rqi(req->get_rqi());
}

void build_corresponding_successful_rsp(crms::protocol::resource::primitive::CRMS_Req *req,
                                        crms::protocol::resource::primitive::CRMS_Rsp *rsp) {
    build_corresponding_rsp(req, rsp);
    rsp->set_rsc(crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Success);
}

void build_corresponding_failed_rsp(crms::protocol::resource::primitive::CRMS_Req *req,
                                    crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                    crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType rsc) {
    build_corresponding_rsp(req, rsp);
    rsp->set_rsc(rsc);

    rsp->get_pc().set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::string);
    rsp->get_pc().set_val(
            (void *) &crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::get_msg(rsc.get_val()));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CREATE

//unsigned int to ascii c string
char *uitoa(unsigned int value, char *str, int base) {
    static char zm[37] = "0123456789abcdefghijklmnopqrstuvwxyz";

    unsigned int n = 0, tmp;
    while (value > 0) {
        tmp = value;
        value /= base;

        str[n++] = zm[tmp - value * base];//zm[value % base]
    }

    for (int i = (n + 1) >> 1; i < n; ++i) {
        std::swap(str[i], str[n - i - 1]);
    }

    str[n] = '\0';

    return str;
}

//set rn&ri and register resource to resource pool
int register_resource(crms::protocol::resource::resource::CRMS_HasChildren *parent,
                      crms::protocol::resource::resource::CRMS_Resource *resource) {
    std::string ri;
    if (resource->get_rn().empty()) {
        char rn[10];
        unsigned int acid = parent->get_acid();

        int ret = -1;
        while (ret == -1) {
            uitoa(acid++, rn, 36);
            ri = parent->get_ri() + "/" + rn;

            ret = resource_pool::get_instance().register_resource(ri, resource);
        }

        resource->set_rn(rn);
        resource->set_ri(ri);

        parent->set_acid(acid);
    } else {
        ri = parent->get_ri() + "/" + resource->get_rn();

        resource->set_ri(ri);

        return resource_pool::get_instance().register_resource(ri, resource);
    }

    return 0;
}

void build_create_successful_rsp(crms::protocol::resource::primitive::CRMS_Req *req,
                                 crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                 crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_corresponding_successful_rsp(req, rsp);

    rsp->get_pc().set_ty(req->get_ty());
    rsp->get_pc().set_val((void *) resource);
}

//create resource
void crms::protocol::agent::resource_operator::resource_operator::create_resource(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *parent) {

    crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> pc;

    deserialize_pc(&pc, req->get_ty(), (const char *) req->get_pc().get_val());

    resource::resource::CRMS_Resource *resource = (resource::resource::CRMS_Resource *) pc.get_val();

    if (resource == NULL) {
        build_corresponding_failed_rsp(req, rsp,
                                       crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Create_error_missing_mandatory_parameter);

        return;
    }

    resource->set_ty(req->get_ty());
    resource->set_rn(req->get_rn());

    ////see TS-0001 10.1.1.1 Step 002 5);
    //a
    resource->set_pa(parent->get_ri());
    //b
    resource->set_ct(DateTime::now());
    //c
    ////mark
    //d
    resource->set_lt(resource->get_ct());
    //e
    //TODO assign Any other RO (Read Only) attributes within the restriction of the Receiver policies a value.

    //store the resource & update its real rn and ri
    if (register_resource((crms::protocol::resource::resource::CRMS_HasChildren *) parent, resource) == -1) {
        build_corresponding_failed_rsp(req, rsp,
                                       crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Create_error_already_exists);

        return;
    }

    //add to parent's ch list
    crms::protocol::resource::common::CRMS_ChildResourceRef child_resource_ref;
    child_resource_ref.set_v(resource->get_ri());
    child_resource_ref.set_rn(resource->get_rn());
    child_resource_ref.set_ty(resource->get_ty());

    ((resource::resource::CRMS_HasChildren *) parent)->add_child_ref(child_resource_ref);

    //build create-successful response
    build_create_successful_rsp(req, rsp, resource);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RETRIEVE

void build_retrieve_successful_rsp(crms::protocol::resource::primitive::CRMS_Req *req,
                                   crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                   crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_corresponding_successful_rsp(req, rsp);

    rsp->get_pc().set_ty(resource->get_ty());
    rsp->get_pc().set_val((void *) resource);
}

//retrieve resource
void crms::protocol::agent::resource_operator::resource_operator::retrieve_resource(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_retrieve_successful_rsp(req, rsp, resource);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UPDATE

void build_update_successful_rsp(crms::protocol::resource::primitive::CRMS_Req *req,
                                 crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                 crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_corresponding_successful_rsp(req, rsp);

    rsp->get_pc().set_ty(resource->get_ty());
    rsp->get_pc().set_val((void *) resource);
}

//update resource
void crms::protocol::agent::resource_operator::resource_operator::update_resource(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *resource) {
    crms::protocol::resource::primitive::CRMS_PrimitiveContentType<> pc;

    deserialize_pc(&pc, resource->get_ty(), (const char *) req->get_pc().get_val());

    resource::resource::CRMS_Resource *new_resource = (resource::resource::CRMS_Resource *) pc.get_val();////mark:delete new_resource

    if (new_resource == NULL) {////mark
        build_corresponding_failed_rsp(req, rsp,
                                       crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Update_error_unacceptable_contents);

        return;
    }

    new_resource->set_ty(resource->get_ty());
    new_resource->set_lt(DateTime::now());

    //update resource
    pc.set_val(resource);

    deserialize_pc(&pc, resource->get_ty(), (const char *) req->get_pc().get_val());

    resource->set_lt(new_resource->get_lt());

    build_update_successful_rsp(req, rsp, new_resource);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DELETE

void build_delete_successful_rsp(crms::protocol::resource::primitive::CRMS_Req *req,
                                 crms::protocol::resource::primitive::CRMS_Rsp *rsp,
                                 crms::protocol::resource::enumeration::CRMS_ResourceType ty) {
    build_corresponding_successful_rsp(req, rsp);

    static std::string rsp_success = "Success";

    rsp->get_pc().set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::string);
    rsp->get_pc().set_val(&rsp_success);
}

int get_has_children_resource() {
    int has_children = 0;
    {
        //resources have children
        has_children |= (1 << crms::protocol::resource::enumeration::CRMS_MemberType::rootResource);
        has_children |= (1 << crms::protocol::resource::enumeration::CRMS_MemberType::resourceObject);
        has_children |= (1 << crms::protocol::resource::enumeration::CRMS_MemberType::command);
    }

    return has_children;
}

void delete_resource_instance(const std::string &_Id) {
    static const int has_children = get_has_children_resource();

    crms::protocol::resource::resource::CRMS_Resource *instance = (crms::protocol::resource::resource::CRMS_Resource *) resource_pool::get_instance().get_resource_from_id(
            _Id);

    assert(instance);

    if ((1 << instance->get_ty()) & has_children) {
        const std::list<crms::protocol::resource::common::CRMS_ChildResourceRef> &childrenListRef = ((crms::protocol::resource::resource::CRMS_HasChildren *) instance)->get_ch();

        //delete all children
        for (std::list<crms::protocol::resource::common::CRMS_ChildResourceRef>::const_iterator childIt = childrenListRef.begin();
             childIt != childrenListRef.end(); ++childIt) {
            delete_resource_instance(childIt->get_v());
        }
    }

    //delete storage
    resource_pool::get_instance().unregister_resource(_Id);

    //delete itself
    delete instance;////TODO:virtual destructor
}

//delete resource
void crms::protocol::agent::resource_operator::resource_operator::delete_resource(
        crms::protocol::resource::primitive::CRMS_Req *req, crms::protocol::resource::primitive::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *resource) {
    crms::protocol::resource::resource::CRMS_HasChildren *parent_resource = (crms::protocol::resource::resource::CRMS_HasChildren *) resource_pool::get_instance().get_resource_from_id(
            resource->get_pa());

    assert(parent_resource);

    //delete from its parent's ch-list
    parent_resource->remove_child_ref(resource->get_ri());

    //delete resource instance and its children if exist
    delete_resource_instance(resource->get_ri());

    build_delete_successful_rsp(req, rsp, resource->get_ty());
}