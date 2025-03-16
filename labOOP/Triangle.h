#pragma once
#include "template.h"

struct Point {
    double x, y;
    Point(double x_, double y_) : x(x_), y(y_) {}
    void display() const;
};

double distance(const Point& p1, const Point& p2);

struct Triangle {
    Point A, B, C;
    Triangle(Point a, Point b, Point c) : A(a), B(b), C(c) {}

    double area() const;
    bool contains(const Point& P) const;
    bool isEdging(const Point& P) const;
    bool otherContains(const Point& P) const;
    bool isDegenerate() const;
};
