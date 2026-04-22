#pragma once
#include "MathTypes.h"

enum EyeType
{
    EYE_LEFT = 0,
    EYE_RIGHT = 1
};

class VRDevice
{
public:
    VRDevice();

    Vec3 GetEyePosition(EyeType eye);

private:
    float ipd; // interpupillary distance
};