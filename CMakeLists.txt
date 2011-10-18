cmake_minimum_required(VERSION 2.6.2)

# Set package properties
project(brepbuffer)

###
# Perform build configuration of dependencies
###
find_package(Protobuf REQUIRED)

###
# Build the project
###

set(BREPBUFFER_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${PROTOBUF_INCLUDE_DIRS})
set(BREPBUFFER_LIBRARIES brepbuffer)

add_subdirectory(brepbuffer)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	# We're our own project
	set(BREPBUFFER_BUILD_APPLICATIONS ON)
else()
	# We're a subproject
	set(BREPBUFFER_INCLUDE_DIRS ${BREPBUFFER_INCLUDE_DIRS} PARENT_SCOPE)
	set(BREPBUFFER_LIBRARIES ${BREPBUFFER_LIBRARIES} PARENT_SCOPE)
endif()

if(BREPBUFFER_BUILD_APPLICATIONS)
	if(NOT BREPBUFFER_DUMP_APP_COMPONENT)
		set(BREPBUFFER_DUMP_APP_COMPONENT dumpbrepbuffer)
	endif()
	if(NOT BREPBUFFER_DUMP_APP_DESTINATION)
		set(BREPBUFFER_DUMP_APP_DESTINATION bin)
	endif()
	add_subdirectory(applications)
endif()
