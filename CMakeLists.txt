cmake_minimum_required(VERSION 3.14)
project(StudyCPP)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含头文件路径
include_directories(include /usr/local/include)

# 查找 OpenCV
find_package(OpenCV REQUIRED)

# 包含头文件路径
include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
)

# 添加源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接 OpenCV 库
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
