#pragma once
#include <cmath>

// =======================
// 3D Vector
// =======================
struct Vec3
{
    float x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3 operator-(const Vec3& v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    Vec3 operator*(float s) const
    {
        return Vec3(x * s, y * s, z * s);
    }
};

// =======================
// Matrix 4x4
// =======================
struct Matrix4
{
    float m[4][4];

    static Matrix4 Identity()
    {
        Matrix4 mat = {};
        for (int i = 0; i < 4; i++)
            mat.m[i][i] = 1.0f;
        return mat;
    }

    static Matrix4 Translation(const Vec3& t)
    {
        Matrix4 mat = Identity();
        mat.m[0][3] = t.x;
        mat.m[1][3] = t.y;
        mat.m[2][3] = t.z;
        return mat;
    }

    static Matrix4 RotationY(float angle)
    {
        Matrix4 mat = Identity();
        float c = cos(angle);
        float s = sin(angle);

        mat.m[0][0] = c;
        mat.m[0][2] = s;
        mat.m[2][0] = -s;
        mat.m[2][2] = c;

        return mat;
    }

    Vec3 Multiply(const Vec3& v) const
    {
        Vec3 result;

        result.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
        result.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
        result.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];

        return result;
    }
};
