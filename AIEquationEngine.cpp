#include "AIEquationEngine.h"
#include <iostream>

AIEquationEngine::AIEquationEngine() : isRunning(false) {}

AIEquationEngine::~AIEquationEngine() {
    Shutdown();
}

void AIEquationEngine::Initialize() {
    std::cout << "Initializing Call_Vars Engine..." << std::endl;

    triangleLayer.Initialize();

    isRunning = true;

    std::cout << "Triangle Layer Loaded: "
        << triangleLayer.equations.size()
        << " equations." << std::endl;
}

void AIEquationEngine::Shutdown() {
    if (isRunning) {
        std::cout << "Shutting down Call_Vars Engine..." << std::endl;
        isRunning = false;
    }
}

bool AIEquationEngine::TrySolve(std::map<std::string, double>& vars,
    const std::string& goal) {

    if (vars.find(goal) != vars.end()) {
        return true;
    }

    for (auto& eq : triangleLayer.equations) {

        if (eq.output == goal) {

            bool ready = true;

            for (const auto& input : eq.inputs) {
                if (vars.find(input) == vars.end()) {

                    if (!TrySolve(vars, input)) {
                        ready = false;
                        break;
                    }
                }
            }

            if (ready) {
                std::cout << "Solving: " << eq.name << std::endl;
                eq.solve(vars);
                return true;
            }
        }
    }

    return false;
}

double AIEquationEngine::Solve(const std::string& goal,
    std::map<std::string, double> vars) {

    std::cout << "\n--- Call_Vars Solve ---" << std::endl;

    if (TrySolve(vars, goal)) {
        std::cout << "Final Result (" << goal << "): "
            << vars[goal] << std::endl;
        return vars[goal];
    }
    else {
        std::cout << "Could not solve for: " << goal << std::endl;
        return 0.0;
    }
}