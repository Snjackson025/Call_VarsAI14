#pragma once
#include <vector>
#include <string>
#include <functional>
#include <map>

struct Equation {
    std::string name;
    std::vector<std::string> inputs;
    std::string output;

    std::function<double(std::map<std::string, double>&)> solve;
};

class TriangleLayer {
public:
    std::vector<Equation> equations;

    void Initialize();
};