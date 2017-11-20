#pragma once

#ifndef _CRMS_RESOURCE_REMOTE_COMMAND_H_
#define _CRMS_RESOURCE_REMOTE_COMMAND_H_

#include "../ResourceBase.h"
#include "CRMS_Command.h"

namespace crms {

    namespace protocol {

        namespace resource {

            namespace resource {

                class CRMS_RemoteCommand : public CRMS_Command {
                public:
                    CRMS_RemoteCommand() :
                            CRMS_Command(),
                            rm(NJSON_DEFAULT_VALUE_INT) {
                        memset(&proxy, -1, sizeof(proxy));
                    }

                DEFINE_MEMBER(rm, _INT)

                DEFINE_MEMBER(rri, _STRING)

                DEFINE_MEMBER(proxy, _BOOL)
                };
            }
        }
    }
}

#endif//_CRMS_RESOURCE_REMOTE_COMMAND_H_