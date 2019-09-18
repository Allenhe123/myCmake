AUX_SOURCE_DIRECTORY(. DIR_TEST1_SRCS)
ADD_LIBRARY ( Test ${DIR_TEST1_SRCS})

# create static lib： add_library(demo5 STATIC ${SRC_LIST})
# create dynamic lib: add_library(demo5_dynamic SHARED ${SRC_LIST})

# install lib and .h
# install(TARGETS demo5 DESTINATION lib)
# install(FILES demo5_h.h DESTINATION include)

# 指定lib输出目录
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
