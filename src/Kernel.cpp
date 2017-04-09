#include "Kernel.h"
#include "Program.h"

namespace Clank
{

Kernel::Kernel(std::shared_ptr<Program> program, const std::string &kernel)
{
    cl_int err = 0;
    _kernel = new cl::Kernel(program->GetNativeHandle(), kernel.c_str(), &err);
    if (err != CL_SUCCESS) {
        ERRTHROW(err, "Failed to create kernel");
    }
}

}
