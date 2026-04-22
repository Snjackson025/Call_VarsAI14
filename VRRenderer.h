#pragma once
#include "MathTypes.h"

class VRRenderer
{
public:
    void Initialize();
    void RenderEye(const Vec3& eyePos, float rotation);

private:
    Vec3 copperColor;
};