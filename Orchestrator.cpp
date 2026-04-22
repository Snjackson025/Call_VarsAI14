#include "Orchestrator.h"
#include <sstream>

// Initialize system
void Orchestrator::Initialize()
{
    memory.LoadFromFile("memory.txt");
    state = "idle";
}

// Core execution logic
std::string Orchestrator::Execute(const std::string& input)
{
    std::istringstream iss(input);
    std::string command, key, value;

    iss >> command >> key;
    std::getline(iss, value);

    if (!value.empty() && value[0] == ' ')
        value.erase(0, 1);

    // STATE CONTROL
    if (command == "state")
    {
        if (!key.empty())
        {
            state = key;
            return "State changed to " + state;
        }
        return "Current state: " + state;
    }

    // MEMORY COMMANDS
    if (command == "set" && !key.empty() && !value.empty())
    {
        memory.Store(key, value);
        return key + " set to " + value;
    }

    if (command == "get" && !key.empty())
    {
        return memory.Retrieve(key);
    }

    if (command == "save")
    {
        memory.SaveToFile("memory.txt");
        return "Memory saved.";
    }

    if (command == "load")
    {
        memory.LoadFromFile("memory.txt");
        return "Memory loaded.";
    }

    // INTELLIGENCE LAYER
    if (input.find("hello") != std::string::npos)
    {
        std::string name = memory.Retrieve("name");

        if (name != "undefined")
            return "Hello, " + name + ". State: " + state;

        return "Hello. I don't know your name yet.";
    }

    if (input.find("how are you") != std::string::npos)
    {
        std::string mood = memory.Retrieve("mood");

        if (mood != "undefined")
            return "I am feeling " + mood + ".";

        return "I am operational.";
    }

    if (input.find("who am i") != std::string::npos)
    {
        return memory.Retrieve("name");
    }

    // STATE-BASED BEHAVIOR
    if (state == "learning")
    {
        memory.Store("last_input", input);
        return "Learning from input...";
    }

    if (state == "idle")
    {
        return "Idle...";
    }

    return "Unknown command";
}