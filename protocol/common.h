#pragma once

#ifndef _CRMS_PROTOCOL_COMMON_H_
#define _CRMS_PROTOCOL_COMMON_H_

#include "../utility/TimeUtil/DateTime.h"

#ifndef _NOEXCEPT
#define _NOEXCEPT throw()
#endif

#define LOGEVT(_Log...) printf("\033[31mLog(\033[0m%s\033[31m)\033[0m:",DateTime::now().to_string().c_str());   \
                        printf(_Log);                                                                           \
                        printf("\n")

#endif //_CRMS_PROTOCOL_COMMON_H_
