#pragma once

#include <memory>
#include "Internal.h"

namespace Clank
{

class Program;

class Kernel
{
public:
    typedef std::shared_ptr<Kernel> Ptr;

    Kernel(std::shared_ptr<Program> program, const std::string &kernel);

private:
    cl::Kernel *_kernel;
};

}
