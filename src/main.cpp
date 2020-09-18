#include <string>
#include <iostream>
#include <wsjcpp_core.h>
#include <wsjcpp_parse_conf.h>

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_APP_NAME);
    std::string appVersion = std::string(WSJCPP_APP_VERSION);
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

