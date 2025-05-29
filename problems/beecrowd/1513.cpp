#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph
typedef vector<list<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<char>> cmatrix;
typedef vector<vector<ll>> llmatrix;

vector<pair<int,int>> kmoves = {{-2,-1},{-2,1},{-1,-2},{1,-2},{2,-1},{2,1},{-1,2},{1,2}};

void bfs(int s, int n, graph &g, vector<int> &layer, cmatrix &board, map<pair<int,int>,int> &pos2node, map<int,pair<int,int>> &node2pos){
    layer = vector<int>(n,0);
    vector<bool> visited(n,0);
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < kmoves.size(); i++){
            pair<int,int> pos = {node2pos[u].first + kmoves[i].first,node2pos[u].second + kmoves[i].second};
            if(pos.first >= 0 && pos.first < board.size() && pos.second >= 0 && pos.second < board[0].size() && board[pos.first][pos.second] != '#'){
                int v = pos2node[pos];
                if(visited[v] == 0){
                    visited[v] = 1;
                    layer[v] = layer[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}

void tsp_dp(int v, int S, int &k,imatrix &dp, imatrix &dist_mat){
    if(dp[v][S] == -1){
        if(S == (1 << v)){
            dp[v][S] = dist_mat[k][v];
        }
        else if((S & (1 << v)) == 0){
            dp[v][S] = IINF;
        }
        else{
            int temp = IINF;
            for(int i = 0; i < k; i++){
                if(i != v && (S & (1 << i))){
                    tsp_dp(i,S & (~(1 << v)),k,dp,dist_mat);
                    temp = min(temp,dp[i][S & (~(1 << v))] + dist_mat[v][i]);
                }
            }
            dp[v][S] = temp;
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m,k;

    while(cin >> n >> m >> k){
        if(n == 0){
            break;
        }
        cmatrix board(n,vector<char>(m));
        map<pair<int,int>,int> pos2node;
        map<int,pair<int,int>> node2pos;
        int count = 0,horse_node;
        vector<int> tgt_nodes;


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> board[i][j];
                if(board[i][j] != '#'){
                    pos2node[{i,j}] = count;
                    node2pos[count] = {i,j};
                    if(board[i][j] == 'C'){
                        horse_node = count;
                    }
                    else if(board[i][j] == 'P'){
                        tgt_nodes.push_back(count);
                    }
                    count++;
                }
            }
        }
        tgt_nodes.push_back(horse_node);

        graph g(count);
        imatrix dist_mat(k+1,vector<int>(k+1,0));
        vector<int> layer;
        for(int u = 0; u < k+1; u++){
            bfs(tgt_nodes[u],count,g,layer,board,pos2node,node2pos);
            for(int v = 0; v < k+1;v++){
                dist_mat[u][v] = layer[tgt_nodes[v]];
            }
        }

        imatrix dp(k,vector<int>(1 << k,-1));
        int ret = IINF;
        for(int v = 0; v < k; v++){
            tsp_dp(v,(1 << k)-1,k,dp,dist_mat);
            ret = min(ret,dp[v][(1 << k)-1] + dist_mat[v][k]);
        }
        cout << ret << endl;
    }




    return 0;
}