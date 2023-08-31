#include"functions.hpp"
#include"../matrix.hpp"
#include<vector>
#include<algorithm>
#include<iostream>

Gradient::Gradient(const int& size) : std::vector<double>(size) {};
Gradient::Gradient(const std::vector<double>& vector) : std::vector<double>(vector) {};

//Quadratic_function::Quadratic_function():A_(),b_(),learning_constant_(0){}

Quadratic_function::Quadratic_function(const Matrix& A, const Point& b, const double& L):
                                        A_(A),b_(b),learning_constant_(L) {}

double Quadratic_function::get_learning_constant() const
{
    return learning_constant_;
}

double Quadratic_function::get_value(const Point& x) const
{
    return x*(A_*x)+b_*x;
}

Gradient Quadratic_function::get_grad(const Point& x) const
{
    Point part_grad(A_*x);
    std::for_each(part_grad.begin(), part_grad.end(),[](double& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    return Gradient(static_cast< const std::vector<double>&>(b_+A_*x));
}
