#include"../main_cycle.hpp"
#include"../functions/functions.hpp"
#include"decline.hpp"
#include<algorithm>
#include<iostream>
#include<string>
#include<memory>
#include<cassert>
//

Classic_Decline::Classic_Decline(const int& dim) :dim_(dim){}

State Classic_Decline::iteration(const State& current_state, const IFunction& function, const Log& log) const
{
//    size_t log_size = log.size();//number of previous steps

    Point new_point(current_state.get_point());
    Gradient old_gradient(current_state.get_grad());
    double step=this->get_step(function,log);
    //multiplying
    std::for_each(old_gradient.begin(),old_gradient.end(),[=](double &a){a=-1.0*a*step;});//-a*gradf(x)

    std::transform(new_point.begin(), new_point.end(), old_gradient.begin(), new_point.begin(), std::plus<double>());
    //now new_point is really new point;
    State next_state(new_point,function.get_grad(new_point));
    return next_state;
}

double Classic_Decline::get_step(const IFunction& function, const Log& log) const
{
    double L=function.get_learning_constant();
    return 1/L;
}

int Classic_Decline::get_dim()
{
    return dim_;
}

//НЕПРАВИЛЬНЫЙ КОД ИСПРАВЬ НУЖНО СДЕЛАТЬ УМНЫЙ УКАЗАТЕЛЬ
//std::unique_ptr<IDecline_method> decline_methods_fabric(const std::string& str, const int& size)
std::shared_ptr<IDecline_method> decline_methods_fabric( const int& size)
{
//    std::cout<<"kuku";
//    if(str == std::string("classic"))
//    {
    std::shared_ptr kek = std::make_shared<Classic_Decline>(3);
    std::cout<<typeid(kek).name();
//        return method;
//    }
    //there is no such decline method
    assert(false);
}
