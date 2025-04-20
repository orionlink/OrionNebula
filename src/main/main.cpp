#include <iostream>

#include "../base/ttime.h"
#include "../base/string_utils.h"
#include "../base/singleton.h"
#include "../base/non_copyable.h"


using namespace std;
using namespace on::base;

static void test_base_time()
{
    cout << endl;
    cout << "------------------- base::TTime start------------------" << endl;

    cout << "NowMs: "<< TTime::NowMs() << endl;
    cout << "Now: "<< TTime::Now() << endl;

    int year, month, day, hour, minute, second;
    TTime::Now(year, month, day, hour, minute, second);
    cout << "year: "<< year << endl;
    cout << "month: "<< month << endl;
    cout << "day: "<< day << endl;
    cout << "hour: "<< hour << endl;
    cout << "minute: "<< minute << endl;
    cout << "second: "<< second << endl;
    cout << "ISOTimeStr: "<< TTime::ISOTimeStr() << endl;

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
    cout << "FilePath: "<< StringUtils::FilePath(path) << endl;
    cout << "FileNameExt: "<< StringUtils::FileNameExt(path) << endl;
    cout << "FileName: "<< StringUtils::FileName(path) << endl;
    cout << "Extension: "<< StringUtils::Extension(path) << endl;

    const string src = "aaabbb";
    const string start_sub = "aaa";
    const string end_sub = "bbbbb";

    cout << "StartsWith: "<< StringUtils::StartsWith(src, start_sub) << endl;
    cout << "EndsWith: "<< StringUtils::EndsWith(src, start_sub) << endl;

    const string splitstr = "//usr//local//system//test";
    const string delimiter = "//";

    auto ret = StringUtils::SplitString(splitstr, delimiter);
    for (const auto &str : ret)
    {
        cout << "SplitString: "<< str << endl;
    }

    cout << "------------------- base::StringUtils end------------------" << endl;
    cout << endl;
}

class A : public NonCopyable
{
public:
    A() = default;
    ~A() = default;

    void Print()
    {
        cout << "This is A" << endl;
    }
};

int main(int argc, char* argv[])
{
    test_base_time();
    test_base_string_utils();

    auto aA = Singleton<A>::GetInstance();
    aA->Print();

    return 0;
}

