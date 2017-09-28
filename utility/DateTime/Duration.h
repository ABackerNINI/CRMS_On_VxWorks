#pragma once

#ifndef _ABACKER_DURATION_H_
#define _ABACKER_DURATION_H_

#include "DateTime.h"

class Duration {
    friend class DateTime;

public:
    unsigned long long ddateTime;                //second * 1000

#if (FEATURE_GET_CPU_CYCLE_COUNT)
    long long dcpuCycleCount;
#endif

#if (FEATURE_GET_CPU_CYCLE_COUNT)
    Duration()
            : ddateTime(DEFAULT_DURATION_DDATETIME), dcpuCycleCount(DEFAULT_DURATION_DCPUCYCLECOUNT) {
    }
#else

    Duration()
            : ddateTime(DEFAULT_DURATION_DDATETIME) {
    }

#endif

    Duration(const char *_Str) {
        //TODO construct with string
    }

    Duration(const DateTime &dateTime1, const DateTime &dateTime2) {
        ddateTime = dateTime1.dateTime - dateTime2.dateTime;
#if (FEATURE_GET_CPU_CYCLE_COUNT)
        dcpuCycleCount = (long long) dateTime1.cpuCycleCount - (long long) dateTime2.cpuCycleCount;
#endif
    }

    bool isUninitialized() const {
#if (FEATURE_GET_CPU_CYCLE_COUNT)
        return ddateTime == DEFAULT_DURATION_DDATETIME && dcpuCycleCount == DEFAULT_DURATION_DCPUCYCLECOUNT;
#else
        return ddateTime == DEFAULT_DURATION_DDATETIME;
#endif
    }

    std::string toString_in_micro_sec() const {
        char duration[20];
        sprintf(duration, "%lld", ddateTime);

        return std::string(duration);
    }

    std::string toString_in_milli_sec() const {
        char duration[20];
        sprintf(duration, "%lld", ddateTime / 1000);

        return std::string(duration);
    }

    std::string toString_in_sec() const {
        if (isUninitialized())return std::string();

        char duration[20];
        sprintf(duration, "%lld", ddateTime / 1000);

        return std::string(duration);
    }

    std::string toString_in_minute() const {
        char duration[20];
        sprintf(duration, "%lld", ddateTime / (1000LL * 60LL));

        return std::string(duration);
    }

    std::string toString_in_hour() const {
        char duration[20];
        sprintf(duration, "%lld", ddateTime / (1000LL * 3600LL));

        return std::string(duration);
    }

    std::string toString_in_day() const {
        char duration[20];
        sprintf(duration, "%lld", ddateTime / (1000LL * 3600LL * 24LL));

        return std::string(duration);
    }
};

#endif//_ABACKER_DURATION_H_