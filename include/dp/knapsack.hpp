#pragma once

#ifndef KNAPSACK
#define KNAPSACK

#include <vector>

#include "common.hpp"

void knapsack_primal(int &n, int &C,std::vector<int> &weights, std::vector<int> &values, intmatrix &dp, std::vector<int> &sol);
void knapsack_dual(int &n, int &C,std::vector<int> &weights, std::vector<int> &values, intmatrix &dp, std::vector<int> &sol);

#endif //KNAPSACK