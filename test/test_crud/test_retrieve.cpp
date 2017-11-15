//
// Created by nini on 10/27/17.
//

#include "../../protocol/resource/crms_resource/CRMS_ResourceObject.h"
#include "../Test_Tool.h"
#include "../../protocol/resource/crms_resource/CRMS_Attribute.h"
#include "../../protocol/resource/crms_resource/CRMS_Command.h"
#include "../../protocol/resource/crms_enumeration/CRMS_ResourceType.h"

//create three resources under ROOT_RESOURCE
//return create result
bool test_1() {
    //create CRMS_ResourceObject
    crms::protocol::resource::resource::CRMS_ResourceObject ro;
    {
        ro.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::resourceObject);
    }
    if (!test_tool::Create("/root", "", &ro)) {
        return false;
    }

    //create CRMS_Attribute
    crms::protocol::resource::resource::CRMS_Attribute attr;
    {
        attr.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::attribute);
    }
    if (!test_tool::Create("/root", "", &attr)) {
        return false;
    }

    //create CRMS_Command
    crms::protocol::resource::resource::CRMS_Command cmd;
    {
        cmd.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::command);
    }
    if (!test_tool::Create("/root", "", &cmd)) {
        return false;
    }

    return true;
}

//retrieve
bool test_2() {
    if (!test_tool::Retrieve("/root")) {
        return false;
    }
    if (!test_tool::Retrieve("/root/1")) {
        return false;
    }
    if (!test_tool::Retrieve("/root/2")) {
        return false;
    }
    if (!test_tool::Retrieve("/root/3")) {
        return false;
    }

    return true;
}

//retrieve with pr.in
bool test_3() {
    crms::protocol::resource::common::CRMS_PartialRetrieve pr;
    pr.set_ty(crms::protocol::resource::common::CRMS_PartialRetrieveType::In);
    pr.set_val("pa,ri,rn,ct,lt");

    if (!test_tool::Retrieve("/root", pr)) {
        return false;
    }
    if (!test_tool::Retrieve("/root/1", pr)) {
        return false;
    }
    if (!test_tool::Retrieve("/root/2", pr)) {
        return false;
    }
    if (!test_tool::Retrieve("/root/3", pr)) {
        return false;
    }

    return true;
}

//retrieve with pr.ex
bool test_4() {
    crms::protocol::resource::common::CRMS_PartialRetrieve pr;
    pr.set_ty(crms::protocol::resource::common::CRMS_PartialRetrieveType::Ex);
    pr.set_val("pa,ri,rn,ct,lt");

    if (!test_tool::Retrieve("/root", pr)) {
        return false;
    }
    if (!test_tool::Retrieve("/root/1", pr)) {
        return false;
    }
    if (!test_tool::Retrieve("/root/2", pr)) {
        return false;
    }
    if (!test_tool::Retrieve("/root/3", pr)) {
        return false;
    }

    return true;
}

int main() {
    test_tool::test_func funcs[] = {
            test_1,
            test_2,
            test_3,
            test_4
    };

    test_tool::Test(funcs, sizeof(funcs) / sizeof(test_tool::test_func));

    return 0;
}