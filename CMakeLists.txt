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
	add_subdirectory(applications)
else()
	# We're a subproject
	set(BREPBUFFER_INCLUDE_DIRS ${BREPBUFFER_INCLUDE_DIRS} PARENT_SCOPE)
	set(BREPBUFFER_LIBRARIES ${BREPBUFFER_LIBRARIES} PARENT_SCOPE)
endif()
