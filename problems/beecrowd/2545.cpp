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

void dfs_visit(int u, int &n, graph &g,vector<int> &color,vector<int> &start,vector<int> &finish,vector<int> &pred){
    dfs_time++;
    color[u] = 1;
    start[u] = dfs_time;

    for(int v : g[u]){
        if(color[v] == 0){
            pred[v] = u;
            dfs_visit(v,n,g,color,start,finish,pred);
        }
    }

    dfs_time++;
    color[u] = 2;
    finish[u] = dfs_time;
}

void dfs(int &n, graph &g, vector<int> &finish){
    vector<int> color(n,0);
    vector<int> pred = vector<int>(n,-1),start = vector<int>(n,0);
    finish = vector<int>(n,0);
    dfs_time = 0;
    for(int u = 0; u < n; u++){
        if(color[u] == 0){
            dfs_visit(u,n,g,color,start,finish,pred);
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin >> n){
        graph g(n);
        for(int u = 0; u < n; u++){
            int m;
            cin >> m;
            for(int j = 0; j < m; j++){
                int v;
                cin >> v;
                v--;
                g[u].push_back(v);
            }
        }
        vector<int> finish;
        dfs(n,g,finish);
        
        bool found_cycle = false;
        for(int u = 0; u < n; u++){
            for(int v : g[u]){
                if(finish[v] >= finish[u]){
                    found_cycle = true;
                }
            }
        }
        if(found_cycle){
            cout << -1 << endl;
        }
        else{
            int ret = 0;
            int num_removed = 0;
            vector<bool> visited(n,0);
            set<int> removed;
            while(num_removed < n){
                vector<int> to_insert;
                for(int u = 0; u < n; u++){
                    if(removed.find(u) == removed.end()){
                        bool zero_deg = true;
                        for(int v : g[u]){
                            if(removed.find(v) == removed.end()){
                                zero_deg = false;
                                break;
                            }
                        }
                        if(zero_deg){
                            num_removed++;
                            to_insert.push_back(u);
                        }
                    }
                }
                ret++;
                for(int u : to_insert){
                    removed.insert(u);
                }
            }
            cout << ret << endl;

        }
    }
    return 0;
}

