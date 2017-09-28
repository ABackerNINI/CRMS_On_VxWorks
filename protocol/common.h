//
// Created by nini on 9/26/17.
//

#ifndef _CRMS_PROTOCOL_COMMON_H_
#define _CRMS_PROTOCOL_COMMON_H_

#include "../utility/DateTime/DateTime.h"

#define LOGEVT(_Log...) printf("\033[31mLog(\033[0m%s\033[31m)\033[0m:",DateTime::now().to_string().c_str());   \
                        printf(_Log);                                                                           \
                        printf("\n")

#endif //_CRMS_PROTOCOL_COMMON_H_
