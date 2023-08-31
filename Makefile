all:
	g++ -std=c++17 main.cpp functions/point.cpp state.cpp matrix.cpp log.cpp readfile.cpp main_cycle.cpp criteria.cpp functions/functions.cpp decline_method/decline.cpp -o main
