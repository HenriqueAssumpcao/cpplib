#include <vector>
#include <cmath>

#include "common.hpp"
#include "algebra/primes.hpp"

std::vector<ll> eratosthenes_sieve(ll n){
    std::vector<bool> is_prime(n-1,1);
    std::vector<ll> primes;

    for(ll i = 2; i*i < n; i++){
        if(is_prime[i-2] == 1){
            ll j = i*i;
            while(j <= n){
                is_prime[j-2] = 0;
                j += i;
            }
        }
    }

    for(ll i = 0; i < n-1; i++){
        if(is_prime[i] == 1){
            primes.push_back(i+2);
        }
    }

    return primes;
}


std::vector<ll> prime_factors(ll n){
    ll csqrtn = ceil(sqrt(n));
    std::vector<ll> primes = eratosthenes_sieve(csqrtn);
    std::vector<ll> factors;

    ll temp = n;
    for(ll prime : primes){
        while(temp % prime == 0){
            factors.push_back(prime);
            temp /= prime;
        }
    }
    if(temp > 2){
        factors.push_back(temp);
    }

    return factors;
}