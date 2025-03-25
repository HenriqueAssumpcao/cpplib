#pragma once

#ifndef PRIMES
#define PRIMES

#include <vector>
#include "common.hpp"

std::vector<ll> eratosthenes_sieve(ll n);
std::vector<ll> prime_factors(ll n);

#endif //PRIMES