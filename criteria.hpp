#pragma once
#include "state.hpp"

class ICriteria
{
public:
    virtual bool check(const State& old_state,const State& new_state) const = 0;
    virtual ~ICriteria()=default;
};

class Cauchy : public ICriteria
{
public:
    Cauchy();
    bool check(const State& old_state, const State& new_state) const override;
};
