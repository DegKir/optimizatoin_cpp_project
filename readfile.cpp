#include<vector>
#include"functions/functions.hpp"
#include"decline_method/decline.hpp"
#include"main_cycle.hpp"
#include"criteria.hpp"
#include"state.hpp"
#include"log.hpp"
#include"readfile.hpp"
#include<fstream>
#include<iostream>
#include"matrix.hpp"
#include<string>
#include<memory>

main_cycle read_main_cycle()
{
    std::ifstream file;
    file.open("config.txt");
    int N = read_size(file);
    Matrix A = read_matrix(file, N);
    double L = read_L(file);
    Point b = read_right_b(file, N);
    Point start_point = read_start_point(file, N);
    std::shared_ptr<IDecline_method> ptr_method = read_method(file, N);
    Quadratic_function function(A,b,L);
//    Classic_Decline decline(N);
    Cauchy criterion;

    Point zero_point(std::vector<double>{0,0,0});
    Gradient gradient = function.get_grad(zero_point);
    State start_state(zero_point, gradient);

    main_cycle cycle(function, std::move(ptr_method), criterion, start_state);
    file.close();
    return cycle;
}

int read_size(std::ifstream& file)
{
    int size;
    file >> size;
    return size;
}
Matrix read_matrix(std::ifstream& file, const int& size)
{
    std::vector<std::vector<double>> v;
    v.reserve(size);
    for(int i = 0; i < size; i++)
    {
        v[i].resize(size);
        for(int j = 0; j < size; j++)
        {
            file >> v[i][j];
        }
    }
    return Matrix(v);
}

double read_L(std::ifstream& file)
{
    double L = -1;
    file >> L;
    return L;
}

Point read_right_b(std::ifstream& file, const int& size)
{
    std::vector<double> v;
    v.resize(size);
    for(int i = 0; i < size; i++)
    {
        file >> v[i];
    }
    return Point(v);
}

Point read_start_point(std::ifstream& file, const int& size)
{
    std::vector<double> v;
    v.resize(size);
    for(int i = 0; i < size; i++)
    {
        file >> v[i];
    }
    return Point(v);
}

//WTF NOT WORKING
std::shared_ptr<IDecline_method> read_method(std::ifstream& file, const int& size)
{
//    std::string method_name("classic");
//    getline(file, method_name);
//    getline(file, method_name);
//    getline(file, method_name);
//    std::cout << "method :"<< method_name<<std::endl;

//    std::cout << "A";
    return decline_methods_fabric( size);
}
