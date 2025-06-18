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
vector<ll> primes;

void erat_sieve(ll nmax){
    prime = vector<bool>(nmax+1,1);
    prime[0] = 0;
    prime[1] = 0;

    primes.resize(0);

    for(ll i = 2; i <= nmax; i++){
        if(prime[i]){
            for(ll j = 2*i;j <= nmax; j += i){
                prime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    ll a,b;
    cin >> a >> b;

    if(a == b){
        cout << "?" << endl;
    }
    else{
        ll diff = abs(a-b);
        erat_sieve(max(a,b));
        ll nprimes = 0,count = 0;
        ll lb = min(a,b);
        for(int i = 0; i < primes.size(); i++){
            if(primes[i] >= lb){
                break;
            }
            count++;
        }
        nprimes = primes.size() - count;
        if(~(nprimes + diff - 1) & diff){
            cout << "Bob" << endl;
        }
        else{
            cout << "Alice" << endl;
        }
        
        
    }

    return 0;
}
