/********************************************************************************
* @author: hwk
* @email: orionlink@163.com
* @date: 2025/4/20 19:40
* @version: 1.0
* @description:
********************************************************************************/

#ifndef BASE_TTIME_H
#define BASE_TTIME_H

#include <cstdint>
#include <string>

namespace on
{
    namespace base
    {
        class TTime
        {
        public:
            /**
             * @brief 获取当前时间戳，单位毫秒
             * @return
             */
           static int64_t NowMs();

           /**
            * @brief 获取当前时间戳，单位秒
            * @return
            */
           static int64_t Now();

           /**
            * @brief 获取当前时间戳，单位毫秒。并且通过参数返回对应的年月日时分秒的数值
            */
           static int64_t Now(int & year, int & month, int & day, int & hour, int & minute, int & second);

           /**
            * @brief 返回当前时间ISO格式的字符串(yyyy-MM-ddTHH:mm:ss)
            * @return
            */
           static std::string ISOTimeStr();
        };
    }
}

#endif //BASE_TTIME_H
