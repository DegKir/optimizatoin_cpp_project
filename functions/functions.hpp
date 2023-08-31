#pragma once
#include<vector>
#include"../matrix.hpp"
#include"point.hpp"

class Gradient : public std::vector<double>
{
public:
    Gradient(const int& size);
    Gradient(const std::vector<double>& vector);
};

class IFunction
{
public:
    virtual double get_learning_constant() const = 0 ;
    virtual double get_value(const Point& x) const = 0 ;
    virtual Gradient get_grad(const Point& x) const = 0 ;
    virtual ~IFunction()=default;
};

class Quadratic_function : public IFunction //f(x)=(x,Ax)+(b,x)
{
private:
    Matrix A_;
    Point b_;
    double learning_constant_;
public:
    Quadratic_function(const Matrix& A, const Point& b, const double& L);
    double get_learning_constant() const override;
    double get_value(const Point& x) const override;
    Gradient get_grad(const Point& x) const override;
};
