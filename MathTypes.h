#pragma once
#include <cmath>

#define DEG_TO_RAD(x) ((x) * 0.01745329251f)

struct Vec3
{
    float x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
};

struct Matrix4
{
    float m[16];

    static Matrix4 Identity()
    {
        Matrix4 mat;
        for (int i = 0; i < 16; i++) mat.m[i] = 0.0f;
        mat.m[0] = mat.m[5] = mat.m[10] = mat.m[15] = 1.0f;
        return mat;
    }

    static Matrix4 RotationY(float degrees)
    {
        float r = DEG_TO_RAD(degrees);
        Matrix4 mat = Identity();

        mat.m[0] = cos(r);
        mat.m[2] = sin(r);
        mat.m[8] = -sin(r);
        mat.m[10] = cos(r);

        return mat;
    }
};
