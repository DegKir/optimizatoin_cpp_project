#include<vector>
#include"matrix.hpp"
#include<algorithm>
#include<numeric>
#include"functions/functions.hpp"

Matrix::Matrix(const std::vector<std::vector<double>>& matrix) : matrix_(matrix){}

Point Matrix::operator*(const Point& point) const
{
    int N = point.size();
    std::vector<double> vector(N);
    //assume that all sizes are compatable
    //maybe come back with something smarter then dumb cycle
    //also should add mpi at some point

    for(int i = 0; i < N; i++)
    {
        std::vector<double> tmp_col(matrix_[i]);
        vector[i]=std::inner_product(tmp_col.begin(), tmp_col.end(),point.begin(),0.0);
    }
    return Point(vector);
}
