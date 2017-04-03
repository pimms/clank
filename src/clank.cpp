#include "Internal.h"
#include <stdio.h>
#include "Device.h"
#include <getopt.h>

void PrintHelp(const char *invokation)
{
	printf("Usage: %s [options]\n", invokation);
	printf("\n");
	printf("Options:\n");

	printf("  -p:\n");
	printf("  Print all available devices.\n");
}

void PrintDevices()
{
	std::vector<Clank::Device::Ptr> devs = Clank::Device::GetAllDevices();
	for (auto d : devs) {
		printf("Device:     %s\n", d->GetDeviceName().c_str());
		printf("Vendor:     %s\n", d->GetVendorName().c_str());
		printf("CLVersion:  %s\n", d->GetOpenCLVersion().c_str());
		printf("Profile:    %s\n", d->GetDeviceProfile().c_str());
		printf("Extensions: %s\n", d->GetExtensions().c_str());
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	try {
		if (argc <= 1) {
			PrintHelp(argv[0]);
			return 1;
		}

		int ch = 0;
		while ((ch = getopt(argc, argv, "d")) != -1) {
			switch (ch) {
				case 'd':
					PrintDevices();
					return 0;

				default:
					PrintHelp(argv[0]);
					return 1;
			}
		}
	} catch (Clank::Exception ex) {
		printf("\n\n");
		printf("Exception caught:\n");
		printf("%s\n", ex.what());
		return 1;
	}

    return 0;
}
