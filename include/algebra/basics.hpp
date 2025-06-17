#pragma once

#ifndef EXP
#define EXP

#include "common.hpp"

ll fast_exp(ll e,const ll &b);
ll fast_exp_mod(ll e,const ll &b,const ll &mod);
ll gcd_ext(ll a, ll b, ll &x, ll &y);
ll inv_mod(const ll &a, const ll &n);
ll inv_modp(const ll &a, const ll &p);
llmatrix matmul_mod(const llmatrix &A,const llmatrix &B,const ll &mod);
llmatrix fast_matexp_mod(ll e, const llmatrix &M,const ll &mod);
std::vector<int> compose_permutation(int n,std::vector<int> &perm1, std::vector<int> &perm2);
std::vector<int> fast_exp_permute(int n, ll e, std::vector<int> &perm);


#endif //EXP
