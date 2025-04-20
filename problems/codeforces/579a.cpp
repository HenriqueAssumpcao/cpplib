#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    ll x;
    cin >> x;

    int counter = 0;

    while(x != 0){
        if(x & 1){
            counter++;
            x = x & ~1;
        }
        else{
            x = x >> 1;
        }
    }

    cout << counter << endl;

    return 0;
}
