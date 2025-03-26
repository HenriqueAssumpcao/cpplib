#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    string n;
    cin >> n;

    int ret = 0;
    for(int i = 0; i < n.length();i++){
        ret = (10*ret + (int)n[i] - 48) % 3;
    }

    cout << ret << endl;
    
    return 0;
}
