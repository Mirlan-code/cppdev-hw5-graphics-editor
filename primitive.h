#pragma once

struct Primitive {

};

struct Color {
    Color(int c) : color(c)
    {}

    int color;
};

struct Point : public Primitive {
    Point(int x, int y, Color c) : x(x), y(y), color(c)
    {}

    int x, y;
    Color color;
};

struct Line : public Primitive {
    Point start, end;
    Color color;
};

