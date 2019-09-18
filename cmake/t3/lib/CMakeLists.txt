set(LIBHELLO_SRC hello.c)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) # set library output path
message(status " LIBRARY_OUTPUT_PATH: " ${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})        # add shared library
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC}) # add static library

SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1) # don't clean already exist library file has the same name
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME hello) # set static libray name to hello too
GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
message(status " this is the hello_static output_name: " ${OUTPUT_VALUE})

# add version for shared library. 1.2 is lib version, 1 is API verion
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

INSTALL(TARGETS hello hello_static 
		LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/library    # install shared library
		ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/library)   # install static library

INSTALL(FILES hello.h DESTINATION ${PROJECT_BINARY_DIR}/include)  # install header files
