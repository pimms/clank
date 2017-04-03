#pragma once

#include "Internal.h"
#include "Device.h"

namespace Clank
{

class Context
{
public:
	Context(Device::Ptr device);

private:
	Device::Ptr _device;
};

}


