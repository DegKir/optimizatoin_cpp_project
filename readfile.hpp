#pragma once
#include"main_cycle.hpp"
#include"matrix.hpp"
#include"functions/point.hpp"
#include"decline_method/decline.hpp"
#include<fstream>
#include<memory>
//добавить считывание критерия

int read_size(std::ifstream&);
Matrix read_matrix(std::ifstream&, const int&);
double read_L(std::ifstream&);
Point read_right_b(std::ifstream&, const int&);
Point read_start_point(std::ifstream&, const int&);
std::shared_ptr<IDecline_method> read_method(std::ifstream&, const int&);

main_cycle read_main_cycle();
