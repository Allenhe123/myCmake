
cmake_minimum_required (VERSION 2.6)
project (mmain)

# set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# 还可以在命令行设置：
# cmake  -DCMAKE_BUILD_TYPE=Debug ..
set(CMAKE_CONFIGURATION_TYPES, )
message(status, "Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")

message(status, "CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_MODULE_PATH ${CMAKE_ROOT}/Modules  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
ADD_SUBDIRECTORY( src )  # add_subdirectory 指明本项目包含一个子目录src，这样src目录下的 CMakeLists.txt 文件和源代码也会被处理 

# aux_source_directory(<dir> <variable>)
# 该命令会把参数 <dir> 中所有的源文件名称赋值给参数 <variable> 
aux_source_directory(. DIR_SRCS)
# another way: file(GLOB DIR_SRCS ./*.cpp)
add_executable(mmain ${DIR_SRCS})

message(status, "CMAKE_MODULE_PATH:${CMAKE_MODULE_PATH}")

find_package(libglog REQUIRED)
mark_as_advanced(LIBGLOG_CXX_INCLUDE_DIR LIBGLOG_CXX_LIBRARIES)

message(status, "LIBGLOG_CXX_INCLUDE_DIR: ${LIBGLOG_CXX_INCLUDE_DIR}")
message(status, "LIBGLOG_CXX_LIBRARIES: ${LIBGLOG_CXX_LIBRARIES}")

if (LIBGLOG_CXX_INCLUDE_DIR AND LIBGLOG_CXX_LIBRARIES)
    message(status, "found libdb libraries")
    include_directories(${LIBGLOG_CXX_INCLUDE_DIR})
    message(status, "LIBGLOG_CXX_LIBRARIES:${LIBGLOG_CXX_LIBRARIES}")
    target_link_libraries(mmain ${LIBGLOG_CXX_LIBRARIES})
endif(LIBGLOG_CXX_INCLUDE_DIR AND LIBGLOG_CXX_LIBRARIES)

TARGET_LINK_LIBRARIES( mmain Test )
