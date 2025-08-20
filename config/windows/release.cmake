message(STATUS "Platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

set(OPENCV_ROOT "D:/code/cpplibs/opencv-release/")
set(SPD_ROOT "D:/code/cpplibs/spdlog/")
set(POCO_ROOT "D:/code/cpplibs/poco-release")

# ---------------- SPDLOG ----------------
target_include_directories(${PROJECT_NAME} PRIVATE "${SPD_ROOT}/include")
target_link_libraries(${PROJECT_NAME} PRIVATE "${SPD_ROOT}/build/Release/spdlog.lib")

# file(GLOB_RECURSE POCO_DLLS "${POCO_ROOT}/bin/*.dll")
# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#             ${POCO_DLLS}
#             $<TARGET_FILE_DIR:${PROJECT_NAME}>
# )
