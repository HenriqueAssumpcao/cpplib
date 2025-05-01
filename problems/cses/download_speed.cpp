#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<int>> graph; // unweighted graph
typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;

// Edmonds Karp 

struct flow_edge{
    int u,v; // Endpoits of directed edge
    ll cap,flow = 0;
    bool in_g; // 1 if edge belongs to the original graph, 0 if it does not
    flow_edge(int _u,int _v, ll _cap, bool _in_g):u(_u),v(_v),cap(_cap),in_g(_in_g){};

};

ll find_aug_path(int s, int t, int &n, graph &g, vector<flow_edge> &edges, vector<int> &parent){
    parent = vector<int>(n,-1);
    vector<bool> visited(n,0);
    visited[s] = 1;

    queue<pair<int,ll>> q;
    q.push({s,LLINF});

    while(q.size()){
        auto [u,flow] = q.front();
        q.pop();

        for(int i : g[u]){
            if(visited[edges[i].v] == 0 && edges[i].cap > 0){
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

ll edmonds_karp_maxflow(int s, int t, int &n, graph &g, vector<flow_edge> &edges){
    ll max_flow = 0;
    vector<int> parent;

    ll curr_flow;
    while(curr_flow = find_aug_path(s,t,n,g,edges,parent)){
        max_flow += curr_flow;
        int temp = t;
        while(temp != s){
            int prev = edges[parent[temp]].u;
            int op_edge_id = (edges[parent[temp]].in_g == 1) ? (parent[temp]+1) : (parent[temp]-1);

            edges[parent[temp]].cap -= curr_flow;
            edges[parent[temp]].flow += curr_flow;
            edges[op_edge_id].cap += curr_flow;
            edges[op_edge_id].flow -= curr_flow;
            temp = prev;
        }
    }

    return max_flow;
}

void min_cut(int s, int &n, graph &g, vector<flow_edge> &edges, vector<int> &is_in_cut){
    is_in_cut = vector<int>(n,0);
    is_in_cut[s] = 1;

    queue<int> q;
    q.push(s);

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i : g[u]){
            if(is_in_cut[edges[i].v] == 0 && edges[i].cap > 0){
                is_in_cut[edges[i].v] = 1;
                q.push(edges[i].v);
            }
        }
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    vector<flow_edge> edges;
    graph g(n);
    int edge_id = 0;
    int u,v;
    ll c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        u--;v--;
        edges.push_back(flow_edge(u,v,c,1));
        edges.push_back(flow_edge(v,u,0,0));
        g[u].push_back(edge_id);
        g[v].push_back(edge_id+1);
        edge_id += 2;
    }

    cout << edmonds_karp_maxflow(0,n-1,n,g,edges) << endl;
}