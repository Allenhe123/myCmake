message(status, "using bundled Findlibdb.cmake...")
find_path(
    LIBGLOG_CXX_INCLUDE_DIR
    glog.h
    /usr/include/ /usr/local/include
)

find_library(
    LIBGLOG_CXX_LIBRARIES NAMES glog
    paths /usr/lib /usr/local/lib
)