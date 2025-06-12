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
vector<ll> factor,pexp,var,primes,ndiv;

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

bool prime_decomp(ll n,vector<ll> &p, vector<ll> &e, ll nmax){
    if(n <= 1){
        return (n == 1);
    }
    
    p.resize(0);e.resize(0);
    ll temp = n;
    if(nmax * nmax < n){
        return 0;
    }

    if(n > nmax){
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
            if(temp <= nmax){
                break;
            }
        }
    }
    if(temp <= nmax){
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

ll n_div(vector<ll> &e){
    ll temp = 1;
    for(ll ee : e){
        temp *= (ee+1);
    }
    return temp;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    ll nmax = 2*1e6 + 1;
    erat_sieve(nmax);
    vector<ll> hp(nmax-2);
    
    ll count = 0;
    for(int i = 2; i < nmax; i++){
        if(!prime[i]){
            vector<ll> p,e;
            prime_decomp(i,p,e,nmax);
            ll temp = n_div(e);
            if(prime[temp]){
                count++;
            }
        }
        else{
            count++;
        }
        hp[i-2] = count;
    }

    ll n;
    while(cin >> n){
        cout << hp[n-2] << endl;
    }

    

    return 0;
}
