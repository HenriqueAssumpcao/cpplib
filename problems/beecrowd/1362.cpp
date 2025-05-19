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

template <typename T>
void print_vector(vector<T> &vec){
    for(unsigned i = 0; i < vec.size()-1; i++){
        cout << vec[i] << " "; 
    }
    cout << vec[vec.size()-1] << endl;
}

struct flow_edge{
    int u,v; // Endpoits of directed edge
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

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    map<string,int> size2id;
    size2id["XXL"] = 0;
    size2id["XL"] = 1;
    size2id["L"] = 2;
    size2id["M"] = 3;
    size2id["S"] = 4;
    size2id["XS"] = 5;
    while(t--){
        int n,m;
        cin >> n >> m;
        int k = n/6;
        graph g(n+m+2);
        vector<flow_edge> edges;
        int eid = 0;
        for(int u = 0; u < m; u++){
            string s1,s2;
            cin >> s1 >> s2;
            add_edge(n+m,u,1,eid,edges,g);
            for(int i = 0; i < k; i++){
                int temp1 = size2id[s1]*k + m,temp2 = size2id[s2]*k + m;
                add_edge(u,temp1+i,1,eid,edges,g);
                add_edge(u,temp2+i,1,eid,edges,g);
            }
        }
        for(int v = m; v < n+m; v++){
            add_edge(v,n+m+1,1,eid,edges,g);
        }

        ll max_flow = dinic_maxflow(n+m,n+m+1,n+m+2,g,edges);
        if(max_flow == m){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
