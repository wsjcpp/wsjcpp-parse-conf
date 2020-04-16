cmake_minimum_required(VERSION 3.0)

project(wsjcpp-parse-conf C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-parse-conf_SOURCE_DIR})

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/main.cpp")

#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

include_directories(${WSJCPP_INCLUDE_DIRS})

list (APPEND WSJCPP_SOURCES "./src/wsjcpp_parse_conf.h")
list (APPEND WSJCPP_SOURCES "./src/wsjcpp_parse_conf.cpp")

add_executable (wsjcpp-parse-conf ${WSJCPP_SOURCES})
target_link_libraries(wsjcpp-parse-conf ${WSJCPP_LIBRARIES})

install(
    TARGETS
        wsjcpp-parse-conf
    RUNTIME DESTINATION
        /usr/bin
)


