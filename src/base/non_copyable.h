/********************************************************************************
* @author: hwk
* @email: orionlink@163.com
* @date: 2025/4/20 21:11
* @version: 1.0
* @description: 
********************************************************************************/

#ifndef ORIONNEBULA_NON_COPYABLE_H
#define ORIONNEBULA_NON_COPYABLE_H

namespace on
{
    namespace base
    {
        class NonCopyable
        {
        protected:
            NonCopyable()
            {}
            virtual ~NonCopyable()
            {}

            NonCopyable(const NonCopyable&) = delete;
            NonCopyable& operator=(const NonCopyable&) = delete;
        };
    }
}

#endif //ORIONNEBULA_NON_COPYABLE_H
