#pragma once
#include<vector>
#include"functions/functions.hpp"
#include"decline_method/decline.hpp"
#include"criteria.hpp"
#include"state.hpp"
#include"log.hpp"
#include<memory>
//you can't change gradient of point after object has been created

class main_cycle
{
private:
    State current_state_;
    Log log_;
    IFunction& function_;
    std::shared_ptr<IDecline_method> method_;
    ICriteria& criteria_;

    bool criteria_fullfiled_;

public:
    main_cycle(IFunction&, std::shared_ptr<IDecline_method>, ICriteria&, State&);
    bool check_criteria();
    Log get_log();
    void step();
};
