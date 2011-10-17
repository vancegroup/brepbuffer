/** @file
	@brief Header

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

#pragma once
#ifndef INCLUDED_BrepBufferFile_h_GUID_10f4ad98_4a09_4f7e_bfa5_7c7ea8b237d5
#define INCLUDED_BrepBufferFile_h_GUID_10f4ad98_4a09_4f7e_bfa5_7c7ea8b237d5

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
#include <string>

namespace brepbuffer {
	namespace topo {
		class Part;
	}
}

void writeBrepBuffer(brepbuffer::topo::Part * part, std::string const& filename, unsigned int compressionLevel = 9);
brepbuffer::topo::Part * readBrepBuffer(std::string const& filename);

#endif // INCLUDED_BrepBufferFile_h_GUID_10f4ad98_4a09_4f7e_bfa5_7c7ea8b237d5
