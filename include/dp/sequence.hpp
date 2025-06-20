#pragma once

#ifndef SEQUENCE
#define SEQUENCE

#include "common.hpp"

void longest_common_subsequence_dp(std::string &s1, std::string &s2, llmatrix &dp);
int longest_common_substring_dp(std::string &s1, std::string &s2, llmatrix &dp, std::string &lcs);
int lis_dp(int &n, std::vector<int> &vec, std::vector<int> &lis);
int lis_dp_binsearch(int &n, std::vector<int> &vec, std::vector<int> &lis);
void cis_dp(int &n, int &k,std::vector<ll> &a, llmatrix &dp);

#endif //SEQUENCE