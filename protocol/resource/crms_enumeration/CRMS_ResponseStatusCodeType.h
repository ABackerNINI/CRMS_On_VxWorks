#pragma once

#ifndef _CRMS_RESOURCE_RESPONSE_STATUS_CODE_TYPE_H_
#define _CRMS_RESOURCE_RESPONSE_STATUS_CODE_TYPE_H_

#include "EnumerationBase.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace enumeration {

                struct CRMS_ResponseStatusCodeType : public EnumerationBase {
                    CRMS_ResponseStatusCodeType() {}

                    CRMS_ResponseStatusCodeType(int val) { this->val = val; }

                    static const _SHORT Success = 1;
                    static const _SHORT Accepted = 2;
                    static const _SHORT Unsupported_resource = 3;
                    static const _SHORT Unsupported_attribute = 4;
                    static const _SHORT Create_error_no_privilege = 5;
                    static const _SHORT Create_error_already_exists = 6;
                    static const _SHORT Create_error_missing_mandatory_parameter = 7;
                    static const _SHORT Retrieve_error_no_privilege = 8;
                    static const _SHORT Retrieve_error_does_not_exist = 9;
                    static const _SHORT Update_error_no_privilege = 10;
                    static const _SHORT Update_error_does_not_exist = 11;
                    static const _SHORT Update_error_unacceptable_contents = 12;
                    static const _SHORT Delete_error_does_not_exist = 13;
                    static const _SHORT Delete_error_no_privilege = 14;
                    static const _SHORT Bad_request = 15;

                    static const std::string &get_msg(_SHORT rsc) {
                        static const std::string Msg[] = {
                                "",
                                "Success",
                                "Accepted",
                                "Unsupported_resource",
                                "Unsupported_attribute",
                                "Create_error_no_privilege",
                                "Create_error_already_exists",
                                "Create_error_missing_mandatory_parameter",
                                "Retrieve_error_no_privilege",
                                "Retrieve_error_does_not_exist",
                                "Update_error_no_privilege",
                                "Update_error_does_not_exist",
                                "Update_error_unacceptable_contents",
                                "Delete_error_does_not_exist",
                                "Delete_error_no_privilege",
                                "Bad_request"
                        };

                        return Msg[rsc];
                    }
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_RESPONSE_STATUS_CODE_TYPE_H_