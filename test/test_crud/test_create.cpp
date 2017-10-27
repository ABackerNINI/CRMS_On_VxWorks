//
// Created by nini on 10/27/17.
//

#include <stdio.h>
#include "../../utility/HttpUtil/HttpUtil.h"
#include "../../utility/HttpUtil/mongoose.h"
#include "../../utility/HttpUtil/Client.h"

void On_Response(HttpUtil::Http_Rsp *http_rsp) {
    //printf("%s\n", http_rsp->Body.c_str());
}

void On_Error(HttpUtil::Client::ErrCode err_code, HttpUtil::Http_Rsp *rsp, http_message *msg, void *_Extra) {
    printf("error_code:%d\n", err_code);
}

void test_1(){
    
}

int main(){
    test_1();

    return 0;
}