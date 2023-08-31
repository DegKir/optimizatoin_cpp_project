#include"criteria.hpp"
#include"functions/point.hpp"
#include<algorithm>
#include<cmath>

Cauchy::Cauchy(): ICriteria() {}

bool Cauchy::check(const State& old_state, const State& new_state) const
{
    bool answer;
    double error = 1E-2;//error should be modifiable
    Point old_point(old_state.get_point());
    Point diff = new_state.get_point() - old_state.get_point();
    double sq_dif_norm = 0;
    std::for_each(diff.begin(),diff.end(),[sq_dif_norm](double& a) mutable {sq_dif_norm+=a*a;});
    double dif_norm = std::sqrt(sq_dif_norm);
    (sq_dif_norm < error) ? answer=true : answer = false;
    return answer;
}
