#include "Memory.h"
#include <fstream>

void Memory::Store(const std::string& key, const std::string& value)
{
    data[key] = value;
}

std::string Memory::Retrieve(const std::string& key)
{
    if (data.find(key) != data.end())
        return data[key];

    return "undefined";
}

void Memory::SaveToFile(const std::string& filename)
{
    std::ofstream file(filename);

    for (const auto& pair : data)
    {
        file << pair.first << "=" << pair.second << std::endl;
    }
}

void Memory::LoadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        size_t pos = line.find("=");

        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            data[key] = value;
        }
    }
}