#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph

void djikstra(int s,int n, wgraph &g, vector<ll> &dist){
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

        if(-neg_distu <= dist[u]){
            for(auto [v,w] : g[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u]+w;
                    pq.emplace(-dist[v],v);
                }
            }
        }
    }
}

vector<pair<int,ll>> find_cycles_bfs(int s, int n, wgraph &g){
    // assumes each vertex is in at most one cycle
    vector<pair<int,ll>> cycles;

    vector<int> visited(n,0);
    vector<int> in_cycle(n,0);
    vector<int> bfs_layer(n,0);
    vector<pair<int,ll>> parent(n,{-1,-1});

    queue<int> q;

    q.emplace(s);
    visited[s] = 1;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto [v,w] : g[u]){
            if(visited[v] == 0){
                visited[v] = 1;
                parent[v] = {u,w};
                bfs_layer[v] = bfs_layer[u]+1;
                q.emplace(v);
            }
            else if(v != parent[u].first && in_cycle[u] == 0){
                ll cycle_cost = w;
                int temp1 = u,temp2 = v;

                if(bfs_layer[u] != bfs_layer[v]){ // if even cycle, we move one step up to assert that u and v are in the same bfs layer
                    in_cycle[temp2] = 1;
                    temp2 = parent[v].first;
                    cycle_cost += parent[v].second;
                }

                while(temp1 != temp2){
                    cycle_cost += (parent[temp1].second + parent[temp2].second);
                    in_cycle[temp1] = 1;in_cycle[temp2] = 1;
                    temp1 = parent[temp1].first;
                    temp2 = parent[temp2].first;
                }
                cycles.push_back({temp1,cycle_cost});

            }
        }
    }

    return cycles;
}



int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);


    int n,m;

    while(cin >> n >> m){
        wgraph g(n);
        
        int u,v,w;
        while(m--){
            cin >> u >> v >> w;
            u--;v--;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        int q;
        cin >> q;

        int x,l;
        while(q--){
            cin >> x >> l;
            x--;
            vector<pair<int,ll>> cycles = find_cycles_bfs(x,n,g);
            
            ll ret = LLINF;
            if(cycles.size() > 0){
                vector<ll> dist;
                djikstra(x,n,g,dist);
                for(auto [cycle_start,cycle_cost] : cycles){
                    if(cycle_cost >= l){
                        ret = min(2*dist[cycle_start] + cycle_cost,ret);
                    }
                }
            }
            if(ret == LLINF){
                ret = -1;
            }
            cout << ret << endl;
        }
    }

    return 0;
}
