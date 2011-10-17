/**
	@file
	@brief Implementation

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Internal Includes
#include "BrepBufferFile.h"

#include "brepbuffer/Topology.pb.h"

// Library/third-party includes
// - none

// Standard includes
#include <fstream>


void writeBrepBuffer(brepbuffer::topo::Part * part, std::string const& filename, unsigned int compressionLevel) {
	std::ofstream outs(filename.c_str(), std::ios_base::out | std::ios_base::binary);
	part->SerializeToOstream(&outs);
}


brepbuffer::topo::Part * readBrepBuffer(std::string const& filename) {
	std::ifstream ins(filename.c_str(), std::ios_base::in | std::ios_base::binary);
	brepbuffer::topo::Part * ret = brepbuffer::topo::Part::default_instance().New();
	ret->ParseFromIstream(&ins);
	return ret;
}
