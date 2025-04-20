/********************************************************************************
* @author: hwk
* @email: orionlink@163.com
* @date: 2025/4/20 19:40
* @version: 1.0
* @description: 字符串工具类
********************************************************************************/

#ifndef ORIONNEBULA_STRING_UTILS_H
#define ORIONNEBULA_STRING_UTILS_H

#include <string>
#include <vector>

namespace on
{
    namespace base
    {
        class StringUtils
        {
        public:
            /**
             * @brief 判断字符串 src 是否以子串 sub 开头
             * @param src
             * @param sub
             * @return
             */
            static bool StartsWith(const std::string& src, const std::string &sub);

            /**
             * @brief 判断字符串 src 是否以子串 sub 结尾
             * @param src
             * @param sub
             * @return
             */
            static bool EndsWith(const std::string& src, const std::string &sub);

            /**
             * @brief 通过完整的文件名路径，返回去除文件名的路径
             * @param path 例 /user/local/system.ini
             * @return /user/local, 如果只有文件名，返回 ./
             */
            static std::string FilePath(const std::string& path);

            /**
             * @brief 通过完整的文件名路径，返回文件名(包含后缀)
             * @param path 例 /user/local/system.ini
             * @return system.ini, 如果没有路径，则直接返回参数 path
             */
            static std::string FileNameExt(const std::string& path);

            /**
             * @brief 通过完整的文件名路径，返回文件名(不包含后缀)
             * @param path 例 /user/local/system.ini
             * @return system, 如果文件名为 .system 则不认为有后缀，直接返回 .system
             */
            static std::string FileName(const std::string& path);

            /**
             * @brief 通过完整的文件名路径，返回文件名的后缀
             * @param path 例 /user/local/system.ini
             * @return ini 如果文件名为 .system 或者 system. 则不认为有后缀，返回空
             */
            static std::string Extension(const std::string& path);

            /**
             * @brief 字符串切割
             * @param src
             * @param delimiter
             * @return
             */
            static std::vector<std::string> SplitString(const std::string& src, const std::string& delimiter);
        };
    }
}

#endif //ORIONNEBULA_STRING_UTILS_H
