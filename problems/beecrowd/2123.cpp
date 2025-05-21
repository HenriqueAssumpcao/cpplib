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
void add_edge(int u, int v, ll c,int &eid, vector<flow_edge> &edges, graph &g){
    edges.push_back(flow_edge(u,v,c));
    edges.push_back(flow_edge(v,u,0));
    g[u].push_back(eid);
    g[v].push_back(eid+1);
    eid+=2;
}
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

int main(){

    int n,m,k;
    int count = 1;

    while(cin >> n >> m >> k){
        cout << "Instancia " << count << endl;

        vector<int> horse_cap(n);
        for(int i = 0; i < n; i++){
            cin >> horse_cap[i];
        }

        int num_v = m+2*n + 2;
        graph g(m+2*n + 2);
        vector<flow_edge> edges;
        int eid = 0;
        for(int i = 0; i < n; i++){
            add_edge(i,m+n+i,horse_cap[i],eid,edges,g);
            add_edge(m+n+i,num_v-1,horse_cap[i],eid,edges,g);
        }
        for(int i = n;i < m+n; i++){
            add_edge(num_v-2,i,1,eid,edges,g);
        }
        for(int i = 0; i < k; i++){
            int u,v;
            cin >> u >> v;
            u--;v--;
            add_edge(n+v,u,1,eid,edges,g);
        }

        cout << dinic_maxflow(num_v-2,num_v-1,num_v,g,edges) << endl;
        cout << endl;

        count++;
    }


    return 0;
}