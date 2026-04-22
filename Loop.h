#include "State.h"

class Loop
{
public:
    void Tick();

private:
    void ProcessInput();
    void Update();
    void Output();

    State m_state;
};
