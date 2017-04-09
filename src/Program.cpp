#include "Program.h"
#include "Context.h"

#include <fstream>

namespace Clank
{

Program::Ptr Program::CreateFromFile(const Context *context, const std::string &path)
{
    std::ifstream f(path);
    if (!f.good()) {
        THROW("Failed to open file '%s'", path.c_str());
    }

    std::string src((std::istreambuf_iterator<char>(f)),
                     std::istreambuf_iterator<char>());

    return CreateFromSource(context, src);
}

Program::Ptr Program::CreateFromSource(const Context *context, const std::string &source)
{
    return Ptr(new Program(context, source));
}

Program::Program(const Context *context, const std::string &source):
    _program(nullptr)
{
    std::vector<std::string> vec;
    vec.push_back(source);

    cl_int err = 0;

    _program = new cl::Program(context->GetNativeHandle(), source, true, &err);
    if (err != CL_SUCCESS) {
        ERRTHROW(err, "Failed to create/build Program");
    }
}

Program::~Program()
{
    if (_program != nullptr) {
        delete _program;
    }
}

const cl::Program& Program::GetNativeHandle() const
{
    return *_program;
}

}
