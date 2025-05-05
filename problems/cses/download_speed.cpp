#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<int>> graph; // unweighted graph
typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;


// Edge struct

struct flow_edge{
    int u,v; // Endpoits of directed edge
    ll cap,flow = 0;
    flow_edge(int _u,int _v, ll _cap):u(_u),v(_v),cap(_cap){};

};

// Capacity Scaling (uses the residual graph!)

ll find_aug_path_lb(int s, int t, int n, ll cap_lb, graph &g, vector<flow_edge> &edges, vector<int> &parent){
    parent = vector<int>(n,-1);
    vector<bool> visited(n,0);
    visited[s] = 1;

    queue<pair<int,ll>> q;
    q.push({s,LLINF});

    while(q.size()){
        auto [u,flow] = q.front();
        q.pop();

        for(int i : g[u]){
            if(visited[edges[i].v] == 0 && edges[i].cap >= cap_lb){
                visited[edges[i].v] = 1;
                parent[edges[i].v] = i;
                flow = min(flow,edges[i].cap);
                if(edges[i].v == t){
                    return flow;
                }
                q.push({edges[i].v,flow});
            }
        }
    }
    return 0;
}

ll edmonds_karp_maxflow_lb(int s, int t, int n, ll cap_lb, graph &g, vector<flow_edge> &edges){
    ll max_flow = 0;
    vector<int> parent;

    ll curr_flow;
    while(curr_flow = find_aug_path_lb(s,t,n,cap_lb,g,edges,parent)){
        max_flow += curr_flow;
        int temp = t;
        while(temp != s){
            int prev = edges[parent[temp]].u;
            int op_edge_id = parent[temp] ^ 1;

            edges[parent[temp]].flow += curr_flow;
            edges[parent[temp]].cap -= curr_flow;
            edges[op_edge_id].flow -= curr_flow;
            edges[op_edge_id].cap += curr_flow;
            temp = prev;
        }
    }

    return max_flow;
}

ll cap_scaling_maxflow(int s, int t, int n, graph &g, vector<flow_edge> &edges){
    ll max_cap = 0;;
    vector<flow_edge> res_edges;
    for(flow_edge e:edges){
        max_cap = max(max_cap,e.cap);
        res_edges.push_back(e);
    }
    ll max_flow = 0;
    while(max_cap >= 1){
        max_flow += edmonds_karp_maxflow_lb(s,t,n,max_cap,g,res_edges);
        max_cap = (max_cap >> 1);
    }

    for(int i = 0; i < edges.size(); i++){
        edges[i].flow = res_edges[i].flow;
    }

    return max_flow;
}


int main(){

    int n,m;
    cin >> n >> m;

    vector<flow_edge> edges;
    graph g(n);
    int edge_id = 0;
    int u,v;
    ll c;
    map<pair<int,int>,int> pair2edge;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        u--;v--;
        if(pair2edge.find({u,v}) == pair2edge.end()){
            edges.push_back(flow_edge(u,v,c));
            edges.push_back(flow_edge(v,u,0));
            g[u].push_back(edge_id);
            g[v].push_back(edge_id+1);
            pair2edge[{u,v}] = edge_id;
            edge_id += 2;
        }
        else{
            edges[pair2edge[{u,v}]].cap += c;
        }
    }

    cout << cap_scaling_maxflow(0,n-1,n,g,edges) << endl;
}