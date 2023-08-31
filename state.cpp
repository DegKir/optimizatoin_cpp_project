#include"functions/functions.hpp"
#include"functions/point.hpp"
#include"state.hpp"
//State::State(){}
State::State(const Point& point, const Gradient& gradient): point_(point), gradient_(gradient){}

Gradient State::get_grad() const
{
    return gradient_;
}

Point State::get_point() const
{
    return point_;
}
