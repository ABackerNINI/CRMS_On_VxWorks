#pragma once

//
//	Created by ABacker on 4/30/2016
//

#ifndef _ABACKER_TIME_H_
#define _ABACKER_TIME_H_

#include <time.h>
#include <string>
#include <iostream>
#include <stdio.h>

#if defined(__unix__)
#include <sys/time.h>

#define FEATURE_GET_CPU_CYCLE_COUNT 0

#if (FEATURE_GET_CPU_CYCLE_COUNT)

#if defined (__i386__)

inline unsigned long long GetCpuCycleCount() {
        unsigned long long x;
        __asm__ volatile("rdtsc":"=A"(x));
        return x;
    }

#elif defined(__x86_64__)

inline unsigned long long GetCpuCycleCount() {
    unsigned hi, lo;
    __asm__ volatile("rdtsc":"=a"(lo), "=d"(hi));
    return ((unsigned long long) lo) | (((unsigned long long) hi) << 32);
}

#endif

#endif

#elif defined(_WIN32)
#include <windows.h>

#if (FEATURE_GET_CPU_CYCLE_COUNT)

	inline unsigned long long GetCpuCycleCount() {
		__asm{
			_emit 0x0F;
			_emit 0x31;
		}//rdtsc
	}

#endif

	// #if !defined(_WINSOCK2API_) && !defined(_WINSOCKAPI_)
	// 	struct timeval {
	// 		long tv_sec;
	// 		long tv_usec;
	// 	};
	// #endif

	// void gettimeofday(struct timeval* tv) {
	// 	union {
	// 		long long ns100;
	// 		FILETIME ft;
	// 	} now;
	// 	GetSystemTimeAsFileTime(&now.ft);
	// 	tv->tv_usec = (long)((now.ns100 / 10LL) % 1000000LL);
	// 	tv->tv_sec = (long)((now.ns100 - 116444736000000000LL) / 10000000LL);
	// }
	int gettimeofday(struct timeval *tp, void *tzp){
	    time_t clock;
	    struct tm tm;
	    SYSTEMTIME wtm;
	    GetLocalTime(&wtm);
	    tm.tm_year     = wtm.wYear - 1900;
	    tm.tm_mon     = wtm.wMonth - 1;
	    tm.tm_mday     = wtm.wDay;
	    tm.tm_hour     = wtm.wHour;
	    tm.tm_min     = wtm.wMinute;
	    tm.tm_sec     = wtm.wSecond;
	    tm. tm_isdst    = -1;
	    clock = mktime(&tm);
	    tp->tv_sec = (long)clock;
	    tp->tv_usec = wtm.wMilliseconds * 1000;

	    return 0;
	}
#endif

//class Duration;

#define DEFAULT_DATETIME_DATETIME           0x7fffffff7fffffff
#define DEFAULT_DATETIME_CPUCYCLECOUNT      0x7fffffff7fffffff
#define DEFAULT_DURATION_DDATETIME          0x7fffffff7fffffff
#define DEFAULT_DURATION_DCPUCYCLECOUNT     0x7fffffff7fffffff

class DateTime {
    friend class Duration;

public:
    //extremely like the struct tm in time.h
    struct tmFormat {
        int year;
        /* years since 1900 */
        int month;
        /* months since January - [0,11] */
        int mday;
        /* day of the month - [1,31] */
        int hour;
        /* hours since midnight - [0,23] */
        int minute;
        /* minutes after the hour - [0,59] */
        int second;
        /* seconds after the minute - [0,59] */
        int millisec;
        /* milliseconds after the second -[0.999]*/
        int microsec;
        /* microseconds after the millisecond -[0.999]*/
        int wday;
        /* days since Sunday - [0,6] */
        int yday;
        /* days since January 1 - [0,365] */
        int isdst;
        /* daylight savings time flag */

#if (FEATURE_GET_CPU_CYCLE_COUNT)
        unsigned long long cpuCycleCount; /* CPU cycle count since system boot */
#endif
    };

#if (FEATURE_GET_CPU_CYCLE_COUNT)
    DateTime()
            : dateTime(DEFAULT_DATETIME_DATETIME), cpuCycleCount(DEFAULT_DATETIME_CPUCYCLECOUNT) {
    }
#else

