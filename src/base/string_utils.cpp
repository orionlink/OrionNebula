/********************************************************************************
* @author: hwk
* @email: orionlink@163.com
* @date: 2025/4/20 19:40
* @version: 1.0
* @description: 
********************************************************************************/

#include "string_utils.h"

bool on::base::StringUtils::StartsWith(const std::string &src, const std::string &sub)
{
    if (sub.empty()) return true;
    if (src.empty()) return false;

    auto sub_len = sub.size();
    auto src_len = src.size();
    if (sub_len > src_len) return false;

    return src.compare(0, sub_len, sub) == 0;
}

bool on::base::StringUtils::EndsWith(const std::string &src, const std::string &sub)
{
    if (sub.empty()) return true;
    if (src.empty()) return false;

    auto sub_len = sub.size();
    auto src_len = src.size();
    if (sub_len > src_len) return false;

    return src.compare(src_len - sub_len, sub_len, sub) == 0;
}

std::string on::base::StringUtils::FilePath(const std::string &path)
{
    auto pos = path.find_last_of("/\\");
    if (pos != std::string::npos)
    {
        return path.substr(0, pos);
    }

#ifdef _WIN32
    return ".\\";
#else
    return "./";
#endif
}

std::string on::base::StringUtils::FileNameExt(const std::string &path)
{
    auto pos = path.find_last_of("/\\");
    if (pos != std::string::npos)
    {
        return path.substr(pos + 1);
    }

    return path;
}

std::string on::base::StringUtils::FileName(const std::string &path)
{
    auto file_name_ext = FileNameExt(path);

    auto pos = file_name_ext.find_last_of('.');
    if (pos != std::string::npos && pos != 0)
    {
        return file_name_ext.substr(0, pos);
    }

    return file_name_ext;
}

std::string on::base::StringUtils::Extension(const std::string &path)
{
    auto file_name_ext = FileNameExt(path);

    auto pos = file_name_ext.find_last_of('.');
    if (pos != std::string::npos && pos != 0 && pos + 1 < file_name_ext.size())
    {
        return file_name_ext.substr(pos + 1);
    }

    return "";
}

std::vector<std::string> on::base::StringUtils::SplitString(const std::string &src, const std::string &delimiter)
{
    std::vector<std::string> ret;
    if (delimiter.empty()) return ret;

    /// aaa//bbbb//ccccc//dd

    size_t last = 0;
    size_t next = 0;
    while ((next = src.find(delimiter, last)) != std::string::npos)
    {
        if (next > last)
        {
            ret.emplace_back(src.substr(last, next - last));
        }

        last = next + delimiter.size();
    }

    if (last < src.size())
    {
        ret.emplace_back(src.substr(last));
    }

    return ret;
}
