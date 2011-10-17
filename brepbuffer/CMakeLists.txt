
set(PROTO_FILES
	Geometry.proto
	Topology.proto
	Vec3.proto)
protobuf_generate_cpp(PROTO_SOURCES PROTO_HEADERS ${PROTO_FILES})
source_group(MessageDefinitions FILES ${PROTO_FILES})
source_group(GeneratedSources FILES ${PROTO_SOURCES})
source_group(GeneratedHeaders FILES ${PROTO_HEADERS})

set(HEADERS
	assignVec3Buf.h)
include_directories(${BREPBUFFER_INCLUDE_DIRS})
add_library(brepbuffer STATIC ${PROTO_FILES} ${PROTO_SOURCES} ${PROTO_HEADERS} ${HEADERS})
target_link_libraries(brepbuffer ${PROTOBUF_LIBRARIES})
