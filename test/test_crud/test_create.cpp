//
// Created by nini on 10/27/17.
//

#include <stdio.h>
#include "../../utility/HttpUtil/HttpUtil.h"
#include "../Test_Tool.h"
#include "../../protocol/resource/crms_resource/CRMS_RootResource.h"
#include "../../protocol/resource/crms_resource/CRMS_ResourceObject.h"
#include "../../protocol/resource/crms_resource/CRMS_Command.h"
#include "../../protocol/resource/crms_resource/CRMS_Attribute.h"
#include "../../protocol/resource/crms_enumeration/CRMS_ResourceType.h"

//create three resources under ROOT_RESOURCE
//return create result
bool test_1() {
    //create CRMS_ResourceObject
    crms::protocol::resource::resource::CRMS_ResourceObject ro;
    {
        ro.set_ty(crms::protocol::resource::enumeration::CRMS_ResourceType::resourceObject);
        ro.set_onto("onto");
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

//create stress test
//return number of tests failed
bool test_2() {
    DateTime begin = DateTime::now();

    int sum = 10000;
    int failed = 0;
    for (int i = 0; i < sum; ++i) {
        if (!test_1()) {
            ++failed;
        }
    }
    DateTime end = DateTime::now();

    long long dif = DateTime::diffTime(end, begin);

    printf("stress test @test_2 time used:%lld.%llds\n", dif / 1000, dif % 1000);
    printf("stress test @test_2 %d/%d failed\n", failed, sum);

    return failed == 0;
}

int main() {
    test_tool::test_func funcs[] = {
            test_1,
            test_2
    };

    test_tool::Test(funcs, sizeof(funcs) / sizeof(test_tool::test_func));

    return 0;
}