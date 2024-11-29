#pragma once
#include <cmath>

struct vector_point
{
    double       x{ 0 };
    double       y{ 0 };
    double       z{ 0 };
    double       length = sqrt(x * x + y * y + z * z);
    vector_point operator+(vector_point& vec) const { return { x + vec.x, y + vec.y }; }
    vector_point operator-(vector_point& vec) const { return { x - vec.x, y - vec.y }; }
    vector_point operator*(double& num) const { return { x * num, y * num }; }
    vector_point operator/(double& num) const { return { x / num, y / num }; }

    double dot_product(vector_point second) const { return x * second.x + y * second.y; }//³»Àû
    double get_angle() const { return atan2(y, x); }
    void set_angle(double angle, double leng)
    {
        x = cos(angle) * leng;
        y = sin(angle) * leng;
    }
};