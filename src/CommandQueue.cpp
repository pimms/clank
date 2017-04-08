#include "CommandQueue.h"
#include "Context.h"


namespace Clank
{

CommandQueue::Ptr CommandQueue::Create(Context* ctx, Device::Ptr dev)
{
	return CommandQueue::Ptr(new CommandQueue(ctx, dev));
}


CommandQueue::CommandQueue(Context* ctx, Device::Ptr dev):
	_device(dev),
	_comQueue(nullptr)
{
	_comQueue = new cl::CommandQueue(ctx->GetNativeHandle());
}

CommandQueue::~CommandQueue()
{
	if (_comQueue) {
		delete _comQueue;
	}
}

}

