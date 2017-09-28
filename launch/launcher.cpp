#include <iostream>

#include "../utility/HttpUtil/Server.h"
#include "../protocol/common.h"
#include "../protocol/agent/request_handler/request_handler.h"
#include "../protocol/agent/resource_handler/root_resource_handler.h"

#define PORT "8080"

void start_server() {
    HttpUtil::server::Show_Req(REQ_ALL);
    HttpUtil::server::Show_Rsp(RSP_ALL);
    HttpUtil::server::Callback _Callback(cse::protocol::agent::request_handler::on_request,
                                         cse::protocol::agent::request_handler::on_error);

    LOGEVT("starting server");
    if (HttpUtil::server::Start(PORT, _Callback)) {
        LOGEVT("server started at port "
                       PORT);
    }
}

void stop_server() {
    HttpUtil::server::Stop();
    LOGEVT("server has been stopped");
}

void launch() {
    crms::protocol::agent::resource_handler::root_resource_handler::init_root_resource();

    start_server();

    char cmd[1000];
    std::cin.getline(cmd, 1000);

    stop_server();
}

int main() {

    launch();

    return 0;
}
