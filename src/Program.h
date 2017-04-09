#pragma once

#include "Internal.h"

namespace Clank
{

class Context;

class Program
{
public:
    typedef std::shared_ptr<Program> Ptr;

    Ptr CreateFromFile(const Context *context, const std::string &path);
    Ptr CreateFromSource(const Context *context, const std::string &source);

    ~Program();

    const cl::Program& GetNativeHandle() const;

private:
    Program(const Context *context, const std::string &source);

    cl::Program *_program;
};

}
