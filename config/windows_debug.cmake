message(STATUS "Platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

add_definitions(-DVLD_ENABLED)

set(OPENCV_ROOT "D:/code/cpplibs/opencv-debug/")
set(SPD_ROOT "D:/code/cpplibs/spdlog/")
set(VLD_ROOT "C:/VLD")
set(POCO_ROOT "D:/code/cpplibs/poco-debug")

# ------------------ VLD ------------------------
target_include_directories(${PROJECT_NAME} PRIVATE "${VLD_ROOT}/include")
target_link_directories(${PROJECT_NAME} PRIVATE  "${VLD_ROOT}/lib/Win64")
target_link_libraries(${PROJECT_NAME} PRIVATE "${VLD_ROOT}/lib/Win64/vld.lib")

# ---------------- Spdlog ---------------------------
target_include_directories(${PROJECT_NAME} PRIVATE "${SPD_ROOT}/include")
target_link_libraries(${PROJECT_NAME} PRIVATE "${SPD_ROOT}/build/Debug/spdlogd.lib")

include(config/googletest_debug.cmake)
