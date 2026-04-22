#include "VRRenderer.h"
#include <iostream>

void VRRenderer::Initialize()
{
    // Copper color (RGB normalized)
    copperColor = Vec3(0.72f, 0.45f, 0.20f);
}

void VRRenderer::RenderEye(const Vec3& eyePos, float rotation)
{
    Matrix4 rot = Matrix4::RotationY(rotation);

    std::cout << "Rendering Eye at ("
        << eyePos.x << ", "
        << eyePos.y << ", "
        << eyePos.z << ") ";

    std::cout << "Rotation: " << rotation << " degrees ";

    std::cout << "Color (Copper): ("
        << copperColor.x << ", "
        << copperColor.y << ", "
        << copperColor.z << ")\n";
}