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

// 
struct flow_edge{
    int u,v; 
    ll cap,flow = 0;
    flow_edge(int _u,int _v, ll _cap):u(_u),v(_v),cap(_cap){};

};
void bfs(int s, int n, graph &g, vector<flow_edge> &edges, vector<int> &bfs_layer,ll cap_lb=1){
    bfs_layer = vector<int>(n,-1);
    queue<int> q;
    q.push(s);
    bfs_layer[s] = 0;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int eid : g[u]){
            if(bfs_layer[edges[eid].v] == -1 && ((edges[eid].cap - edges[eid].flow) >= cap_lb)){
                bfs_layer[edges[eid].v] = bfs_layer[edges[eid].u] + 1;
                q.push(edges[eid].v);
            }
        }
    }
}
ll layer_aug_path_dfs(int u, int t, ll flow, graph &g, vector<flow_edge> &edges,vector<int> &bfs_layer, vector<int> &dfs_ptr, ll cap_lb=1){
    if((flow == 0) || (u == t)){
        return flow;
    }
    for(int &i = dfs_ptr[u]; i < g[u].size(); i++){
        int eid = g[u][i];
        if((bfs_layer[edges[eid].v] == bfs_layer[u] + 1) && (edges[eid].cap - edges[eid].flow) >= cap_lb){
            ll down_flow = layer_aug_path_dfs(edges[eid].v,t,min(flow,edges[eid].cap - edges[eid].flow),g,edges,bfs_layer,dfs_ptr,cap_lb);
            if(down_flow >= cap_lb){
                edges[eid].flow += down_flow;
                edges[eid ^ 1].flow -= down_flow;
                return down_flow;
            }
        }
    }

    return 0;

}
ll dinic_maxflow(int s, int t, int n, graph &g, vector<flow_edge> &edges, ll cap_lb=1){
    vector<int> bfs_layer,dfs_ptr;
    ll max_flow = 0,curr_flow;
    while(true){
        bfs(s,n,g,edges,bfs_layer,cap_lb);
        if(bfs_layer[t] == -1){
            break;
        }
        dfs_ptr = vector<int>(n,0);
        while((curr_flow = layer_aug_path_dfs(s,t,LLONG_MAX,g,edges,bfs_layer,dfs_ptr,cap_lb))){
            max_flow += curr_flow;
        }
    }

    return max_flow;
}
//
void add_edge(int u, int v, ll c,int &eid, vector<flow_edge> &edges, graph &g){
    edges.push_back(flow_edge(u,v,c));
    edges.push_back(flow_edge(v,u,0));
    g[u].push_back(eid);
    g[v].push_back(eid+1);
    eid+=2;
}

bool sol_d(int d, int &n, int &m, int &a, wgraph &g){
    int lgs = (d+1)*n + 2;
    graph gflow(lgs);
    vector<flow_edge> edges;
    int eid = 0;

    for(int dd = 0; dd < d; dd++){
        for(int u = 0; u < n; u++){
            int today_u = (dd*n)+u,tomorrow_u = (dd+1)*n + u;
            add_edge(today_u,tomorrow_u,LLINF,eid,edges,gflow);
        }
    }

    add_edge(lgs-2,0,a,eid,edges,gflow);
    add_edge(lgs-3,lgs-1,LLINF,eid,edges,gflow);
    
    for(int u = 0; u < n; u++){
        for(auto [v,c] : g[u]){
            for(int dd = 0; dd < d; dd++){
                int today_u = (dd*n)+u,tomorrow_v = (dd+1)*n + v;
                add_edge(today_u,tomorrow_v,c,eid,edges,gflow);
            }
        }
    }

    return (dinic_maxflow(lgs-2,lgs-1,lgs,gflow,edges) == a);
}

ll bin_search_sol(int left, int right, int &n, int &m, int &a, wgraph &g){
    if(left == right){
        if(sol_d(left,n,m,a,g)){
            return left;
        }
        return -1;
    }
    else if(right == left+1){
        if(sol_d(left,n,m,a,g)){
            return left;
        }
        else if(sol_d(right,n,m,a,g)){
            return right;
        }
        return -1;
    }
    int middle = left + (right-left+1)/2;
    if(sol_d(middle,n,m,a,g)){
        return bin_search_sol(left,middle,n,m,a,g);
    }
    else{
        return bin_search_sol(middle+1,right,n,m,a,g);
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m,a;
    
    while(cin >> n >> m >> a){
        if(n == 0){
            break;
        }
        wgraph g(n);
        int u,v;
        ll c;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> c;
            u--;v--;
            g[u].push_back({v,c});
        }
        cout << bin_search_sol(1,a+n,n,m,a,g) << endl;
    }

    return 0;
}