    DateTime()
            : dateTime(DEFAULT_DATETIME_DATETIME) {
    }

#endif

    //DateTime formate is like "2016-09-17T16:55:42.403+08:00 42345677345234234"
    //or ellipsis last one or two or three like "2014-4-30T20:55:25"
    DateTime(const std::string &dateTime) {
        DateTime(dateTime.c_str());
    }

    DateTime(const char *dateTime) {
        tm time;
        int millisec = 0, microsec = 0;
        unsigned long long cpuCycleCount = 0;
        sscanf(dateTime, "%d-%d-%dT%d:%d:%d.%d %llu", &time.tm_year, &time.tm_mon, &time.tm_mday,
               &time.tm_hour, &time.tm_min, &time.tm_sec, &millisec, &cpuCycleCount);

        time.tm_year -= 1900;
        time.tm_mon -= 1;
        time.tm_isdst = -1;

        this->dateTime = ((unsigned long long)mktime(&time) * 1000 + millisec);
#if (FEATURE_GET_CPU_CYCLE_COUNT)
        this->cpuCycleCount = cpuCycleCount;
#endif
    }

    static DateTime now() {
        DateTime dateTime;
#if (FEATURE_GET_CPU_CYCLE_COUNT)
        dateTime.cpuCycleCount = GetCpuCycleCount();
#endif

#if defined(__unix__)
        struct timeval t;
        gettimeofday(&t, NULL);
        dateTime.dateTime = (unsigned long long)time(NULL) * 1000 + t.tv_usec / 1000;
#elif defined(_WIN32)
        struct timeval t;
		gettimeofday(&t,NULL);
		dateTime.dateTime = (unsigned long long)time(NULL) * 1000 + t.tv_usec / 1000;
#endif

        return dateTime;
    }

    bool isUninitialized() const {
        return dateTime == DEFAULT_DATETIME_DATETIME
#if (FEATURE_GET_CPU_CYCLE_COUNT)
       	&& cpuCycleCount == DEFAULT_DATETIME_CPUCYCLECOUNT
#endif
        ;
    }

    //return time interval in micro second,if>0 means dateTime1 is after dateTime2
    static long long diffTime(const DateTime &dateTime1, const DateTime &dateTime2) {
        return dateTime1.dateTime - dateTime2.dateTime;
    }

    bool isAfter(const DateTime &dateTime) const {
        return diffTime(*this, dateTime) > 0;
    }

    bool isBefore(const DateTime &dateTime) const {
        return diffTime(*this, dateTime) < 0;
    }

    bool isEqual(const DateTime &dateTime) const {
        return diffTime(*this, dateTime) == 0;
    }

//    bool isBefore_with_cpu_cycle_count(const DateTime &dateTime) const {
//        return diffTime(*this, dateTime) < 0 ||
//               (diffTime(*this, dateTime) == 0 && cpuCycleCount < dateTime.cpuCycleCount);
//    }
//
//    bool isAfter_with_cpu_cycle_count(const DateTime &dateTime) const {
//        return diffTime(*this, dateTime) > 0 ||
//               (diffTime(*this, dateTime) == 0 && cpuCycleCount > dateTime.cpuCycleCount);
//    }
//
//    bool isEqual_with_cpu_cycle_count(const DateTime &dateTime) const {
//        return diffTime(*this, dateTime) == 0 && cpuCycleCount == dateTime.cpuCycleCount;
//    }

