
#ADD_DEFINITIONS(-DENABLE_DEBUG -DABC)

set(BINARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
include_directories(../include)
AUX_SOURCE_DIRECTORY(. SRC_LIST)
add_executable(main ${SRC_LIST})
#TARGET_LINK_LIBRARIES(main hello)      # link shared library
TARGET_LINK_LIBRARIES(main libhello.a)  # link static library


message(status " #CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})
message(status " #PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})
message(status " #main_SOURCE_DIR: " ${main_SOURCE_DIR})

message(status " #CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message(status " #CMAKE_CURRENT_BINARY_DIR: " ${CMAKE_CURRENT_BINARY_DIR})

message(status " #CMAKE_CURRENT_LIST_FILE: " ${CMAKE_CURRENT_LIST_FILE})
message(status " #CMAKE_CURRENT_LIST_LINE: " ${CMAKE_CURRENT_LIST_LINE})

message(status " #CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})
message(status " #EXECUTABLE_OUTPUT_PATH: " ${EXECUTABLE_OUTPUT_PATH})
message(status " #LIBRARY_OUTPUT_PATH: " ${LIBRARY_OUTPUT_PATH})

message(status " #PROJECT_NAME: " ${PROJECT_NAME})
#install(FILES COPYRIGHT README DESTINATION share/doc/cmake/t2)
#install(PROGRAMS runhello.sh DESTINATION bin)
#install(DIRECTORY doc/ DESTINATION share/doc/cmake/t2)

