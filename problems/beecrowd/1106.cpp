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
typedef vector<vector<double>> dmatrix;

template <typename T>
void print_vector(vector<T> &vec){
    for(unsigned i = 0; i < vec.size()-1; i++){
        cout << vec[i] << " "; 
    }
    cout << vec[vec.size()-1] << endl;
}

void post_order(int node,int &n,vector<pair<int,int>> &children, vector<int> &ret){
    if(node >= n){
        post_order(children[node-n].first,n,children,ret);
        post_order(children[node-n].second,n,children,ret);
        ret.push_back(node);
    }
}

double sol_dp(int n, int num_nodes, dmatrix &M, int root, vector<pair<int,int>> &children){
    dmatrix dp(num_nodes,vector<double>(num_nodes,0));

    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }

    vector<int> po;
    post_order(root,n,children,po);

    for(int k : po){
        int l = children[k-n].first,r = children[k-n].second;
        for(int i = 0; i < n; i++){
            if(dp[i][l] == 0){
                continue;
            }
            for(int j = 0; j < n; j++){
                if(dp[j][r] == 0){
                    continue;
                }
                dp[i][k] += dp[i][l]*dp[j][r]*M[i][j];
                dp[j][k] += dp[i][l]*dp[j][r]*M[j][i];
            }
        }
    }

    return dp[0][root];
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    cout << fixed;
    cout << setprecision(6);
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        dmatrix M(n,vector<double>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> M[i][j];
            }
        }
        int num_nodes = 2*n-1;
        vector<pair<int,int>> children(n-1);
        vector<int> parent(num_nodes,-1);
        for(int i = n; i < num_nodes; i++){
            cin >> children[i-n].first >> children[i-n].second;
            children[i-n].first--;children[i-n].second--;
            parent[children[i-n].first] = i;
            parent[children[i-n].second] = i;
        }
        int root;
        for(int i = n; i < num_nodes; i++){
            if(parent[i] == -1){
                root = i;
                break;
            }
        }

        cout << sol_dp(n,num_nodes,M,root,children) << endl;

    }

    return 0;
}
