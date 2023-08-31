#pragma once
#include<vector>

class Point : public std::vector<double>
{
public:
    Point(const int& size);
    Point(const std::vector<double>& vector);

    std::vector<double> get_vector();
    double operator*(const Point& right) const; //inner product
    Point operator+(const Point& right) const; //coord-summ
    Point operator-(const Point& right) const;
};
