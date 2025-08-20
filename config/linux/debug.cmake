message(STATUS "Platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

find_package(Poco REQUIRED Foundation Util Net)
target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Foundation Poco::Util Poco::Net)

find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

include(config/linux/googletest.cmake)
