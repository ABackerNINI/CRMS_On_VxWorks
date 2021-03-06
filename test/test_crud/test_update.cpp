//
// Created by nini on 10/28/17.
//

#include "../Test_Tool.h"
#include "../../protocol/resource/crms_resource/CRMS_Command.h"
#include "../../protocol/resource/crms_resource/CRMS_Attribute.h"
#include "../../protocol/resource/crms_resource/CRMS_ResourceObject.h"
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

//update resources
bool test_2() {
    //update CRMS_ResourceObject
    crms::protocol::resource::resource::CRMS_ResourceObject ro;
    {
        ro.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::resourceObject);
        ro.set_onto("test_onto");
    }
    if (!test_tool::Update("/root/1", &ro)) {
        return false;
    }

    //update CRMS_Attribute
    crms::protocol::resource::resource::CRMS_Attribute attr;
    {
        attr.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::attribute);
        attr.set_data("test_data");
        attr.set_ro(true);
    }
    if (!test_tool::Update("/root/2", &attr)) {
        return false;
    }

    //update CRMS_Command
    crms::protocol::resource::resource::CRMS_Command cmd;
    {
        cmd.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::command);
    }
    if (!test_tool::Update("/root/3", &cmd)) {
        return false;
    }

    return true;
}

//retrieve
bool test_3() {
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

int main() {
    test_tool::test_func funcs[] = {
            test_1,
            test_2,
            test_3
    };

    test_tool::Test(funcs, sizeof(funcs) / sizeof(test_tool::test_func));

    return 0;
}