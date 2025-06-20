#pragma once

#ifndef DIGIT_SUM
#define DIGIT_SUM

#include "common.hpp"
typedef std::vector<std::vector<std::vector<ll>>> llmatrix3d;

ll digit_sum_dp_rec(int i, int j, int k, std::string &ub,llmatrix3d &dp);

#endif //DIGIT_SUM