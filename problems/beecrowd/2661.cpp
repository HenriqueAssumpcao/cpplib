#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

vector<ll> eratosthenes_sieve(ll n){
    vector<bool> is_prime(n-1,1);
    vector<ll> primes;

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


vector<ll> prime_factors(ll n){
    ll csqrtn = ceil(sqrt(n));
    vector<ll> primes = eratosthenes_sieve(csqrtn);
    vector<ll> factors;

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

map<pair<int,int>,int> binom2val;

int binom_coeff(int n, int k){
    if(k < 0 || k > n){
        return 0;   
    }
    else if(k == 0){
        return 1;
    }
    else{
        auto temp1 = binom2val.find({n-1,k}), temp2 = binom2val.find({n-1,k-1});
        if(temp1 == binom2val.end()){
            binom2val[{n-1,k}] = binom_coeff(n-1,k);
        }
        if(temp2 == binom2val.end()){
            binom2val[{n-1,k-1}] = binom_coeff(n-1,k-1);
        }
        return binom2val[{n-1,k}] + binom2val[{n-1,k-1}];
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    
    ll n;
    cin >> n;

    vector<ll> factors = prime_factors(n);
    set<ll> unique_factors(factors.begin(),factors.end());

    int num_stripped = 0;
    int num_factors = unique_factors.size();
    for(int k = 2; k <= num_factors; k++){
        num_stripped += binom_coeff(num_factors,k);
    }

    cout << num_stripped << endl;


    return 0;
}
