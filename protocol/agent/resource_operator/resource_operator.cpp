//
// Created by nini on 9/27/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "resource_operator.h"
#include "../../common.h"
#include "../../resource/crms_resource/CRMS_Attribute.h"
#include "../../resource/crms_resource/CRMS_ChildResourceRef.h"
#include "../../resource/crms_resource/CRMS_Command.h"
#include "../../resource/crms_resource/CRMS_DataTable.h"
#include "../../resource/crms_resource/CRMS_Group.h"
#include "../../resource/crms_resource/CRMS_Node.h"
#include "../../resource/crms_resource/CRMS_RemoteAttribut.h"
#include "../../resource/crms_resource/CRMS_RemoteCommand.h"
#include "../../resource/crms_resource/CRMS_RemoteResourceObject.h"
#include "../../resource/crms_resource/CRMS_RootResource.h"
#include "../../../utility/resource_pool/resource_pool.h"
#include "../../resource/crms_resource/CRMS_Req_Rsp.h"
#include "../../keyword.h"
#include "../../resource/crms_resource/CRMS_Req.h"

void build_corresponding_rsp(crms::protocol::resource::resource::CRMS_Req *req,
                             crms::protocol::resource::resource::CRMS_Rsp *rsp) {
    rsp->set_fr(req->get_to());
    rsp->set_to(req->get_fr());
    rsp->set_rqi(req->get_rqi());
}

void build_corresponding_successful_rsp(crms::protocol::resource::resource::CRMS_Req *req,
                                        crms::protocol::resource::resource::CRMS_Rsp *rsp) {
    build_corresponding_rsp(req, rsp);
    rsp->set_rsc(crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Success);
}

void build_failed_rsp(crms::protocol::resource::resource::CRMS_Req *req,
                      crms::protocol::resource::resource::CRMS_Rsp *rsp,
                      crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType rsc) {
    build_corresponding_rsp(req, rsp);
    rsp->set_rsc(rsc);

    crms::protocol::resource::resource::CRMS_Req_Rsp<std::string> req_rsp(
            crms::protocol::resource::enumeration::CRMS_MemberType::string,
            &crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::get_msg(rsc.get_val()));

    char *s = serialize(req_rsp);
    rsp->set_pc(crms::protocol::resource::resource::CRMS_PrimitiveContentType(s));
    delete[] s;
}

void serialize_resource_to_pc(crms::protocol::resource::resource::CRMS_Rsp *rsp,
                              crms::protocol::resource::resource::CRMS_Resource *resource,
                              crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Resource> *req_rsp) {

    char *s = NULL;
    switch (resource->get_ty()) {//switch:resources can be create or update or retrieve
        case crms::protocol::resource::enumeration::CRMS_MemberType::rootResource:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_RootResource> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::resourceObject:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_ResourceObject> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::attribute:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Attribute> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::command:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Command> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::node:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Node> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::dataTable:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_DataTable> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::group:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Group> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::remoteResourceObject:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_RemoteResourceObject> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::remoteAttribute:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_RemoteAttribute> *) req_rsp));
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::remoteCommand:
            s = serialize(
                    *((crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_RemoteCommand> *) req_rsp));
            break;
        default:
            assert(false);
            break;

    }
    rsp->set_pc(crms::protocol::resource::resource::CRMS_PrimitiveContentType(s));

    delete[] s;
}

crms::protocol::resource::resource::CRMS_Resource *
deserialize_resource(int ty, const char *s, crms::protocol::resource::resource::CRMS_Resource *resource = NULL) {
    crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Resource> req_rsp;

    if (resource) {
        req_rsp.set_val(resource);
    }

    switch (ty) {//switch:resources can be create or update
        case crms::protocol::resource::enumeration::CRMS_MemberType::resourceObject:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_ResourceObject> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::attribute:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Attribute> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::command:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Command> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::node:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Node> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::dataTable:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_DataTable> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::group:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Group> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::remoteResourceObject:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_RemoteResourceObject> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::remoteAttribute:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_RemoteAttribute> *) &req_rsp,
                    s);
            break;
        case crms::protocol::resource::enumeration::CRMS_MemberType::remoteCommand:
            deserialize(
                    (crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_RemoteCommand> *) &req_rsp,
                    s);
            break;
        default:
            assert(false);
            break;
    }

    return req_rsp.get_val();
}

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

void build_create_successful_rsp(crms::protocol::resource::resource::CRMS_Req *req,
                                 crms::protocol::resource::resource::CRMS_Rsp *rsp,
                                 crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_corresponding_successful_rsp(req, rsp);

    crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Resource> req_rsp(
            resource->get_ty(), resource);
    serialize_resource_to_pc(rsp, resource, &req_rsp);
}

