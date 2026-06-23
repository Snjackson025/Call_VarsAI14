cmake_minimum_required(VERSION 3.15)
project(Call_VarsAI14_Tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(RunTests
  MathTypesTest.cpp
  AIEngineTest.cpp
  VREngineTest.cpp
)

# Link with Google Test
target_link_libraries(RunTests
  gtest
  gtest_main
)

# Add include directories for source files
target_include_directories(RunTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Register tests with CTest
gtest_discover_tests(RunTests)
