# wsjcpp-parse-conf


[![Build Status](https://api.travis-ci.org/wsjcpp/wsjcpp-parse-conf.svg?branch=master)](https://travis-ci.org/wsjcpp/wsjcpp-parse-conf) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-parse-conf.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-parse-conf) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-parse-conf.svg)](https://github.com/wsjcpp/wsjcpp-parse-conf) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-parse-conf.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-parse-conf/network/members) [![Total alerts](https://img.shields.io/lgtm/alerts/g/wsjcpp/wsjcpp-parse-conf.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-parse-conf/alerts/) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/wsjcpp/wsjcpp-parse-conf.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-parse-conf/context:cpp)

Primitive parser for *.conf files

## How to integrate

```
$ wsjcpp install "https://github.com/wsjcpp/wsjcpp-parse-conf:master"
```

or include files to your project:

* src.wsjcpp/wsjcpp_core/wsjcpp_core.h
* src.wsjcpp/wsjcpp_core/wsjcpp_core.cpp
* src/wsjcpp_parse_conf.h
* src/wsjcpp_parse_conf.cpp

## Example usage

```
#include <string>
#include <iostream>
#include <wsjcpp_core.h>
#include <wsjcpp_parse_conf.h>

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);
    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setPrefixLogFile("wsjcpp");
    WsjcppLog::setLogDirectory(".logs");
    
    WsjcppParseConf conf("./example.conf");
    if (!conf.load()) {
        std::cout << "Could not load file conf" << std::endl;
        return -1;
    }
    
    if (conf.has("testBool")) {
        bool bResult = conf.getBoolValue("testBool", false);
        std::cout << "testBool = " << (bResult ? "true" : "false" ) << std::endl;
    }

    if (conf.has("testInt")) {
        int nResult = conf.getIntValue("testInt", 0);
        std::cout << "testInt = " << nResult << std::endl;
    }

    if (conf.has("testString")) {
        std::string sResult = conf.getStringValue("testString", "");
        std::cout << "testString = " << sResult << std::endl;
    }

    if (conf.has("testString2")) {
        std::string sResult2 = conf.getStringValue("testString2", "");
        std::cout << "testString2 = " << sResult2 << std::endl;
    }

    return 0;
}
```