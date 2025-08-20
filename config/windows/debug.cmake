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

# ---------------- POCO ----------------
target_include_directories(${PROJECT_NAME} PRIVATE  "${POCO_ROOT}/include")
file(GLOB_RECURSE POCO_LIBS "${POCO_ROOT}/lib/*.lib")
target_link_libraries(${PROJECT_NAME} PRIVATE ${POCO_LIBS})
file(GLOB_RECURSE POCO_DLLS "${POCO_ROOT}/bin/*.dll")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${POCO_DLLS}
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

include(config/windows/googletest.cmake)
