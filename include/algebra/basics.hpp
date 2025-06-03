#pragma once

#ifndef EXP
#define EXP

#include "common.hpp"

ll fast_exp(ll e,const ll &b);
ll fast_exp_mod(ll e,const ll &b,const ll &mod);
ll gcd(ll a, ll b, ll &x, ll &y);
ll inv_mod(const ll &a, const ll &n);
ll inv_modp(const ll &a, const ll &p);
llmatrix matmul_mod(const llmatrix &A,const llmatrix &B,const ll &mod);
llmatrix fast_matexp_mod(ll e, const llmatrix &M,const ll &mod);


#endif //EXP