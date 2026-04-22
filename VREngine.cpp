#include "VREngine.h"

VREngine::VREngine() : rotation(0.0f) {}

void VREngine::Initialize()
{
    renderer.Initialize();
}

void VREngine::Update(float deltaTime)
{
    rotation += 90.0f * deltaTime;

    if (rotation >= 360.0f)
        rotation -= 360.0f;
}

void VREngine::Render()
{
    renderer.RenderEye(device.GetEyePosition(EYE_LEFT), rotation);
    renderer.RenderEye(device.GetEyePosition(EYE_RIGHT), rotation);
}