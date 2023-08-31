#pragma once
#include"state.hpp"
#include<vector>

class Log
{
private:
    std::vector<State> log_;
public:
    Log();
    Log(const State&);
    Log(std::vector<State>);
    void update(State);
    State get_prev();
    State get_last();
    void print();
};