    std::string to_string_with_milli_sec() const {
        if (isUninitialized())return std::string();

        time_t _dateTime = dateTime / 1000;
        tm t = *localtime(&_dateTime);
        
        char dateTime[30];
        sprintf(dateTime, "%d-%02d-%02dT%02d:%02d:%02d.%03d%s", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour,
                t.tm_min, t.tm_sec, int(this->dateTime % 1000), get_local_timezone().c_str());

        return std::string(dateTime);
    }

    std::string to_string() const {
        return to_string_with_milli_sec();
    }

//    std::string to_string_with_sec() const {
//        time_t _dateTime = dateTime / 1000;
//        tm t = *localtime(&_dateTime);

//        char dateTime[30];
//        sprintf(dateTime, "%d/%02d/%02d %02d:%02d:%02d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min,
//                t.tm_sec);

//        return std::string(dateTime);
//    }

//    std::string to_string_with_date() const {
//        time_t _dateTime = dateTime / 1000;
//        tm t = *localtime(&_dateTime);

//        char dateTime[30];
//        sprintf(dateTime, "%d-%02d-%02dT%02d:%02d:%02d+08:00", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour,
//                t.tm_min, t.tm_sec);
//        return std::string(dateTime);
//    }

//    std::string to_string_with_micro_sec() const {
//        time_t _dateTime = dateTime / 1000000;
//        tm t = *localtime(&_dateTime);

//        char dateTime[30];
//        sprintf(dateTime, "%d-%02d-%02dT%02d:%02d:%02d.%03d.%03d+08:00", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
//                t.tm_hour,
//                t.tm_min, t.tm_sec, int((this->dateTime % 1000000) / 1000), int(this->dateTime % 1000));

//        return std::string(dateTime);
//    }

// #if(FEATURE_GET_CPU_CYCLE_COUNT)
//    std::string to_string_with_cpu_cycle_count() const {
//        time_t _dateTime = dateTime / 1000000;
//        tm t = *localtime(&_dateTime);

//        char dateTime[50];
//        sprintf(dateTime, "%d-%02d-%02dT%02d:%02d:%02d.%03d.%03d+08:00 %llu", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
//                t.tm_hour,
//                t.tm_min, t.tm_sec, int((this->dateTime % 1000000) / 1000), int(this->dateTime % 1000), cpuCycleCount);

//        return std::string(dateTime);
//    }
// #endif

    void getFormat(/*in*/  tmFormat *format) const {
        time_t _dateTime = (time_t) dateTime / 1000;
        tm t = *localtime(&_dateTime);

        format->year = t.tm_year;
        format->month = t.tm_mon;
        format->mday = t.tm_mday;
        format->hour = t.tm_hour;
        format->minute = t.tm_min;
        format->second = t.tm_sec;
        format->millisec = int(this->dateTime % 1000);
        format->microsec = 0;

        format->wday = t.tm_wday;
        format->yday = t.tm_yday;
        format->isdst = t.tm_isdst;

#if (FEATURE_GET_CPU_CYCLE_COUNT)
        format->cpuCycleCount = cpuCycleCount;
#endif
    }

    const std::string &get_local_timezone() const {
        static std::string timezone_string;

        if (timezone_string.empty()) {
            time_t t = time(NULL);

            tm LOC_tm = *localtime(&t);
            tm UTC_tm = *gmtime(&t);

            time_t LOC_time = mktime(&LOC_tm);
            time_t UTC_time = mktime(&UTC_tm);

            unsigned long long timezone = (LOC_time - UTC_time) / 3600;
            char tmp[10];
            timezone_string = itoa((int)timezone,tmp,10);
            if (timezone >= 0) timezone_string = "+0" + timezone_string + ":00";
            else {
                timezone_string.insert(1, "0");
                timezone_string += ":00";
            }
        }

        return timezone_string;
    }

private:
    unsigned long long dateTime;                    //second * 1000 + msec

#if (FEATURE_GET_CPU_CYCLE_COUNT)
    unsigned long long cpuCycleCount;
#endif
};

typedef DateTime Date;
typedef DateTime LocalDateTime;

#endif//_ABACKER_TIME_H_