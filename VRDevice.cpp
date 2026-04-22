#include "VRDevice.h"

VRDevice::VRDevice() : ipd(0.064f) {}

Vec3 VRDevice::GetEyePosition(EyeType eye)
{
    if (eye == EYE_LEFT)
        return Vec3(-ipd * 0.5f, 0.0f, 0.0f);
    else
        return Vec3(ipd * 0.5f, 0.0f, 0.0f);
}