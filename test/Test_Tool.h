//
// Created by nini on 11/9/16.
//

#ifndef GATEWAY_CSE_TEST_TOOL_H
#define GATEWAY_CSE_TEST_TOOL_H

#include "../utility/HttpUtil/HttpUtil.h"
#include "../protocol/resource/crms_common/CRMS_RetrieveQuery.h"
#include "../protocol/resource/crms_resource/CRMS_Resource.h"

namespace test_tool {

    static const std::string URL = "192.168.159.130:8080";
    static const std::string RSC_OK = "1";

    std::map<std::string, std::string> GetHeaders();

    bool Create(const std::string &path, const std::string &name,
                const crms::protocol::resource::resource::CRMS_Resource *resource);

    void Retrieve(const std::string &path, crms::protocol::resource::common::CRMS_PartialRetrieve pr);

    void Retrieve(const std::string &path, crms::protocol::resource::common::CRMS_PaginationRetrieve pg);

    void Retrieve(const std::string &path, crms::protocol::resource::common::CRMS_SubscriptionRetrieve sr);

    void Update(const std::string &path, const std::string &body);

    void Delete(const std::string &path);
}


#endif //GATEWAY_CSE_TEST_TOOL_H
