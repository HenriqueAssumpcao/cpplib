#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph
typedef vector<list<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;


void prim(int s,wgraph &g, int n, vector<int> &pred){
    vector<ll> keys(n);
    vector<bool> visited(n);
    pred.resize(n);
    for(int i = 0; i < n; i++){
        pred[i] = -1;
        keys[i] = LLINF;
        visited[i] = 0;
    }

    keys[s] = 0;

    priority_queue<pair<ll,int>> pq;

    pq.emplace(0,s);

    while(pq.size()){
        auto [neg_key,u] = pq.top();
        pq.pop();
        visited[u] = 1;
        if(keys[u] >= -neg_key){
            for(auto [v,w] : g[u]){
                if(visited[v] == 0 && w < keys[v]){
                    pred[v] = u;
                    keys[v] = w;
                    pq.emplace(-w,v);
                }
            }
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    // Reads graph
    int n;
    cin >> n;

    wgraph g(n),g_neg(n);

    int u,v;
    ll w;
    while(cin >> u >> v >> w){
        g[u-1].push_back({v-1,w});
        g[v-1].push_back({u-1,w});

        g_neg[u-1].push_back({v-1,-w});
        g_neg[v-1].push_back({u-1,-w});
    }
    
    // Prim to find min ST on original graph, and prim on graph with negative weights to find max ST
    vector<int> pred;
    vector<int> pred_neg;

    prim(0,g,n,pred);
    prim(0,g_neg,n,pred_neg);

    ll min_st_weight = 0,max_st_weight = 0;
    for(int u = 1; u < n; u++){
        for(auto [v,w] : g[u]){
            if(v == pred[u]){
                min_st_weight += w;
            }
        }
        for(auto [v,w] : g_neg[u]){
            if(v == pred_neg[u]){
                max_st_weight += w;
            }
        }
    }

    cout << -max_st_weight << endl;
    cout << min_st_weight << endl;



    return 0;
}
