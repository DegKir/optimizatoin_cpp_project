#pragma once
#include<vector>
#include"functions/point.hpp"

class Matrix
{
private:
    std::vector<std::vector<double> > matrix_;
public:
    Matrix(const std::vector<std::vector<double> >&);
    Point operator*(const Point& point) const;
};
