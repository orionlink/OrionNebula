#include "TTime.h"

#include <iostream>
#include <chrono>
#include <ctime>
int64_t on::base::TTime::NowMs()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int64_t on::base::TTime::Now()
{
    using namespace std::chrono;
    return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
}

int64_t on::base::TTime::Now(int &year, int &month, int &day, int &hour, int &minute, int &second)
{
    using namespace std::chrono;
    auto now = system_clock::now();

    std::time_t tt = system_clock::to_time_t(now);

    // 转换为本地时间结构体
    std::tm local_time;
#ifdef _WIN32
    localtime_s(&local_time, &tt);
#else
    localtime_r(&tt, &local_time);
#endif

    year = local_time.tm_year + 1900;
    month = local_time.tm_mon + 1;
    day = local_time.tm_mday;
    hour = local_time.tm_hour;
    minute = local_time.tm_min;
    second = local_time.tm_sec;

    return duration_cast<seconds>(now.time_since_epoch()).count();
}

std::string on::base::TTime::ISOTimeStr()
{
    using namespace std::chrono;
    auto now = system_clock::now();
    std::time_t tt = system_clock::to_time_t(now);

    std::tm local_time;
#ifdef _WIN32
    localtime_s(&local_time, &tt);
#else
    localtime_r(&tt, &local_time);
#endif

    char buffer[64] = {0};
    std::strftime(buffer, sizeof (buffer), "%Y-%m-%d %H:%M:%S", &local_time);

    return buffer;
}
