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


int dfs_time;

void dfs_visit(int u, int &n, wgraph &g,vector<int> &color,vector<int> &start,vector<int> &finish,vector<int> &pred){
    dfs_time++;
    color[u] = 1;
    start[u] = dfs_time;

    for(auto [v,w] : g[u]){
        if(color[v] == 0){
            pred[v] = u;
            dfs_visit(v,n,g,color,start,finish,pred);
        }
    }

    dfs_time++;
    color[u] = 2;
    finish[u] = dfs_time;
}

void dfs(int &n, wgraph &g,vector<int> &pred,vector<int> &start, vector<int> &finish){
    vector<int> color(n,0);
    pred = vector<int>(n,-1),start = vector<int>(n,0),finish = vector<int>(n,0);
    dfs_time = 0;
    for(int u = 0; u < n; u++){
        if(color[u] == 0){
            dfs_visit(u,n,g,color,start,finish,pred);
        }
    }
}

wgraph transpose_graph(int n,wgraph &g){
    wgraph gt(n);

    for(int u = 0; u < n; u++){
        for(auto [v,w] : g[u]){
            gt[v].push_back({u,w});
        }
    }

    return gt;
}

void kosaraju_visit(int u, int n, wgraph &gt, vector<int> &color, vector<int> &scc){
    color[u] = 1;
    for(auto [v,w] : gt[u]){
        if(color[v] == 0){
            scc.push_back(v);
            kosaraju_visit(v,n,gt,color,scc);
        }
    }
    color[u] = 2;
}

vector<vector<int>> kosaraju_scc(int &n, wgraph &g){
    vector<int> pred,start,finish;
    dfs(n,g,pred,start,finish);
    vector<pair<int,int>> nodefinish(n);
    for(int u = 0; u < n; u++){
        nodefinish[u] = {u,finish[u]};
    }
    sort(nodefinish.begin(), nodefinish.end(), [](auto &left, auto &right) {
    return left.second > right.second;});

    wgraph gt = transpose_graph(n,g);

    vector<int> color(n,0);
    vector<vector<int>> sccs;
    for(int i = 0; i < n; i++){
        int u = nodefinish[i].first;
        if(color[u] == 0){
            vector<int> scc;
            scc.push_back(u);
            kosaraju_visit(u,n,gt,color,scc);
            sccs.push_back(scc);
        }
    }

    return sccs;
}

void dijkstra(int s, int n, wgraph &g, vector<ll> &dist){
    dist = vector<ll>(n,LLINF);
    dist[s] = 0;
    priority_queue<pair<ll,int>> pq;
    pq.emplace(0,s);

    while(pq.size()){
        auto [curr_dist,u] = pq.top();
        pq.pop();

        if(dist[u] >= -curr_dist){
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

    int n,m;
    while(cin >> n >> m){
        if(n == 0){
            break;
        }
        wgraph g(n);
        for(int i = 0;i < m; i++){
            int u,v;
            ll w;
            cin >> u >> v >> w;
            u--;v--;
            g[u].push_back({v,w});
        }

        vector<vector<int>> sccs = kosaraju_scc(n,g);

        map<int,int> node2scc;
        for(int i = 0; i < sccs.size(); i++){
            for(int u : sccs[i]){
                node2scc[u] = i;
            }
        }

        wgraph gscc(sccs.size());
        for(int u = 0; u < n; u++){
            for(auto [v,w] : g[u]){
                if(node2scc[u] != node2scc[v]){
                    gscc[node2scc[u]].push_back({node2scc[v],w});
                }
            }
        }


        int k;
        cin >> k;
        while(k--){
            int u,v;
            cin >> u >> v;
            u--;v--;
            vector<ll> dist;
            dijkstra(node2scc[u],sccs.size(),gscc,dist);
            if(dist[node2scc[v]] != LLINF){
                cout << dist[node2scc[v]] << endl;
            }
            else{
                cout << "Nao e possivel entregar a carta" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
