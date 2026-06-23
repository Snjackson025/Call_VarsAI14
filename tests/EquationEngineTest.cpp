#include <gtest/gtest.h>
#include <map>
#include <cmath>
#include "../AIEquationEngine.h"

class EquationEngineTest : public ::testing::Test {
protected:
    AIEquationEngine engine;

    void SetUp() override {
        engine.Initialize();
    }

    void TearDown() override {
        engine.Shutdown();
    }
};

// ============ TEST 1: Verify All Equations Load ============
TEST_F(EquationEngineTest, EquationsLoadCorrectly) {
    ASSERT_EQ(engine.triangleLayer.equations.size(), 3) 
        << "Expected 3 equations to be loaded, but got " 
        << engine.triangleLayer.equations.size();
}

// ============ TEST 2: Verify Equation Names ============
TEST_F(EquationEngineTest, EquationNamesAreCorrect) {
    auto& eqs = engine.triangleLayer.equations;
    
    EXPECT_EQ(eqs[0].name, "Pythagorean");
    EXPECT_EQ(eqs[1].name, "Area");
    EXPECT_EQ(eqs[2].name, "Perimeter");
}

// ============ TEST 3: Verify Equation Inputs/Outputs ============
TEST_F(EquationEngineTest, EquationInputsOutputsAreCorrect) {
    auto& eqs = engine.triangleLayer.equations;
    
    // Pythagorean
    EXPECT_EQ(eqs[0].output, "c");
    EXPECT_EQ(eqs[0].inputs.size(), 2);
    EXPECT_EQ(eqs[0].inputs[0], "a");
    EXPECT_EQ(eqs[0].inputs[1], "b");
    
    // Area
    EXPECT_EQ(eqs[1].output, "area");
    EXPECT_EQ(eqs[1].inputs.size(), 2);
    
    // Perimeter
    EXPECT_EQ(eqs[2].output, "perimeter");
    EXPECT_EQ(eqs[2].inputs.size(), 3);
}

// ============ TEST 4: Pythagorean Theorem Calculation ============
TEST_F(EquationEngineTest, PythagoreanCalculationCorrect) {
    std::map<std::string, double> vars;
    vars["a"] = 3;
    vars["b"] = 4;
    
    // The Pythagorean theorem should produce c = 5
    double result = engine.Solve("c", vars);
    
    EXPECT_DOUBLE_EQ(result, 5.0) 
        << "Pythagorean: Expected c=5 for a=3, b=4, but got " << result;
    EXPECT_DOUBLE_EQ(vars["c"], 5.0);
}

// ============ TEST 5: Perimeter Calculation with Dependency Resolution ============
TEST_F(EquationEngineTest, PerimeterWithDependencyResolution) {
    std::map<std::string, double> vars;
    vars["a"] = 3;
    vars["b"] = 4;
    
    // This should:
    // 1. Recognize perimeter needs a, b, c
    // 2. Find c using Pythagorean (3, 4 -> 5)
    // 3. Calculate perimeter (3 + 4 + 5 = 12)
    double result = engine.Solve("perimeter", vars);
    
    EXPECT_DOUBLE_EQ(result, 12.0) 
        << "Perimeter: Expected 12 for a=3, b=4, but got " << result;
    EXPECT_TRUE(vars.find("c") != vars.end()) 
        << "Expected c to be calculated but it's missing from vars";
    EXPECT_DOUBLE_EQ(vars["c"], 5.0);
}

// ============ TEST 6: Area Calculation ============
TEST_F(EquationEngineTest, AreaCalculationCorrect) {
    std::map<std::string, double> vars;
    vars["base"] = 6;
    vars["height"] = 4;
    
    double result = engine.Solve("area", vars);
    
    EXPECT_DOUBLE_EQ(result, 12.0) 
        << "Area: Expected 12 for base=6, height=4 (0.5 * 6 * 4), but got " << result;
}

// ============ TEST 7: Missing Dependencies ============
TEST_F(EquationEngineTest, FailsGracefullyWithMissingDependencies) {
    std::map<std::string, double> vars;
    vars["a"] = 3;
    // Missing "b" for Pythagorean
    
    double result = engine.Solve("c", vars);
    
    EXPECT_EQ(result, 0.0) 
        << "Expected 0.0 when dependencies are missing, but got " << result;
}

// ============ TEST 8: Direct Value Already Exists ============
TEST_F(EquationEngineTest, ReturnDirectValueIfAlreadyExists) {
    std::map<std::string, double> vars;
    vars["perimeter"] = 42.0;
    
    double result = engine.Solve("perimeter", vars);
    
    EXPECT_EQ(result, 42.0) 
        << "Should return existing value without recalculation";
}

// ============ TEST 9: Larger Triangle ============
TEST_F(EquationEngineTest, LargerTrianglePerimeter) {
    std::map<std::string, double> vars;
    vars["a"] = 5;
    vars["b"] = 12;
    
    double result = engine.Solve("perimeter", vars);
    
    // c = sqrt(25 + 144) = sqrt(169) = 13
    // perimeter = 5 + 12 + 13 = 30
    EXPECT_DOUBLE_EQ(result, 30.0);
    EXPECT_DOUBLE_EQ(vars["c"], 13.0);
}

// ============ TEST 10: Equation Execution Callback ============
TEST_F(EquationEngineTest, EquationSolveCallbackWorks) {
    auto& eqs = engine.triangleLayer.equations;
    std::map<std::string, double> vars;
    vars["a"] = 3;
    vars["b"] = 4;
    
    // Directly call the Pythagorean solve function
    double result = eqs[0].solve(vars);
    
    EXPECT_DOUBLE_EQ(result, 5.0);
    EXPECT_DOUBLE_EQ(vars["c"], 5.0);
}
