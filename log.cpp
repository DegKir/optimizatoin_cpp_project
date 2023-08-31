#include"state.hpp"
#include<vector>
#include"log.hpp"
#include<algorithm>
#include<numeric>
#include<iostream>
#include<cmath>

Log::Log()
{
    log_=std::vector<State>();
}

Log::Log(std::vector<State> history)
{
    log_=history;
}
Log::Log(const State& start)
{
    log_=std::vector<State>{start};
}
void Log::update(State new_state)
{
    log_.push_back(new_state);
}

State Log::get_prev()
{
    return log_[log_.size()-2];
}

State Log::get_last()
{
    return log_[log_.size()-1];
}

void Log::print()
{
    std::cout<<"size:"<<log_[0].get_point().size()<<std::endl;
    std::for_each(log_.begin(),log_.end(),
            [](State& state){
                Point po=state.get_point();
                std::cout<<"Point : ";
                std::for_each(po.begin(),po.end(),[](double& crd){std::cout<< crd <<" ";});
                std::cout<<std::endl;

                Gradient gra=state.get_grad();
                std::cout<<"Gradient : ";
                std::for_each(gra.begin(),gra.end(),[](double& crd){std::cout<< crd <<" ";});

                std::cout<<"\nNorm of gradient = ";
                double sq_sum = std::inner_product( gra.begin(), gra.end(), gra.begin(), 0.0 );
                std::cout<<std::sqrt(sq_sum)<<std::endl;
                std::cout<<std::endl<<std::endl;
            });
}
