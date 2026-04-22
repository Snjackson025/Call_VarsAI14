#include "TriangleLayer.h"
#include <cmath>

void TriangleLayer::Initialize() {

    equations.clear();

    // ---------- Pythagorean ----------
    Equation pyth;
    pyth.name = "Pythagorean";
    pyth.inputs = std::vector<std::string>{ "a", "b" };
    pyth.output = "c";
    pyth.solve = [](std::map<std::string, double>& vars) {
        double a = vars["a"];
        double b = vars["b"];
        double c = std::sqrt(a * a + b * b);
        vars["c"] = c;
        return c;
        };
    equations.push_back(pyth);

    // ---------- Area ----------
    Equation area;
    area.name = "Area";
    area.inputs = std::vector<std::string>{ "base", "height" };
    area.output = "area";
    area.solve = [](std::map<std::string, double>& vars) {
        double result = 0.5 * vars["base"] * vars["height"];
        vars["area"] = result;
        return result;
        };
    equations.push_back(area);

    // ---------- Perimeter ----------
    Equation perim;
    perim.name = "Perimeter";
    perim.inputs = std::vector<std::string>{ "a", "b", "c" };
    perim.output = "perimeter";
    perim.solve = [](std::map<std::string, double>& vars) {
        double result = vars["a"] + vars["b"] + vars["c"];
        vars["perimeter"] = result;
        return result;
        };
    equations.push_back(perim);
}