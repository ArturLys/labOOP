#include "Triangle.h"

void Point::display() const {
    cout << "(" << this->x << ", " << this->y << ")\n";
}


double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::area() const {
    return heronArea(*this);
}

bool Triangle::contains(const Point& P) const {
    Triangle T1 = { A, B, P };
    Triangle T2 = { B, C, P };
    Triangle T3 = { C, A, P };

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    return fabs(S_main - S_sum) < 1e-9;
}

bool Triangle::isEdging(const Point& P) const {
    double C1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    double C2 = (C.x - B.x) * (P.y - B.y) - (C.y - B.y) * (P.x - B.x);
    double C3 = (A.x - C.x) * (P.y - C.y) - (A.y - C.y) * (P.x - C.x);
    return fabs(C1) < 1e-9 || fabs(C2) < 1e-9 || fabs(C3) < 1e-9;
}

bool Triangle::otherContains(const Point& P) const {

    double C1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    double C2 = (C.x - B.x) * (P.y - B.y) - (C.y - B.y) * (P.x - B.x);
    double C3 = (A.x - C.x) * (P.y - C.y) - (A.y - C.y) * (P.x - C.x);
    return !((signbit(C1)^signbit(C2))|(signbit(C2)^signbit(C3)));
}

bool Triangle::isDegenerate() const {
    return fabs(area()) < 1e-9;
}
