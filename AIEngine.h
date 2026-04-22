#ifndef AI_ENGINE_H
#define AI_ENGINE_H

#include <string>

class AIEngine {
public:
    // Constructor and Destructor
    AIEngine();
    ~AIEngine();

    // Initializes the AI engine
    void Initialize();

    // Starts the main run loop
    void Run();

    // Processes user input
    void ProcessInput(const std::string& input);

    // Shuts down the AI engine
    void Shutdown();

private:
    bool isRunning; // Flag to control the run state of the engine
};

#endif // AI_ENGINE_H

