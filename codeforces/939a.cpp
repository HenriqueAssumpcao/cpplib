#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    
    
    vector<int> f(n);

    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        temp--;
        f[i] = temp;
    }

    for(int i = 0; i < n; i++){
        if(f[f[f[i]]] == i){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;


    return 0;
}
