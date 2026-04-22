#pragma once

#include <string>
#include "Memory.h"

class Orchestrator
{
private:
    Memory memory;
    std::string state;

public:
    void Initialize();
    std::string Execute(const std::string& input);
};
