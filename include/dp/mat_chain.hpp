#pragma once

#ifndef MAT_CHAIN
#define MAT_CHAIN

#include "common.hpp"
void mat_chain_order_dp(const int &n,const std::vector<int> &a, llmatrix &dp, llmatrix &recover);
std::string recover_product(int l, int r,llmatrix &recover);

#endif //MAT_CHAIN