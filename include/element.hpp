#pragma once

#include <image.hpp>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>

class Element
{
public:
    virtual void draw(Image &img) = 0;
    virtual ~Element() = default;
};

class Line : public Element
{

public:
    int xA, yA;
    int xB, yB;
    Vector3f color;
    void draw(Image &img) override
    {
        int x, y, dx, dy, e, d;
        dx = abs(xA - xB), dy = abs(yA - yB);
        if (dy < dx)
        {
            if (xA > xB)
                std::swap(xA, xB), std::swap(yA, yB);
            d = yA > yB ? -1 : 1;
            x = xA, y = yA, e = -dx;
            for (int i = 0; i <= dx; i++)
            {
                img.SetPixel(x, y, color);
                x++, e += 2 * dy;
                if (e >= 0)
                    y += d, e -= 2 * dx;
            }
        }
        else
        {
            if (yA > yB)
                std::swap(xA, xB), std::swap(yA, yB);
            d = xA > xB ? -1 : 1;
            x = xA, y = yA, e = -dy;
            for (int i = 0; i <= dy; i++)
            {
                img.SetPixel(x, y, color);
                y++, e += 2 * dx;
                if (e >= 0)
                    x += d, e -= 2 * dy;
            }
        }
        printf("Draw a line from (%d, %d) to (%d, %d) using color (%f, %f, %f)\n", xA, yA, xB, yB,
               color.x(), color.y(), color.z());
    }
};

class Circle : public Element
{

public:
    int cx, cy;
    int radius;
    Vector3f color;
    void draw(Image &img) override
    {
        int x, y, d;
        x = 0, y = radius, d = 5 - 4 * radius;
        img.SetPixel(x + cx, y + cy, color);img.SetPixel(-x + cx, y + cy, color);
        img.SetPixel(-x + cx, -y + cy, color);img.SetPixel(x + cx, -y + cy, color);
        img.SetPixel(y + cx, x + cy, color);img.SetPixel(-y + cx, x + cy, color);
        img.SetPixel(y + cx, -x + cy, color);img.SetPixel(-y + cx, -x + cy, color);
        while (x <= y)
        {
            if (d < 0)
                d += 8 * x + 12;
            else
                d += 8 * (x - y) + 20, y--;
            x++;
            img.SetPixel(x + cx, y + cy, color);img.SetPixel(-x + cx, y + cy, color);
            img.SetPixel(-x + cx, -y + cy, color);img.SetPixel(x + cx, -y + cy, color);
            img.SetPixel(y + cx, x + cy, color);img.SetPixel(-y + cx, x + cy, color);
            img.SetPixel(y + cx, -x + cy, color);img.SetPixel(-y + cx, -x + cy, color);
        }
        printf("Draw a circle with center (%d, %d) and radius %d using color (%f, %f, %f)\n", cx, cy, radius,
               color.x(), color.y(), color.z());
    }
};

class Fill : public Element
{

public:
    int cx, cy;
    Vector3f color;
    void draw(Image &img) override
    {
        if (img.GetPixel(cx, cy) != color)
        {
            std::queue<std::pair<int, int>> node;
            node.push(std::pair<int, int>(cx, cy));
            bool judge[img.Width()][img.Height()]={0};
            int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
            while (!node.empty())
            {
                std::pair<int, int> now = node.front();
                std::pair<int, int> next;
                node.pop();
                judge[now.first][now.second] = true;
                for (int i = 0; i <= 3; i++)
                {
                    next.first = now.first + dx[i], next.second = now.second + dy[i];
                    if (next.first >= 0 && next.first < img.Width() && next.second >= 0 && next.second < img.Height() && !judge[next.first][next.second]&&img.GetPixel(now.first,now.second)==img.GetPixel(next.first,next.second))
                    {
                        node.push(next);
                        judge[next.first][next.second]=true;
                    }
                }
                img.SetPixel(now.first, now.second, color);
            }
        }
        printf("Flood fill source point = (%d, %d) using color (%f, %f, %f)\n", cx, cy,
               color.x(), color.y(), color.z());
    }
};