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

void dfs_visit(int u, int &n, graph &g,vector<int> &color,vector<int> &finish){
    dfs_time++;
    color[u] = 1;

    for(int v : g[u]){
        if(color[v] == 0){
            dfs_visit(v,n,g,color,finish);
        }
    }

    dfs_time++;
    color[u] = 2;
    finish[u] = dfs_time;
}

void dfs(int &n, graph &g,vector<int> &finish){
    vector<int> color(n,0);
    finish = vector<int>(n,0);
    dfs_time = 0;
    for(int u = 0; u < n; u++){
        if(color[u] == 0){
            dfs_visit(u,n,g,color,finish);
        }
    }
}

graph transpose_graph(int n,graph &g){
    graph gt(n);

    for(int u = 0; u < n; u++){
        for(int v : g[u]){
            gt[v].push_back(u);
        }
    }

    return gt;
}

void kosaraju_visit(int u, int n, graph &gt, vector<int> &color, vector<int> &scc){
    color[u] = 1;
    for(int v : gt[u]){
        if(color[v] == 0){
            scc.push_back(v);
            kosaraju_visit(v,n,gt,color,scc);
        }
    }
    color[u] = 2;
}

vector<vector<int>> kosaraju_scc(int &n, graph &g){
    vector<int> finish;
    dfs(n,g,finish);
    vector<pair<int,int>> nodefinish(n);
    for(int u = 0; u < n; u++){
        nodefinish[u] = {u,finish[u]};
    }
    sort(nodefinish.begin(), nodefinish.end(), [](auto &left, auto &right) {
    return left.second > right.second;});
    graph gt = transpose_graph(n,g);
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

bool bfs(int n, graph &g){
    vector<bool> visited(n,0);
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    int nvisited = 1;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(visited[v] == 0){
                visited[v] = 1;
                nvisited++;
                q.push(v);
            }
        }
    }

    return (nvisited == n);
}

void bridge_visit(int u, int &n, graph &g, vector<int> &color, vector<pair<int,int>> &bridges,vector<int> &start,vector<int> &parent,vector<int> &low){
    color[u] = 1;
    start[u] = dfs_time;
    low[u] = dfs_time;
    dfs_time++;
    for(int v: g[u]){
        if(color[v] == 0){
            parent[v] = u;
            bridge_visit(v,n,g,color,bridges,start,parent,low);
            low[u] = min(low[u],low[v]);
            if(low[v] > start[u]){
                bridges.push_back({u,v});
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u],start[v]);
        }
    }
    color[u] = 2;
}

bool is_2edgeconnected(int n, graph &g,map<pair<int,int>,int> &way){
    vector<int> color(n,0),start(n,0),parent(n,-1),low(n,0);
    dfs_time = 0;
    vector<pair<int,int>> bridges;
    for(int u = 0; u < n; u++){
        if(color[u] == 0){
            bridge_visit(u,n,g,color,bridges,start,parent,low);
        }
    }
    for(auto e : bridges){
        if(way[e] == 1){
            return 0;
        }
    }
    return 1;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(cin >> n >> m){
        graph g(n),gu(n);
        map<pair<int,int>,int> way;
        int u,v,t;
        cin >> u >> v >> t;
        for(int i = 1; i < m; i++){
            int a,b,t;
            cin >> a >> b >> t;
            a--;b--;
            way[{a,b}] = t;
            way[{b,a}] = t;
            g[a].push_back(b);
            gu[a].push_back(b);
            gu[b].push_back(a);
            if(t == 2){
                g[b].push_back(a);
            }
        }
        vector<vector<int>> sccs = kosaraju_scc(n,g);
        if(sccs.size() == 1){
            cout << '-' << endl;
        }
        else if(bfs(n,gu) == 0){
            cout << "*" << endl;
        }
        else if(is_2edgeconnected(n,gu,way) == 1){
            cout << "1" << endl;
        }
        else{
            cout << "2" << endl;
        }

    }

    return 0;
}
