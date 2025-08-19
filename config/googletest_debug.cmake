enable_testing()

set(TEST_NAME "tester")
set(GTEST_ROOT "D:/code/cpplibs/googletest")
set(SPD_ROOT "D:/code/cpplibs/spdlog/")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${TEST_NAME} ${SOURCES} tests/test.cpp)

target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# --------------------- googletest -----------------------------
file(GLOB GTEST_LIBS "${GTEST_ROOT}/build/lib/Debug/*.lib")
target_link_libraries(${TEST_NAME} PRIVATE ${GTEST_LIBS})
target_include_directories(${TEST_NAME} PRIVATE "${GTEST_ROOT}/googletest/include")

# ---------------- Spdlog ---------------------------
target_include_directories(${TEST_NAME} PRIVATE "${SPD_ROOT}/include")
target_link_libraries(${TEST_NAME} PRIVATE "${SPD_ROOT}/build/Debug/spdlogd.lib")

# ----------------- POCO ---------------------------
target_include_directories(${TEST_NAME} PRIVATE "${POCO_ROOT}/include")
file(GLOB_RECURSE POCO_LIBS "${POCO_ROOT}/lib/*.lib")
target_link_libraries(${TEST_NAME} PRIVATE ${POCO_LIBS})