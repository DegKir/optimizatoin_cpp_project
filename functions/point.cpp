#include"point.hpp"
#include<algorithm>
#include<numeric>
#include<vector>

Point::Point(const int& size) : std::vector<double>(size) {};
Point::Point(const std::vector<double>& vector) : std::vector<double>(vector) {};

std::vector<double> Point::get_vector()
{
    return static_cast<std::vector<double>&>(*this);
}
//check for size !
double Point::operator*(const Point& right) const //inner product
{
    //not very smart
    return std::inner_product((*this).begin(),(*this).end(),right.begin(),0.0);
}
//check for size
Point Point::operator+(const Point& right) const //coord-summ
{
    std::vector<double> vector(right.size());
    std::transform((*this).begin(),(*this).end(),right.begin(),vector.begin(),std::plus<double>());
    return Point(vector);
}

Point Point::operator-(const Point& right) const //coord-summ
{
    std::vector<double> vector(right.size());
    std::transform((*this).begin(),(*this).end(),right.begin(),vector.begin(),std::minus<double>());
    return Point(vector);
}
