#pragma once
#include"../state.hpp"
#include"../log.hpp"
#include"../functions/functions.hpp"
#include"../decline_method/decline.hpp"
#include<string>
#include<memory>

class IDecline_method
{
public:
    virtual State iteration(const State&, const IFunction&, const Log&) const = 0;
    virtual double get_step(const IFunction&, const Log&) const = 0;
    virtual ~IDecline_method()=default;
};

class Classic_Decline : public IDecline_method
{
private:
    int dim_;
public:
    int get_dim();
    Classic_Decline(const int&);
    State iteration(const State&, const IFunction&, const Log&) const override;
    double get_step(const IFunction&, const Log&) const override;
};
//std::unique_ptr<IDecline_method> decline_methods_fabric(const std::string&, const int&);
std::shared_ptr<IDecline_method> decline_methods_fabric(const int&);
