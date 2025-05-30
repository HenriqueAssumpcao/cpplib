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
    ll cap,flow = 0,time=LLINF;
    flow_edge(int _u,int _v, ll _cap,ll _time):u(_u),v(_v),cap(_cap),time(_time){};

};
void add_edge(int u, int v, ll c,int &eid, vector<flow_edge> &edges, graph &g,ll time=LLINF){
    edges.push_back(flow_edge(u,v,c,time));
    edges.push_back(flow_edge(v,u,0,time));
    g[u].push_back(eid);
    g[v].push_back(eid+1);
    eid+=2;
}
void bfs(int s, int n, graph &g, vector<flow_edge> &edges, vector<int> &bfs_layer,ll cap_lb=1,ll time_ub=LLINF){
    bfs_layer = vector<int>(n,-1);
    queue<int> q;
    q.push(s);
    bfs_layer[s] = 0;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int eid : g[u]){
            if((edges[eid].time <= time_ub) && bfs_layer[edges[eid].v] == -1 && ((edges[eid].cap - edges[eid].flow) >= cap_lb)){
                bfs_layer[edges[eid].v] = bfs_layer[edges[eid].u] + 1;
                q.push(edges[eid].v);
            }
        }
    }
}
ll layer_aug_path_dfs(int u, int t, ll flow, graph &g, vector<flow_edge> &edges,vector<int> &bfs_layer, vector<int> &dfs_ptr, ll cap_lb=1,ll time_ub=LLINF){
    if((flow == 0) || (u == t)){
        return flow;
    }
    for(int &i = dfs_ptr[u]; i < g[u].size(); i++){
        int eid = g[u][i];
        if((edges[eid].time <= time_ub) && (bfs_layer[edges[eid].v] == bfs_layer[u] + 1) && (edges[eid].cap - edges[eid].flow) >= cap_lb){
            ll down_flow = layer_aug_path_dfs(edges[eid].v,t,min(flow,edges[eid].cap - edges[eid].flow),g,edges,bfs_layer,dfs_ptr,cap_lb,time_ub);
            if(down_flow >= cap_lb){
                edges[eid].flow += down_flow;
                edges[eid ^ 1].flow -= down_flow;
                return down_flow;
            }
        }
    }

    return 0;

}
ll dinic_maxflow(int s, int t, int n, graph &g, vector<flow_edge> &edges, ll cap_lb=1,ll time_ub=LLINF){
    vector<int> bfs_layer,dfs_ptr;
    ll max_flow = 0,curr_flow;
    while(true){
        bfs(s,n,g,edges,bfs_layer,cap_lb,time_ub);
        if(bfs_layer[t] == -1){
            break;
        }
        dfs_ptr = vector<int>(n,0);
        while((curr_flow = layer_aug_path_dfs(s,t,LLONG_MAX,g,edges,bfs_layer,dfs_ptr,cap_lb,time_ub))){
            max_flow += curr_flow;
        }
    }

    return max_flow;
}

void zero_flow(vector<flow_edge> &edges){
    for(int i = 0; i < edges.size(); i++){
        edges[i].flow = 0;
    }
}

ll bin_search_sol(int l, int r, int &s, int &t, int &n, graph &g, vector<flow_edge> &edges, ll &totald){
    if(l == r){
        ll mf = dinic_maxflow(s,t,n,g,edges,1,l);
        if(mf == totald){
            return l;
        }
        return -1;
    }
    else if(r == (l+1)){
        ll mf_l = dinic_maxflow(s,t,n,g,edges,1,l);
        if(mf_l == totald){
            return l;
        }
        else{
            zero_flow(edges);
            ll mf_r = dinic_maxflow(s,t,n,g,edges,1,r);
            if(mf_r == totald){
                return r;
            } 
        }
        return -1;
    }
    int middle = l + (r-l+1)/2;
    ll ret_middle = dinic_maxflow(s,t,n,g,edges,1,middle);
    zero_flow(edges);
    if(ret_middle == totald){
        return bin_search_sol(l,middle,s,t,n,g,edges,totald);
    }
    else{
        return bin_search_sol(middle+1,r,s,t,n,g,edges,totald);
    }
}


//

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    int r,p,c;
    cin >> p >> r >> c;
    vector<ll> demand(p),stock(r);
    vector<flow_edge> edges;
    int eid = 0;
    int n = r+p+2;
    graph g(n);
    int s = r+p,t = s + 1;
    for(int i = 0; i < p; i++){
        cin >> demand[i];
        add_edge(r+i,t,demand[i],eid,edges,g,0);
    }
    for(int i = 0;i < r; i++){
        cin >> stock[i];
        add_edge(s,i,stock[i],eid,edges,g,0);
    }
    ll tmax = 1;
    while(c--){
        int u,v;
        ll tt;
        cin >> v >> u >> tt;
        u--;v--;
        tmax = max(tmax,tt);
        add_edge(u,r+v,LLINF,eid,edges,g,tt);
    }
    ll totald = accumulate(demand.begin(),demand.end(),0);
    cout << bin_search_sol(1,tmax,s,t,n,g,edges,totald) << endl;



    return 0;
}