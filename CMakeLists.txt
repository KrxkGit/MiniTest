# CMakeList.txt: MiniTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("MiniTest")

# C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 编译为可执行文件 / 动态库
option(BUILD_EXECUTABLE "Build as executable" ON)

# 扫描源文件
set(MTEST_SOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/MTest)
file(GLOB_RECURSE SOURCES "${MTEST_SOURCES_PATH}/*.cpp")

# 生成可执行文件 / 动态库
if(BUILD_EXECUTABLE)
    file(GLOB_RECURSE SAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/sample*.cpp")
    add_executable(${PROJECT_NAME} ${SOURCES} ${SAMPLE_SOURCES})
else()
    list(FILTER SOURCES EXCLUDE REGEX ".*sample.*\\.cpp") # 如果存在 sample*.cpp, 移除
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
endif()
