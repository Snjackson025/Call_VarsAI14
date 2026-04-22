#pragma once

#include <vector>

// Simple color struct
struct Color
{
    unsigned char r, g, b, a;

    Color(unsigned char r = 0, unsigned char g = 0,
        unsigned char b = 0, unsigned char a = 255)
        : r(r), g(g), b(b), a(a) {
    }
};

// Simple 2D point
struct Vec2
{
    float x, y;

    Vec2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
};

class Rasterizer
{
public:
    Rasterizer(int width, int height);
    ~Rasterizer();

    void Clear(const Color& color);
    void DrawPixel(int x, int y, const Color& color);
    void DrawLine(const Vec2& p0, const Vec2& p1, const Color& color);

    const std::vector<Color>& GetBuffer() const;

private:
    int m_width;
    int m_height;
    std::vector<Color> m_buffer;

    bool IsInside(int x, int y) const;
};
