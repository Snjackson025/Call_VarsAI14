# Call_VarsAI14

**Synthetic AI — a VR engine project.**

## What it does

- **AIEquationEngine** — solves equations, including the Pythagorean
  triangle layer (a = 3, b = 4 gives hypotenuse 5 and perimeter 12)
- **VREngine, VRDevice, VRRenderer, VRInput** — the VR layer
- **AIEngine, Orchestrator, Memory, Loop, Rasterizer, MathTypes, Math3D**
  — the supporting systems

Run it and it initializes the Call_Vars engine, loads the triangle
layer, and prints the final result (perimeter): 12.

## Build and run

With Visual Studio, open the solution and build Debug x64. The exe
lands at `x64/Debug/Call_VarsAI14.exe`.

## Continuous integration

`.github/workflows/build-and-test.yml` builds Debug x64 with MSBuild and
runs the exe, failing unless it exits 0 and prints
"Final Result (perimeter): 12". It also runs daily at 06:00 UTC.
