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

ll gcd_ext(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll ret = gcd_ext(b,a%b,x,y);
    ll temp = y;
    y = x - (a/b)*temp;
    x = temp;
    return ret;
}

ll inv_mod(const ll &a, const ll &n){
    ll x,y,d;
    d = gcd_ext(a,n,x,y);
    if(d == 1){
        if(x < 0){
            x = n - ((-x) % n);
        }
        return x%n;
    }
    else{
        return 0;
    }
}

ll binom_mod(ll n, ll k, ll mod,vector<ll> &fact){
    return (fact[n] * inv_mod((fact[n-k] * fact[k]) % mod,mod)) % mod;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    ll nmax = 1e7;
    vector<ll> fact(nmax+1);
    ll mod = 1300031;

    fact[0] = 1;
    for(int i = 1; i <= nmax; i++){
        fact[i] = (i * fact[i-1]) % mod;
    }

    int t;
    cin >> t;
    while(t--){
        ll n,c;
        cin >> n >> c;

        cout << binom_mod(c+n-1,n-1,mod,fact) << endl;
    }

    return 0;
}
