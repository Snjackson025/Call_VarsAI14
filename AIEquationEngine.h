#pragma once
#include "TriangleLayer.h"
#include <map>
#include <string>

class AIEquationEngine {
private:
    bool isRunning;

public:
    TriangleLayer triangleLayer;

    AIEquationEngine();
    ~AIEquationEngine();

    void Initialize();
    void Shutdown();

    double Solve(const std::string& goal,
        std::map<std::string, double> vars);

private:
    bool TrySolve(std::map<std::string, double>& vars,
        const std::string& goal);
};