#include "Internal.h"
#include <vector>
#include <memory>

namespace Clank
{

class Device
{
public:
	typedef std::shared_ptr<Device> Ptr;

	enum Type {
		ANY,
		GPU,
		CPU,
	};

	// Retrieve all available OpenCL-devices. All instances
	// will be fully initialized upon return. If no available
	// devices exists, this method returns an empty vector.
	static std::vector<Device::Ptr> GetAllDevices(Type=ANY);

	// Retrieve the first GPU device. If no such device exists,
	// an exception is raised.
	static Device::Ptr GetFirstGPU();

	// Retrieve all native handles. For simplicity, avoid using
	// this, as the GetAllDevices() and GetFirstGPU() methods
	// wrap this nicely for you.
	static std::vector<cl::Device> GetAllNativeHandles(Type=ANY);

	Device(cl::Device nativeHandle);
	~Device();

	std::string GetDeviceName() const;
	std::string GetVendorName() const;
	std::string GetDeviceProfile() const;
	std::string GetOpenCLVersion() const;
	std::string GetExtensions() const;

	cl::Device& GetNativeHandle();

private:
	cl::Device _handle;

	std::string _deviceName;
	std::string _vendorName;
	std::string _deviceProfile;
	std::string _clVersion;
	std::string _extensions;
};

}

