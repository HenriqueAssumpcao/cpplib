#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<list<int>> graph; // unweighted graph\

ll squared_dist(pair<int,int> &p, pair<int,int> &q){
    int diff1 = p.first - q.first, diff2 = p.second-q.second;
    
    return (diff1*diff1) + (diff2*diff2);
}

vector<set<int>> connected_components(graph &g, int n){
    vector<set<int>> ccs;

    vector<int> is_explored(n);
    int num_explored = 0;
    for(int i = 0; i < n; i++){
        is_explored[i] = 0;
    }

    queue<int> q;
    q.push(0);
    
    int u;
    set<int> curr_component;
    while(num_explored < n){
        if(q.size() > 0){
            u = q.front();
            q.pop();
        }
        else{
            ccs.push_back(curr_component);
            curr_component.erase(curr_component.begin(),curr_component.end());
            for(int i = 0; i < n; i++){
                if(is_explored[i] == 0){
                    u = i;
                    break;
                }
            }
        }
        if(is_explored[u] == 0){
            curr_component.insert(u);
            is_explored[u] = 1;
            num_explored++;
            for(int v : g[u]){
                q.push(v);
            }
        }
    }
    ccs.push_back(curr_component);
    return ccs;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int m,n,k;
    
    cin >> m >> n >> k;
    
    vector<pair<int,int>> coords(k+2);
    vector<ll> rad(k+2);
    
    int x,y,s;
    for(int i = 1; i <= k; i++){
        cin >> x >> y >> s;
        coords[i] = {x,y};
        rad[i] = s;
    }
    
    coords[0] = {0,0};coords[k+1] = {m,n};
    rad[0] = 0;rad[k+1] = 0;
    
    graph g(k+6);
    
    for(int i = 1; i < k+1;i++){
        for(int j = i+1; j < k+1; j++){
            if((rad[i]*rad[i] + 2*rad[i]*rad[j] + rad[j]*rad[j]) >= squared_dist(coords[i],coords[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        if(coords[i].first - rad[i] <= 0){
            g[i].push_back(k+2);
            g[k+2].push_back(i);
        }
        if(coords[i].first + rad[i] >= m){
            g[i].push_back(k+3);
            g[k+3].push_back(i);
        }
        if(coords[i].second - rad[i] <= 0){
            g[i].push_back(k+4);
            g[k+4].push_back(i);
        }
        if(coords[i].second + rad[i] >= n){
            g[i].push_back(k+5);
            g[k+5].push_back(i);
        }
    }

    vector<set<int>> ccs = connected_components(g,k+6);

    bool has_left_wall,has_right_wall,has_bottom_wall,has_top_wall;

    for(auto cc : ccs){
        has_left_wall = cc.find(k+2) != cc.end();
        has_right_wall = cc.find(k+3) != cc.end();
        has_bottom_wall = cc.find(k+4) != cc.end();
        has_top_wall = cc.find(k+5) != cc.end();

        if((has_left_wall && has_right_wall) || (has_top_wall && has_bottom_wall) || (has_top_wall && has_right_wall) || (has_bottom_wall && has_left_wall)){
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;
    
    return 0;
}

