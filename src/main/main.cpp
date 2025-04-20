#include <iostream>

#include "../base/ttime.h"
#include "../base/string_utils.h"

using namespace std;

static void test_base_time()
{
    cout << endl;
    cout << "------------------- base::TTime start------------------" << endl;

    cout << "NowMs: "<< on::base::TTime::NowMs() << endl;
    cout << "Now: "<< on::base::TTime::Now() << endl;

    int year, month, day, hour, minute, second;
    on::base::TTime::Now(year, month, day, hour, minute, second);
    cout << "year: "<< year << endl;
    cout << "month: "<< month << endl;
    cout << "day: "<< day << endl;
    cout << "hour: "<< hour << endl;
    cout << "minute: "<< minute << endl;
    cout << "second: "<< second << endl;
    cout << "ISOTimeStr: "<< on::base::TTime::ISOTimeStr() << endl;

    cout << "------------------- base::TTime end------------------" << endl;
    cout << endl;
}

static void test_base_string_utils()
{
    cout << endl;
    cout << "------------------- base::StringUtils start------------------" << endl;

    const string path = "usr/local/system.ini";
//    const string path = "usr/local/system.";

    cout << "path: "<< path << endl;
    cout << "FilePath: "<< on::base::StringUtils::FilePath(path) << endl;
    cout << "FileNameExt: "<< on::base::StringUtils::FileNameExt(path) << endl;
    cout << "FileName: "<< on::base::StringUtils::FileName(path) << endl;
    cout << "Extension: "<< on::base::StringUtils::Extension(path) << endl;

    const string src = "aaabbb";
    const string start_sub = "aaa";
    const string end_sub = "bbbbb";

    cout << "StartsWith: "<< on::base::StringUtils::StartsWith(src, start_sub) << endl;
    cout << "EndsWith: "<< on::base::StringUtils::EndsWith(src, start_sub) << endl;
//    cout << "second: "<< on::base::StringUtils::FilePath(path) << endl;

    const string splitstr = "//usr//local//system//test";
    const string delimiter = "//";

    auto ret = on::base::StringUtils::SplitString(splitstr, delimiter);
    for (const auto &str : ret)
    {
        cout << "SplitString: "<< str << endl;
    }

    cout << "------------------- base::StringUtils end------------------" << endl;
    cout << endl;
}

int main(int argc, char* argv[])
{
    test_base_time();
    test_base_string_utils();
    return 0;
}

