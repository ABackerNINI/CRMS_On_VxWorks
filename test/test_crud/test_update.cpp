//
// Created by nini on 10/28/17.
//

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
    //create CRMS_ResourceObject
    crms::protocol::resource::resource::CRMS_ResourceObject ro;
    {
        ro.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::resourceObject);
    }
    if (!test_tool::Update("/root/1", "", &ro)) {
        return false;
    }

    //create CRMS_Attribute
    crms::protocol::resource::resource::CRMS_Attribute attr;
    {
        attr.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::attribute);
    }
    if (!test_tool::Update("/root/1", "", &attr)) {
        return false;
    }

    //create CRMS_Command
    crms::protocol::resource::resource::CRMS_Command cmd;
    {
        cmd.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::command);
    }
    if (!test_tool::Update("/root/1", "", &cmd)) {
        return false;
    }

    return true;
}

int main() {
    test_tool::test_func funcs[] = {
            test_1,
            test_2
    };

    test_tool::Test(funcs, sizeof(funcs) / sizeof(test_tool::test_func));

    return 0;
}