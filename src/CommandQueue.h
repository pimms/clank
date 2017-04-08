#pragma once

#include "Internal.h"

#include "Device.h"

namespace Clank
{

class Context;

class CommandQueue
{
public:
	typedef std::shared_ptr<CommandQueue> Ptr;

	static CommandQueue::Ptr Create(Context* ctx, Device::Ptr dev);

	~CommandQueue();

private:
	CommandQueue(Context* ctx, Device::Ptr dev);

	Device::Ptr _device;
	cl::CommandQueue *_comQueue;
};

}
