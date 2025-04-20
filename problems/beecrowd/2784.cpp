#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph

void dijkstra(int s,wgraph &g, vector<ll> &dist, int n){
    dist.resize(n);
    for(int i = 0; i < n; i++){
        dist[i] = LLINF;
    }
    dist[s] = 0;

    priority_queue<pair<ll,int>> pq;
    pq.emplace(0,s);

    while(pq.size()){
        auto [neg_distu,u] = pq.top();
        pq.pop();
        if(dist[u] >= -neg_distu){
            for(auto [v,w] : g[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.emplace(-dist[v],v);
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    
    // Reads graph
    int n,m;
    cin >> n >> m;

    wgraph g(n);

    int u,v,w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        g[u-1].push_back({v-1,w});
        g[v-1].push_back({u-1,w});
    }

    int s;
    cin >> s;
    s--;
    // Dijkstra to find shortest path to server

    vector<ll> dist;
    dijkstra(s,g,dist,n);

    ll maxping = -1,minping = LLINF;
    for(int i = 0; i < n; i++){
        if(i != s){
            if(dist[i] > maxping){
                maxping = dist[i];
            }
            if(dist[i] < minping){
                minping = dist[i];
            }
        }
    }
    

    cout << maxping - minping << endl;


    return 0;
}
