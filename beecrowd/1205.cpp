#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<list<int>> graph; // unweighted graph


void dijkstra_prob(int n, graph &g, double p, int k, int s, int t, vector<int> &snipers,vector<double> &probs){
    vector<int> ammo(n);
    probs.resize(n);
    for(int i = 0; i < n; i++){
        probs[i] = 0;
        ammo[i] = 0;
    }

    probs[s] = (snipers[s] < k) ? pow(p,snipers[s]) : 0;
    ammo[s] = k - snipers[s];

    double epsilon = 1e-6;

    priority_queue<pair<double,int>> pq;
    pq.emplace(probs[s],s);

    while(pq.size()){
        auto [prob,u] = pq.top();
        pq.pop();
        if(u == t){
            break;
        }
        if(prob >= probs[u]){
            for(int v : g[u]){
                int ammo_left = ammo[u] - snipers[v];
                double temp = probs[u] * pow(p,snipers[v]);
                if(ammo_left >= 0 && temp-probs[v] > epsilon){
                    probs[v] = temp;
                    ammo[v] = ammo_left;
                    pq.emplace(probs[v],v);
                }
            }
        }
    }
}



int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m,k;
    double p;

    cout << fixed;
    cout << setprecision(3);

    while(cin >> n >> m >> k >> p){
        graph g(n);

        int u,v;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            u--;v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        int a;
        cin >> a;

        vector<int> snipers(n,0);
        int pos;
        while(a--){
            cin >> pos;
            pos--;
            snipers[pos]++;
        }

        int s,t;

        cin >> s >> t;
        s--;t--;

        vector<double> probs;
        dijkstra_prob(n,g,p,k,s,t,snipers,probs);

        cout << probs[t] << endl;

    }

    return 0;
}
