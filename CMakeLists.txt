cmake_minimum_required(VERSION 3.0.0)

project(sol_issue_1508)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_library(LUAJIT_LIBRARY_DIR libluajit-5.1.a lua51 REQUIRED)
find_path(LUAJIT_INCLUDE_DIR luajit.h PATH_SUFFIXES luajit-2.1 luajit REQUIRED)
add_library(luajit INTERFACE)
target_include_directories(luajit INTERFACE ${LUAJIT_INCLUDE_DIR})
target_link_libraries(luajit INTERFACE ${LUAJIT_LIBRARY_DIR})
message(STATUS "LuaJIT Include Dir: ${LUAJIT_INCLUDE_DIR}")
message(STATUS "LuaJIT Library Dir: ${LUAJIT_LIBRARY_DIR}")

add_executable(test main.cpp)
target_link_libraries(test PRIVATE luajit)
target_compile_options(test PRIVATE -Wall -Wextra -pedantic -Werror)

# set(SOL_VERSION "v3.2.1")
# set(SOL_VERSION "v3.3.0")
set(SOL_VERSION "eab1430c")
message(STATUS "SOL Version: ${SOL_VERSION}")
target_include_directories(test PRIVATE sol/sol_${SOL_VERSION})
