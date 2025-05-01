#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2
 
typedef long long ll;
 
struct edge{
    int to;
    ll cap,flow;
    edge *opp;
 
    edge(int to, ll cap, ll flow, edge *opposite):to(to),cap(cap),flow(flow),opp(opp){};
};
 
typedef vector<vector<edge*>> flow_graph;
 
ll find_aug_path(int s, int t,int &n, flow_graph &g, vector<pair<int,edge*>> &parent){
    parent = vector<pair<int,edge*>>(n,{-1,nullptr});
 
    vector<bool> is_visited(n,0);
    is_visited[s] = 1;
 
    queue<pair<int,ll>> q;
 
    q.push({s,LLINF});
 
    while(q.size()){
        auto [u,curr_flow] = q.front();
        q.pop();
        for(edge *e : g[u]){
            if(is_visited[e->to] == 0 && e->cap > 0){
                is_visited[e->to] = 1;
                parent[e->to] = {u,e};
                curr_flow = min(curr_flow,e->cap);
                if(e->to == t){
                    return curr_flow;
                }
                q.push({e->to,curr_flow});
            }
        }
    }
    return 0;
}
 
ll edmonds_karp_maxflow(int s, int t, int &n, flow_graph &g){
    ll max_flow = 0;
    vector<pair<int,edge*>> parent;
 
    ll flow;
    while(flow = find_aug_path(s,t,n,g,parent)){
        max_flow += flow;
        int temp = t;
        while(temp != s){
            int prev = parent[temp].first;
            edge *curr_edge = parent[temp].second;
            curr_edge->cap -= flow;
            curr_edge->flow += flow;
            curr_edge->opp->cap += flow;
            curr_edge->opp->flow -= flow;
            temp = prev;
        }
    }
 
    return max_flow;
}
 
 
int main(){
 
    int n,m;
 
    cin >> n >> m;
 
    flow_graph g(n);
    int u,v;
    ll c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        u--;v--;
        edge *e1 = new edge(v,c,0,nullptr),*e2 = new edge(u,0,0,nullptr);
        e1->opp = e2;e2->opp = e1;
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
 
    cout << edmonds_karp_maxflow(0,n-1,n,g) << endl;
 
    return 0;
}