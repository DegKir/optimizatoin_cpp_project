#include<vector>
#include"main_cycle.hpp"
#include"functions/functions.hpp"
#include"decline_method/decline.hpp"
#include"readfile.hpp"
#include"state.hpp"
#include"log.hpp"


//nado budet udalit
#include"iostream"

main_cycle::main_cycle(IFunction& function, std::shared_ptr<IDecline_method> method, ICriteria& criteria, State& start) :
 function_(function), criteria_(criteria), current_state_(start), log_(start)
{
    method_ = std::move(method);
    criteria_fullfiled_=false;
}

bool main_cycle::check_criteria()
{
    return criteria_fullfiled_;
}

void main_cycle::step()
{
    State new_state=method_.get()->iteration(current_state_,function_,log_);
//    std::cout<<"hehe"<<std::endl;
//    if(criteria_.check(log_.get_prev(), new_state))
//    {
//        criteria_fullfiled_=true;
//    }
//    std::cout<<"huhu"<<std::endl;
    log_.update(new_state);
//    std::cout<<"lol"<<std::endl;
    current_state_=new_state;
}

Log main_cycle::get_log()
{
    return log_;
}
