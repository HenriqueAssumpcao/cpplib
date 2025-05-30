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

ll mst_prim(int n, wgraph &g){
    vector<ll> key(n,LLINF);
    vector<bool> visited(n,0);
    key[0] = 0;

    priority_queue<pair<ll,int>> pq;
    pq.emplace(0,0);

    while(pq.size()){
        auto [curr_key,u] = pq.top();
        pq.pop();
        visited[u] = 1;
        if(key[u] >= -curr_key){
            for(auto [v,w] : g[u]){
                if(visited[v] == 0 && w < key[v]){
                    key[v] = w;
                    pq.emplace(-w,v);
                } 
            }
        }
    }
    ll ret = 0;
    for(int u = 1; u < n; u++){
        if(key[u] != LLINF){
            ret += key[u];
        }
    }

    return ret;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    while(cin >> n >> m){
        if(n == 0){
            break;
        }
        wgraph g(n);
        for(int i = 0; i < m; i++){
            int u,v;
            ll w;
            cin >> u >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        cout << mst_prim(n,g) << endl;
    }

    return 0;
}
