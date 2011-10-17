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
#include <brepbuffer/BrepBufferFile.h>
#include <brepbuffer/Topology.pb.h>

// Library/third-party includes
// - none

// Standard includes
#include <string>
#include <iostream>


int main(int argc, char * argv[]) {
	if (argc < 2) {
		std::cerr << "ERROR: Must specify a file containing a brepbuffer!" << std::endl;
		return 1;
	}
	std::string fn = argv[1];
	brepbuffer::topo::Part * brep = readBrepBuffer(fn);
	std::cout << brep->DebugString() << std::endl;
	return 0;
}
