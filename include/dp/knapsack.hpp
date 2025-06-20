#pragma once

#ifndef KNAPSACK
#define KNAPSACK

#include "common.hpp"

void knapsack_max(const int &n, const int &C,const std::vector<int> &weights,const std::vector<int> &values, intmatrix &dp, std::vector<int> &sol);
void knapsack_min(const int &n, const int &V,const std::vector<int> &weights,const std::vector<int> &values, intmatrix &dp, std::vector<int> &sol);

#endif //KNAPSACK