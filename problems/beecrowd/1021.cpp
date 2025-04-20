#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph
typedef vector<list<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;

void cashiers_alg(double val,vector<double> &cash_vals,unordered_map<double,int> &cash2count){
    int i;
    while(val > 0){
        i = -1;
        for(unsigned j = 0; j < cash_vals.size(); j++){
            if(cash_vals[j] <= val){
                i = j;
            }
        }
        cash2count[cash_vals[i]]++;
        val = val - cash_vals[i];
        val = round(val * 100.0)/100.0;
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    double val;

    cin >> val;

    vector<double> cash_vals = {0.01,0.05,0.10,0.25,0.50,1,2,5,10,20,50,100};
    unordered_map<double,int> cash2count;

    cashiers_alg(val,cash_vals,cash2count);

    cout << fixed;
    cout << setprecision(2);
    cout << "NOTAS:" << endl;
    for(int i = 11; i > 5; i--){
        cout << cash2count[cash_vals[i]] << " nota(s) de R$ " << cash_vals[i] << endl;
    }
    cout << "MOEDAS:" << endl;
    for(int i = 5; i >= 0; i--){
        cout << cash2count[cash_vals[i]] << " moeda(s) de R$ " << cash_vals[i] << endl;
    }

    

    return 0;
}
