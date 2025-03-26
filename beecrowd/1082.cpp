#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<list<int>> graph; // unweighted graph


vector<vector<int>> connected_components(graph &g, int n){
    vector<vector<int>> ccs;

    vector<int> is_explored(n);
    int num_explored = 0;
    for(int i = 0; i < n; i++){
        is_explored[i] = 0;
    }

    queue<int> q;
    q.push(0);
    
    int u;
    vector<int> curr_component;
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
            curr_component.push_back(u);
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
    std::ios::sync_with_stdio(0);cin.tie(0);
    vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    unordered_map<char,int> char2int;
    for(unsigned i = 0; i < alphabet.size(); i++){
        char2int[alphabet[i]] = i;
    }

    int N,n,m;
    char u,v;
    cin >> N;
    for(int i = 0; i < N; i++){
        // Read graph
        cout << "Case #" << i+1 << ":" << endl;
        cin >> n >> m;
        graph g(n);
        for(int j = 0; j < m; j++){
            cin >> u >> v;
            g[char2int[u]].push_back(char2int[v]);
            g[char2int[v]].push_back(char2int[u]);
        }
        vector<vector<int>> ccs = connected_components(g,n);
        for(vector<int> comp : ccs){
            sort(comp.begin(),comp.end());
            for(int u : comp){
                cout << alphabet[u] << ",";
            }
            cout << endl;
        }
        cout << ccs.size() << " connected components" << endl << endl;
    }

    return 0;
}
