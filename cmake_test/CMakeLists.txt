cmake_minimum_required (VERSION 2.6)
project (Tutorial)
include(CTest)
set (CTEST_PROJECT_NAME "Tutorial")

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# does this system provide the log and exp functions?
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)

check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

message(status, "CMAKE_ROOT:${CMAKE_ROOT}")

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")


message(status, "PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
message(status, "PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
# 通过配置USB_MYMATH来决定是否编译和使用MathFunctions.”EXTRA_LIBS”变量是用来收集每一个可选库的,以便他们链接到可执行程序中.这是一个保持大项目工程可选库清洁的通用方法
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions) # 使得子目录MathFunctions也能被编译
  set (EXTRA_LIBS ${EXTRA_LIBS} MathSqrt)
endif (USE_MYMATH)
 
# add the executable
add_executable (Tutorial tutorial.cxx)

# 将目标文件与库文件进行链接
# target_link_libraries(<target> [item1] [item2] [...]
#                      [[debug|optimized|general] <item>] ...)
# <target>是指通过add_executable()和add_library()指令生成已经创建的目标文件
# [item]表示库文件没有后缀的名字
target_link_libraries (Tutorial  ${EXTRA_LIBS})

message(status, "EXTRA_LIBS:${EXTRA_LIBS}")

##################################################################################
# cmake 后 build 目录执行 make install
# add the install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

message(status, "CMAKE_INSTALL_PREFIX:${CMAKE_INSTALL_PREFIX}")

#################################################################################
# cmake 后 build 目录执行make test
# does the application run  --- NAME COMMAND ARGS
add_test (TutorialRuns Tutorial 25)
 
# does the usage message work?
add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage   # NAME PROPERTY VALUE
  PROPERTIES 
  PASS_REGULAR_EXPRESSION "Usage:.*number"
  )
 
 
#define a macro to simplify adding tests
macro (do_test arg result)
  add_test (TutorialComp${arg} Tutorial ${arg})
  set_tests_properties (TutorialComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)
 
# do a bunch of result based tests
do_test (4 "4 is 2")
do_test (9 "9 is 3")
do_test (5 "5 is 2.236")
do_test (7 "7 is 2.645")
do_test (25 "25 is 5")
do_test (-25 "-25 is 0")
do_test (0.0001 "0.0001 is 0.01")


# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)


