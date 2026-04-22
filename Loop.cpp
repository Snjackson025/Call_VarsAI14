#include "Loop.h"
#include <iostream>

void Loop::Tick()
{
    ProcessInput();
    Update();
    Output();
}

void Loop::ProcessInput()
{
    std::cout << "[Loop] Processing Input...\n";
}

void Loop::Update()
{
    std::cout << "[Loop] Updating State...\n";
}

void Loop::Output()
{
    std::cout << "[Loop] Outputting Results...\n";
}