#pragma once

#ifndef KNAPSACK
#define KNAPSACK

#include <vector>

#include "common.hpp"

void knapsack(int n, int w, std::vector<int> &values, std::vector<int> &weights, intmatrix &opt, std::vector<int> &sol);

#endif //KNAPSACK