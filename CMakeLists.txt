cmake_minimum_required(VERSION 3.14)
project(StudyCPP)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# 添加源文件
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} "src/main.cc")

if(WIN32)
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(config/windows/debug.cmake)
  elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    include(config/windows/release.cmake)
  endif()
  # ---------------------- OpenCV --------------------------
  target_include_directories(${PROJECT_NAME} PRIVATE "${OPENCV_ROOT}/include")
  file(GLOB OPENCV_LIBS CONFIGURE_DEPENDS "${OPENCV_ROOT}/lib/*.lib")
  target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENCV_LIBS})

  # ---------------- POCO ----------------
  target_include_directories(${PROJECT_NAME} PRIVATE  "${POCO_ROOT}/include")
  file(GLOB_RECURSE POCO_LIBS "${POCO_ROOT}/lib/*.lib")
  target_link_libraries(${PROJECT_NAME} PRIVATE ${POCO_LIBS})
elseif(UNIX)
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(config/linux/debug.cmake)
  elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    include(config/linux/release.cmake)
  endif()
endif()

# 项目头文件
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
