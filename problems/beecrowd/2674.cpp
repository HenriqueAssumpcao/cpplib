#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<pair<int,ll>>> wgraph; // weighted graph
typedef vector<vector<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;


vector<bool> prime;
vector<ll> factor,pexp,var,primes;

void erat_sieve(ll nmax){
    prime = vector<bool>(nmax+1,1);
    prime[0] = 0;
    prime[1] = 0;

    factor.resize(nmax+1);pexp.resize(nmax+1);var.resize(nmax+1);
    primes.resize(0);

    for(ll i = 2; i <= nmax; i++){
        if(prime[i]){
            factor[i] = i;
            pexp[i] = 1;
            var[i] = 1;
            for(ll j = 2*i;j <= nmax; j += i){
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



int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    ll n;
    ll nmax = 1e5;
    erat_sieve(nmax);
    while(cin >> n){
        if(prime[n]){
            bool is_super = true;
            while(n != 0){
                if(!prime[n % 10]){
                    is_super = false;
                    break;
                }
                n /= 10;
            }
            if(is_super){
                cout << "Super" << endl;
            }
            else{
                cout << "Primo" << endl;
            }
        }
        else{
            cout << "Nada" << endl;
        }
    }

    return 0;
}
