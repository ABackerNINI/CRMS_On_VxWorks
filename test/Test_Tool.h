//
// Created by nini on 11/9/16.
//

#ifndef GATEWAY_CSE_TEST_TOOL_H
#define GATEWAY_CSE_TEST_TOOL_H

#include "../utility/HttpUtil/HttpUtil.h"
#include "../protocol/resource/crms_common/CRMS_RetrieveQuery.h"
#include "../protocol/resource/crms_resource/CRMS_Resource.h"

namespace test_tool {

    static const std::string URL = "http://localhost:8080";
    static const std::string RSC_OK = "1";

    std::map<std::string, std::string> GetHeaders();

    bool Create(const std::string &path, const std::string &name,
                const crms::protocol::resource::resource::CRMS_Resource *resource);

    bool Retrieve(const std::string &path,HttpUtil::Http_Req *req = NULL);

    bool Retrieve(const std::string &path, const crms::protocol::resource::common::CRMS_PartialRetrieve &pr);

    bool Retrieve(const std::string &path, const crms::protocol::resource::common::CRMS_PaginationRetrieve &pg);

    bool Retrieve(const std::string &path, const crms::protocol::resource::common::CRMS_SubscriptionRetrieve &sr);

    bool Update(const std::string &path, const std::string &body);

    bool Delete(const std::string &path);


    typedef bool (*test_func)();

    int Test(test_func *funcs,int n);
}


#endif //GATEWAY_CSE_TEST_TOOL_H
