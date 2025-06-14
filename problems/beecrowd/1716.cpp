#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

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

ll fast_exp_mod(ll e,const ll &b,const ll &mod){
    if(e == 1){
        return b % mod;
    }
    ll temp = fast_exp_mod(e/2,b,mod);
    temp = (temp*temp)%mod;
    if((e % 2) == 1){
        temp = (temp*b)%mod;
    }
    return temp;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    ll nmax = 1e5;
    erat_sieve(nmax);

    ll N,E,C;
    cin >> N >> E >> C;

    vector<ll> p,e;
    prime_decomp(N,p,e,nmax);

    ll tot = (p[0]-1)*(p[1]-1);

    ll D = inv_mod(E,tot);

    ll M = fast_exp_mod(D,C,N);

    cout << M << endl;

    return 0;
}