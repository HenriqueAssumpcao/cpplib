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

vector<pair<int,int>> kmoves = {{-2,-1},{-2,1},{-1,-2},{1,-2},{2,-1},{2,1},{-1,2},{1,2}};

void bfs(pair<int,int> &s,map<pair<int,int>,int> &layer){
    map<pair<int,int>,bool> visited;
    layer[s] = 0;
    visited[s] = 1;

    queue<pair<int,int>> q;
    q.push(s);

    while(q.size()){
        pair<int,int> u = q.front();
        q.pop();
        for(int i = 0; i < kmoves.size(); i++){
            pair<int,int> v = {u.first + kmoves[i].first,u.second + kmoves[i].second};
            if(v.first >= 0 && v.first < 8 && v.second >= 0 && v.second < 8 && visited[v] == 0){
                visited[v] = 1;
                layer[v] = layer[u] + 1;
                q.push(v);
            }
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    string s1,s2;
    while(cin >> s1 >> s2){
        pair<int,int> s = {(s1[1] - '0')-1,s1[0] - 'a'},t = {(s2[1] - '0')-1,s2[0] - 'a'};
        map<pair<int,int>,int> layer;
        bfs(s,layer);
        cout << "To get from " << s1 << " to " << s2 << " takes " << layer[t] << " knight moves." << endl;
    }

    return 0;
}
