#pragma once

#include "Internal.h"
#include "Device.h"
#include "CommandQueue.h"

namespace Clank
{


/**
 * Context is the "root" object in OpenCL and Clank, and is
 * also the only object where using a shared-pointer is not
 * enforced. Allocate and pass it around however you wish.
 */
class Context
{
public:
	Context(Device::Ptr device);
	~Context();

	CommandQueue::Ptr GetCommandQueue() const;

	cl::Context& GetNativeHandle();
	const cl::Context& GetNativeHandle() const;

private:
	Device::Ptr _device;
	CommandQueue::Ptr _commandQueue;

	cl::Context *_context;
};


}


