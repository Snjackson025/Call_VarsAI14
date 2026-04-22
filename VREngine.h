#pragma once
#include "VRDevice.h"
#include "VRRenderer.h"

class VREngine
{
public:
    VREngine();

    void Initialize();
    void Update(float deltaTime);
    void Render();

private:
    VRDevice device;
    VRRenderer renderer;

    float rotation; // 0 → 360 degrees
};