# first we add the executable that generates the table
add_executable(MakeTable MakeTable.cxx)

message(status, "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(status, "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# add the command to generate the source code
# https://cmake.org/cmake/help/v3.3/command/add_custom_command.html
add_custom_command (
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  )
# add the binary tree directory to the search path 
# for include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )
 
# 该指令的主要作用就是将指定的源文件生成链接文件，然后添加到工程中去
# add_library(<name> [STATIC | SHARED | MODULE]
#            [EXCLUDE_FROM_ALL]
#            [source1] [source2] [...])
# <name>表示库文件的名字，该库文件会根据命令里列出的源文件来创建。而STATIC、SHARED和MODULE的作用是指定生成的库文件的类型。
# MODULE库是一种不会被链接到其它目标中的插件，但是可能会在运行时使用dlopen-系列的函数
# add the main library
add_library(MathSqrt mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)
 
install (TARGETS MathSqrt DESTINATION bin)
install (FILES mysqrt.h DESTINATION include)

