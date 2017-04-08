#include "Context.h"

namespace Clank
{


Context::Context(Device::Ptr device):
	_device(device),
	_context(nullptr)
{
	std::vector<cl::Device> devs;
	devs.push_back(device->GetNativeHandle());
	_context = new cl::Context(devs);

	_commandQueue = CommandQueue::Create(this, _device);
}

Context::~Context()
{
	_commandQueue = nullptr;

	if (_context) {
		delete _context;
	}
}

CommandQueue::Ptr Context::GetCommandQueue() const
{
	return _commandQueue;
}

cl::Context& Context::GetNativeHandle()
{
	return *_context;
}

}
