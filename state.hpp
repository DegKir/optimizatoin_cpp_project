#pragma once
#include"functions/functions.hpp"
#include"functions/point.hpp"

class State
{
private:
    Point point_;
    Gradient gradient_;
public:
//    State();
    State(const Point&,const Gradient&);
    Gradient get_grad() const;
    Point get_point() const;
};
