#include "Rasterizer.h"

// Constructor
Rasterizer::Rasterizer(int width, int height)
    : m_width(width), m_height(height),
    m_buffer(width* height)
{
}

// Destructor
Rasterizer::~Rasterizer()
{
}

// Clear screen
void Rasterizer::Clear(const Color& color)
{
    for (auto& pixel : m_buffer)
    {
        pixel = color;
    }
}

// Bounds check
bool Rasterizer::IsInside(int x, int y) const
{
    return (x >= 0 && x < m_width && y >= 0 && y < m_height);
}

// Draw pixel
void Rasterizer::DrawPixel(int x, int y, const Color& color)
{
    if (!IsInside(x, y)) return;

    m_buffer[y * m_width + x] = color;
}

// Bresenham Line Algorithm
void Rasterizer::DrawLine(const Vec2& p0, const Vec2& p1, const Color& color)
{
    int x0 = static_cast<int>(p0.x);
    int y0 = static_cast<int>(p0.y);
    int x1 = static_cast<int>(p1.x);
    int y1 = static_cast<int>(p1.y);

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        DrawPixel(x0, y0, color);

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

// Get buffer
const std::vector<Color>& Rasterizer::GetBuffer() const
{
    return m_buffer;
}