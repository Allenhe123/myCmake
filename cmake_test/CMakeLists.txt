cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")


# should we use our own math functions?
option (USE_MYMATH "Use tutorial provided math implementation" ON) 

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# 该指令的主要作用就是将指定的源文件生成链接文件，然后添加到工程中去
# add_library(<name> [STATIC | SHARED | MODULE]
#            [EXCLUDE_FROM_ALL]
#            [source1] [source2] [...])
# <name>表示库文件的名字，该库文件会根据命令里列出的源文件来创建。而STATIC、SHARED和MODULE的作用是指定生成的库文件的类型。
# MODULE库是一种不会被链接到其它目标中的插件，但是可能会在运行时使用dlopen-系列的函数
add_library(MathFunctions mysqrt.cpp)
 
# add the executable
add_executable (Tutorial tutorial.cpp)

# 将目标文件与库文件进行链接
# target_link_libraries(<target> [item1] [item2] [...]
#                      [[debug|optimized|general] <item>] ...)
# <target>是指通过add_executable()和add_library()指令生成已经创建的目标文件
# [item]表示库文件没有后缀的名字
target_link_libraries (Tutorial  ${EXTRA_LIBS})
