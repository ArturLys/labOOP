#pragma once
#include "template.h"

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2);

struct Triangle {
    Point A, B, C;

    double area() const;
    bool contains(const Point& P) const;
    bool isDegenerate() const;
};

double heronArea(const Triangle& t);