#include<iostream>
#include<vector>
#include"functions/functions.hpp"
#include"functions/point.hpp"
#include"decline_method/decline.hpp"
#include"readfile.hpp"
#include"criteria.hpp"
#include"matrix.hpp"
#include"main_cycle.hpp"
#include<algorithm>
#include<numeric>
#include"readfile.hpp"
#include<memory>

void easy_test()
{
    int N=3;
    Matrix A(std::vector<std::vector<double>>{  {2, -1, 0},
                                                {-1, 2, -1},
                                                {0, -1, 2}});
    Point b(std::vector<double>{10,10,30});

    Quadratic_function function(A,b,10);
    Cauchy criterion;

    Point zero_point(std::vector<double>{0,0,0});
    Gradient gradient = function.get_grad(zero_point);
    State start_state(zero_point, gradient);

    main_cycle cycle(function, std::make_unique<Classic_Decline>(N), criterion, start_state);

    std::cout<<"start point :"<<std::endl;
    for_each(zero_point.begin(),zero_point.end(),[](double& a){std::cout<<a<<std::endl;});
    std::cout<< "first grad :"<<std::endl;
    for_each(gradient.begin(), gradient.end(),[](double& a){std::cout<<a<<std::endl;});
    //making step

    std::cout<<"hehe"<<std::endl;
    for(int i = 0; i < 10; i++)
    {
        cycle.step();
    }
    std::cout<<"haha"<<std::endl;

    State result_state(cycle.get_log().get_last());
    Point result_point = result_state.get_point();
    Gradient result_gradient = result_state.get_grad();
    std::cout<<"end point :"<<std::endl;
    for_each(result_point.begin(),result_point.end(),[](double& a){std::cout<<a<<std::endl;});
    std::cout<< "end grad :"<<std::endl;
    for_each(result_gradient.begin(), result_gradient.end(),[](double& a){std::cout<<a<<std::endl;});

    cycle.get_log().print();
}

void config_mod()
{
    main_cycle cycle = read_main_cycle();
    for(int i = 0; i < 10; i++)
    {
        cycle.step();
    }

    cycle.get_log().print();

}

int main()
{
    config_mod();
    std::cout<<"kek";
    return 0;
}
