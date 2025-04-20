/********************************************************************************
* @author: hwk
* @email: orionlink@163.com
* @date: 2025/4/20 21:13
* @version: 1.0
* @description: 单例模板类
********************************************************************************/

#ifndef ORIONNEBULA_SINGLETON_H
#define ORIONNEBULA_SINGLETON_H

#include "non_copyable.h"

#include <mutex>
#include <memory>

namespace on
{
    namespace base
    {
        template<typename T>
        class Singleton
        {
        public:
            static std::shared_ptr<T> GetInstance()
            {
                static std::once_flag flag;
                std::call_once(flag, [&]()
                {
                    _instance = std::shared_ptr<T>(new T);
                });

                return _instance;
            }

            virtual ~Singleton() {}
        protected:
            Singleton() = default;
            Singleton(const Singleton&) = delete;
            Singleton& operator=(const Singleton&) = delete;

        private:
            static std::shared_ptr<T> _instance;
        };

        template<typename T>
        std::shared_ptr<T> Singleton<T>::_instance = nullptr;
    }
}

#endif //ORIONNEBULA_SINGLETON_H
