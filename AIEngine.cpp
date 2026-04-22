#include "AIEngine.h"
#include <iostream>

AIEngine::AIEngine() : isRunning(false) {}

AIEngine::~AIEngine() {
    Shutdown();
}

void AIEngine::Initialize() {
    std::cout << "Initializing AI Engine..." << std::endl;
    // Any additional initialization tasks
    isRunning = true;
}

void AIEngine::Run() {
    std::cout << "AI Engine running. Type 'exit' to shut down." << std::endl;
    while (isRunning) {
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit") {
            Shutdown();
        }
        else {
            ProcessInput(input);
        }
    }
}

void AIEngine::ProcessInput(const std::string& input) {
    std::cout << "Processing input: " << input << std::endl;
    // Add logic here to handle different types of inputs.
    // For example, you could implement command processing.
}

void AIEngine::Shutdown() {
    std::cout << "Shutting down AI Engine..." << std::endl;
    isRunning = false;
    // Perform cleanup tasks here (if any).
}
