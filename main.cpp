#include "AIEquationEngine.h"
#include <map>

int main() {
    AIEquationEngine engine;

    engine.Initialize();

    std::map<std::string, double> vars;
    vars["a"] = 3;
    vars["b"] = 4;

    engine.Solve("perimeter", vars);

    return 0;
}
