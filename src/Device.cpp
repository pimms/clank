#include "Device.h"

namespace Clank
{


std::vector<Device::Ptr> Device::GetAllDevices(Type type)
{
	std::vector<cl::Device> native;
	native = GetAllNativeHandles(type);

	std::vector<Device::Ptr> clankDevs;

	for (auto &device : native) {
		clankDevs.push_back(std::make_shared<Device>(device));
	}

	return clankDevs;
}

Device::Ptr Device::GetFirstGPU()
{
	std::vector<cl::Device> devices = GetAllNativeHandles(Type::GPU);

	if (!devices.empty()) {
		return Ptr(new Device(devices.front()));
	}

	THROW("No GPU devices identified: %d", 15);
	return nullptr;
}

std::vector<cl::Device> Device::GetAllNativeHandles(Type type)
{
	int filter = 0;
	switch (type) {
		case Type::ANY:
			filter = CL_DEVICE_TYPE_ALL;
			break;
		case Type::GPU:
			filter = CL_DEVICE_TYPE_GPU;
			break;
		case Type::CPU:
			filter = CL_DEVICE_TYPE_CPU;
			break;
	}

	std::vector<cl::Platform> platforms;
	std::vector<cl::Device> devices;
	cl::Platform::get(&platforms);

	printf("Found %d platforms\n", (int)platforms.size());
	for (auto &platform : platforms) {
		platform.getDevices(filter, &devices);
		printf("Found %d devices\n", (int)devices.size());
	}

	return devices;
}


Device::Device(cl::Device nativeHandle):
	_handle(nativeHandle)
{
	_handle.getInfo(CL_DEVICE_NAME, &_deviceName);
	_handle.getInfo(CL_DEVICE_VENDOR, &_vendorName);
	_handle.getInfo(CL_DEVICE_PROFILE, &_deviceProfile);
	_handle.getInfo(CL_DEVICE_OPENCL_C_VERSION, &_clVersion);
	_handle.getInfo(CL_DEVICE_EXTENSIONS, &_extensions);

	cl_device_type type;
	_handle.getInfo(CL_DEVICE_TYPE, &type);
	switch (type) {
		case CL_DEVICE_TYPE_CPU:
			_type = Type::CPU;
			break;
		case CL_DEVICE_TYPE_GPU:
			_type = Type::GPU;
			break;
		default:
			_type = Type::ANY;
			THROW("Unsupported OpenCL device type: %d", (int)type);
			break;
	}
}

Device::~Device()
{

}

std::string Device::GetDeviceName() const
{
	return _deviceName;
}

std::string Device::GetVendorName() const
{
	return _vendorName;
}

std::string Device::GetDeviceProfile() const
{
	return _deviceProfile;
}

std::string Device::GetOpenCLVersion() const
{
	return _clVersion;
}

std::string Device::GetExtensions() const
{
	return _extensions;
}

Device::Type Device::GetType() const
{
	return _type;
}

std::string Device::GetTypeString() const
{
	switch (_type) {
		case CPU:
			return "CPU";
		case GPU:
			return "GPU";
		case ANY:
			return "ANY";
	}

	return "UNDEFINED";
}

cl::Device& Device::GetNativeHandle()
{
	return _handle;
}


}
