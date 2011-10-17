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
#ifndef INCLUDED_assignVec3Buf_h_GUID_6b1c9b69_9596_46d4_b24e_8caf1e58d7bd
#define INCLUDED_assignVec3Buf_h_GUID_6b1c9b69_9596_46d4_b24e_8caf1e58d7bd

// Internal Includes
#include <brepbuffer/Vec3.pb.h>

// Library/third-party includes
// - none

// Standard includes
// - none

namespace brepbuffer {
	template<typename T>
	inline void assign(Vec3* dest, T const vec[3]) {
		dest->set_x(vec[0]);
		dest->set_y(vec[1]);
		dest->set_z(vec[2]);
	}
	template<typename T>
	inline Vec3 toVec3(T const vec[3]) {
		Vec3 dest;
		assign(&dest, vec);
		return dest;
	}
}

#endif // INCLUDED_assignVec3Buf_h_GUID_6b1c9b69_9596_46d4_b24e_8caf1e58d7bd
