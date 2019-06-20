message(status, "****using bundled Findlibglog.cmake...")
find_path(LIBGLOG_CXX_INCLUDE_DIR logging.h /usr/include/ /usr/local/include/glog/)
find_library(LIBGLOG_CXX_LIBRARIES glog /usr/lib/ /usr/local/lib/)