//
// Created by nini on 10/27/17.
//

#include <stdio.h>
#include "../../utility/HttpUtil/HttpUtil.h"
#include "../../utility/HttpUtil/mongoose.h"
#include "../../utility/HttpUtil/Client.h"
#include "../Test_Tool.h"
#include "../../protocol/resource/crms_resource/CRMS_RootResource.h"
#include "../../protocol/resource/crms_resource/CRMS_ResourceObject.h"
#include "../../protocol/resource/crms_resource/CRMS_Command.h"
#include "../../protocol/resource/crms_resource/CRMS_Attribute.h"
#include "../../protocol/common.h"

void On_Response(HttpUtil::Http_Rsp *http_rsp) {
    //printf("%s\n", http_rsp->Body.c_str());
}

void On_Error(HttpUtil::Client::ErrCode err_code, HttpUtil::Http_Rsp *rsp, http_message *msg, void *_Extra) {
    printf("error_code:%d\n", err_code);
}

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

//create stress test
//return number of tests failed
int test_1_1(int sum) {
    LOGEVT("stress test @test_1_1 begin\n");
    DateTime begin = DateTime::now();
    int failed = 0;
    for (int i = 0; i < sum; ++i) {
        if (!test_1()) {
            ++failed;
        }
    }
    DateTime end = DateTime::now();
    LOGEVT("stress test @test_1_1 end\n");

    long long dif = DateTime::diffTime(end, begin);

    printf("stress test @test_1_1 time used:%lld.%llds\n", dif / 1000, dif % 1000);

    return failed;
}

int main() {
    if (!test_1()) {
        printf("test_1 failed!\n");
    } else {
        int sum = 10000;
        int failed = test_1_1(sum);
        printf("stress test @test_1_1 %d/%d failed\n", failed, sum);
    }

    return 0;
}