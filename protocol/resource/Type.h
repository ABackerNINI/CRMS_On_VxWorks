#pragma once

#ifndef _CRMS_RESOURCE_TYPE_H_
#define _CRMS_RESOURCE_TYPE_H_

//basic types
#define _CHAR           char
#define _BOOL           bool
#define _SHORT          short
#define _INT            int
#define _UINT           unsigned int
#define _FLOAT          float
#define _LONG_LONG      long long
#define _DOUBLE         double

//string & list & map & vector types
#define _STRING         std::string
#define _CSTR           char *
#define _LIST           std::list
#define _MAP            std::map
#define _VECTOR         std::vector

//DateTime & Duration types
#define _DATETIME       DateTime
#define _DURATION       Duration

#include <string>
#include <list>
#include <map>
#include <vector>

#include "../../utility/TimeUtil/DateTime.h"
#include "../../utility/TimeUtil/Duration.h"

#endif//_CRMS_RESOURCE_TYPE_H_