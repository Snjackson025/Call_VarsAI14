#pragma once

#include <string>
#include <unordered_map>

class Memory
{
private:
    std::unordered_map<std::string, std::string> data;

public:
    void Store(const std::string& key, const std::string& value);
    std::string Retrieve(const std::string& key);

    void SaveToFile(const std::string& filename);
    void LoadFromFile(const std::string& filename);
};
