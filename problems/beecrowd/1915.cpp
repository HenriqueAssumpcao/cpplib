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

vector<int> encode_str(string s){
    vector<int> encoding;
    map<char,int> alph,occur;
    for(int i = 65; i <= 90; i++){
        alph[(char)i] = i-64;
    }

    for(char c : s){
        c = toupper(c);
        encoding.push_back(alph[c] + occur[c]*26);
        occur[c]++;
    }

    return encoding;
}

bool is_adj(vector<int> &e1, vector<int> &e2){
    int n = e1.size(),m = e2.size();

    // lcs dp
    imatrix dp(n+1,vector<int>(m+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(e1[i-1] == e2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    int num_to_remove = n+m-(2*dp[n][m]);
    return (num_to_remove % 5) == 0;
}


int main(){
    int n,m;
    cout << fixed;
    cout << setprecision(2);

    while(cin >> n >> m){
        if(n == 0){
            break;
        }
        imatrix encodings(n+m);
        int numv = n+m+2;
        graph g(numv);
        vector<flow_edge> edges;
        int eid = 0;
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            encodings[i] = encode_str(s);
            add_edge(numv-2,i,1,eid,edges,g);
        }
        for(int i = 0 ; i < m; i++){
            cin >> s;
            encodings[n+i] = encode_str(s);
            add_edge(n+i,numv-1,1,eid,edges,g);
        }

        for(int u = 0; u < n; u++){
            for(int v = n; v < n+m; v++){
                if(is_adj(encodings[u],encodings[v])){
                    add_edge(u,v,1,eid,edges,g);
                }
            }
        }

        double ret = dinic_maxflow(numv-2,numv-1,numv,g,edges)/((double)n);

        cout << "P = " << ret*100 << endl;

    }

    return 0;
}