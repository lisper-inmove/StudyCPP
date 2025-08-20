enable_testing()

set(TEST_NAME "tester")
set(GTEST_ROOT "D:/code/cpplibs/googletest")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${TEST_NAME} ${SOURCES} tests/test.cpp)

target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(GTest REQUIRED)

target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main)

find_package(Poco REQUIRED Foundation Util Net)
target_link_libraries(${TEST_NAME} PRIVATE Poco::Foundation Poco::Util Poco::Net)

find_package(spdlog REQUIRED)
target_link_libraries(${TEST_NAME} PRIVATE spdlog::spdlog)

# 让 CTest 自动发现测试
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

message(STATUS "Add googletest in linux debug")
