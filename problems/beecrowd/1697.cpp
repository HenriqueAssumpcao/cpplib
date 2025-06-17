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

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    ll nmax = 2*1e6;
    erat_sieve(nmax);
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        bool has_one = false;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            has_one = has_one || (a[i] == 1);
        }
        if(!has_one){
            cout << 0 << endl;
        }
        else{
            vector<bool> is_reachable(nmax,0);
            for(ll aa : a){
                if(aa < nmax){
                    is_reachable[aa] = 1;
                }
            }

            for(int i = 2; i < nmax; i++){
                if(!is_reachable[i]){
                    ll p = factor[i],q = i/p;
                    is_reachable[i] = (is_reachable[p] && is_reachable[q]);
                }
            }
            
            for(int i = 2; i < nmax; i++){
                if(!is_reachable[i]){
                    cout << i - 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
