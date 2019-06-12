
cmake_minimum_required (VERSION 2.6)
project (mmain)

set(CMAKE_SOURCE_DIR .)
set(CMAKE_MODULE_PATH ${CMAKE_ROOT}/Modules ${CMAKE_SOURCE_DIR}/cmake/modules)
ADD_SUBDIRECTORY( src )

# aux_source_directory(<dir> <variable>)
# 该命令会把参数 <dir> 中所有的源文件名称赋值给参数 <variable> 
aux_source_directory(. DIR_SRCS)
add_executable(mmain ${DIR_SRCS})

find_package(libglog REQUIRED)
mark_as_advanced(LIBGLOG_CXX_INCLUDE_DIR LIBGLOG_CXX_LIBRARIES)

if (LIBGLOG_CXX_INCLUDE_DIR AND LIBGLOG_CXX_LIBRARIES)
message(status, "found libdb libraries")
include_directories(${LIBGLOG_CXX_INCLUDE_DIR})
message(status, "LIBGLOG_CXX_LIBRARIES:${LIBGLOG_CXX_LIBRARIES}")
target_link_libraries(mmain ${LIBGLOG_CXX_LIBRARIES})
endif(LIBGLOG_CXX_INCLUDE_DIR AND LIBGLOG_CXX_LIBRARIES)

TARGET_LINK_LIBRARIES( mmain Test )
