#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m;

    cin >> n >> m;

    vector<int> deg(n);
    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        deg[u-1]++;
        deg[v-1]++;
    }

    int num_deg1 = 0, num_deg2 = 0;

    for(int u = 0; u < n; u++){
        if(deg[u] == 1){
            num_deg1++;
        }
        else if(deg[u] == 2){
            num_deg2++;
        }
    }

    if(num_deg1 == 2 && num_deg2 == n-2){
        cout << "bus topology" << endl;
    }
    else if(num_deg2 == n){
        cout << "ring topology" << endl;
    }
    else if(num_deg1 == n-1){
        cout << "star topology" << endl;
    }
    else{
        cout << "unknown topology" << endl;
    }

    return 0;
}
