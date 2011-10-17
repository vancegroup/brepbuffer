include_directories(${BREPBUFFER_INCLUDE_DIRS})
add_executable(dumpbrepbuffer DumpBrepBuffer.cpp)
target_link_libraries(dumpbrepbuffer ${BREPBUFFER_LIBRARIES})