void crms::protocol::agent::resource_operator::resource_operator::create_resource(
        crms::protocol::resource::resource::CRMS_Req *req, crms::protocol::resource::resource::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *parent) {

    resource::resource::CRMS_Resource *resource = deserialize_resource(req->get_ty(),
                                                                       req->get_pc().get_value().c_str());

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
        build_failed_rsp(req, rsp,
                         crms::protocol::resource::enumeration::CRMS_ResponseStatusCodeType::Create_error_already_exists);

        return;
    }

    //add to parent's ch list
    crms::protocol::resource::resource::CRMS_ChildResourceRef child_resource_ref;
    child_resource_ref.set_v(resource->get_ri());
    child_resource_ref.set_rn(resource->get_rn());
    child_resource_ref.set_ty(resource->get_ty());

    ((resource::resource::CRMS_HasChildren *) parent)->add_child_ref(child_resource_ref);

    //build create-successful response
    build_create_successful_rsp(req, rsp, resource);
}

void build_retrieve_successful_rsp(crms::protocol::resource::resource::CRMS_Req *req,
                                   crms::protocol::resource::resource::CRMS_Rsp *rsp,
                                   crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_corresponding_successful_rsp(req, rsp);

    crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Resource> req_rsp(
            resource->get_ty(), resource);
    req_rsp.set_retrieve_query(&(req->retrieve_query));

    serialize_resource_to_pc(rsp, resource, &req_rsp);
}

void crms::protocol::agent::resource_operator::resource_operator::retrieve_resource(
        crms::protocol::resource::resource::CRMS_Req *req, crms::protocol::resource::resource::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_retrieve_successful_rsp(req, rsp, resource);
}

void build_update_successful_rsp(crms::protocol::resource::resource::CRMS_Req *req,
                                 crms::protocol::resource::resource::CRMS_Rsp *rsp,
                                 crms::protocol::resource::resource::CRMS_Resource *resource) {
    build_corresponding_successful_rsp(req, rsp);

    crms::protocol::resource::resource::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Resource> req_rsp(
            resource->get_ty(), resource);
    serialize_resource_to_pc(rsp, resource, &req_rsp);
}

void crms::protocol::agent::resource_operator::resource_operator::update_resource(
        crms::protocol::resource::resource::CRMS_Req *req, crms::protocol::resource::resource::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *resource) {
    resource::resource::CRMS_Resource *new_resource = deserialize_resource(resource->get_ty(),
                                                                           req->get_pc().get_value().c_str());
    new_resource->set_ty(resource->get_ty());
    new_resource->set_lt(DateTime::now());

    //update resource
    deserialize_resource(resource->get_ty(), req->get_pc().get_value().c_str(), resource);
    resource->set_lt(new_resource->get_lt());

    build_update_successful_rsp(req, rsp, new_resource);
}

void build_delete_successful_rsp(crms::protocol::resource::resource::CRMS_Req *req,
                                 crms::protocol::resource::resource::CRMS_Rsp *rsp,
                                 crms::protocol::resource::enumeration::CRMS_MemberType ty) {
    build_corresponding_successful_rsp(req, rsp);

    char rsp_pc[50];
    sprintf(rsp_pc, KV_DELETE_RESPOND_FORMAT_STRING, (int) ty.get_val());

    rsp->set_pc(crms::protocol::resource::resource::CRMS_PrimitiveContentType(rsp_pc));
}

void delete_resource_instance(const std::string &_Id) {
    crms::protocol::resource::resource::CRMS_Resource *instance = (crms::protocol::resource::resource::CRMS_Resource *) resource_pool::get_instance().get_resource_from_id(
            _Id);
    int ty = instance->get_ty();
    if (ty == crms::protocol::resource::enumeration::CRMS_MemberType::rootResource ||
        ty == crms::protocol::resource::enumeration::CRMS_MemberType::resourceObject ||
        ty == crms::protocol::resource::enumeration::CRMS_MemberType::command ||
        ty == crms::protocol::resource::enumeration::CRMS_MemberType::remoteResourceObject ||
        ty == crms::protocol::resource::enumeration::CRMS_MemberType::remoteCommand) {//resources have children
        const std::list<crms::protocol::resource::resource::CRMS_ChildResourceRef> &childrenListRef = ((crms::protocol::resource::resource::CRMS_HasChildren *) instance)->get_children();

        //delete all children
        for (std::list<crms::protocol::resource::resource::CRMS_ChildResourceRef>::const_iterator childIt = childrenListRef.begin();
             childIt != childrenListRef.end(); ++childIt) {
            delete_resource_instance(childIt->get_v());
        }
    }

    //delete storage
    resource_pool::get_instance().unregister_resource(_Id);

    //delete itself
    delete instance;////TODO:virtual destructor
}

void crms::protocol::agent::resource_operator::resource_operator::delete_resource(
        crms::protocol::resource::resource::CRMS_Req *req, crms::protocol::resource::resource::CRMS_Rsp *rsp,
        crms::protocol::resource::resource::CRMS_Resource *resource) {
    resource::enumeration::CRMS_MemberType ty = resource->get_ty();

    delete_resource_instance(resource->get_ri());

    build_delete_successful_rsp(req, rsp, ty);
}