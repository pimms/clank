#pragma once

#ifdef __APPLE__
	// I can't find the CL header to save my life, so I'm just
	// bringing my own header. Oh well.
	#ifdef YOU_COMPLETE_ME
		#include "macos/cl.h"
	#else
		#include <OpenCL/OpenCL.h>
	#endif

	// Apple doesn't ship the C++ wrapper header by default,
	// so we need to supply our own. This one is nacked directly
	// from Khronos:
	// https://www.khronos.org/registry/OpenCL/api/2.1/cl.hpp
	#include "macos/cl.hpp"

#endif

// TODO: All the other platforms that exists


#include <stdexcept>


namespace Clank
{

typedef std::runtime_error Exception;

namespace Internal
{

void Throw(const char *file, const char *func, int line, const char *msg, ...);

}
}


#define THROW(MSG...) \
	Clank::Internal::Throw(__FILE__, __PRETTY_FUNCTION__, __LINE__, MSG)

