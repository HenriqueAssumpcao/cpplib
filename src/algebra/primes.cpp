#include "algebra/primes.hpp"

std::vector<bool> prime;
std::vector<ll> factor,pexp,var,primes;

void eratosthenes_sieve(ll n){
    prime = std::vector<bool>(n+1,1);
    prime[0] = 0;
    prime[1] = 0;

    factor.resize(n+1);pexp.resize(n+1);var.resize(n+1);
    primes.resize(0);

    for(ll i = 2; i <= n; i++){
        if(prime[i]){
            factor[i] = i;
            pexp[i] = 1;
            var[i] = 1;
            for(ll j = 2*i;j <= n; j += i){
                prime[j] = 0;
                factor[j] = i;
                if(factor[j/i] == i){
                    pexp[j] = pexp[j/i] + 1;
                    var[j] = var[j/i];
                }
                else{
                    pexp[j] = 1;
                    var[j] = j/i;
                }
            }
            primes.push_back(i);
        }
    }
}

bool prime_factors(ll n, ll NMAX,std::vector<ll> &p, std::vector<ll> &e){
    if(n <= 1){
        return (n == 1);
    }
    
    p.resize(0);e.resize(0);
    ll temp = n;
    if(NMAX * NMAX < n){
        return 0;
    }

    if(n > NMAX){
        for(int pp : primes){
            int curr = 0;
            while((temp % pp) == 0){
                curr++;
                temp /= pp;
            }
            if(curr){
                p.push_back(pp);
                e.push_back(curr);
            }
            if(temp <= NMAX){
                break;
            }
        }
    }
    if(temp <= NMAX){
        while(temp != 1){
            p.push_back(factor[temp]);
            e.push_back(pexp[temp]);
            temp = var[temp];
        }
    }
    else{
        p.push_back(temp);
        e.push_back(1);
    }

    return 1;
}