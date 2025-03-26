#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<int>> imatrix;

void knapsack_dp(int n, int w, vector<int> &values, vector<int> &weights, imatrix &opt, vector<int> &sol){
    opt = imatrix(n+1,vector<int>(w+1,0));
    sol = vector<int>(n,0);

    for(int i = 0; i < n; i++){
        for(int ww = 0; ww <= w; ww++){
            if(weights[i] > ww || (opt[i][ww] > values[i] + opt[i][ww-weights[i]])){
                opt[i+1][ww] = opt[i][ww];
            }
            else{
                opt[i+1][ww] = values[i] + opt[i][ww-weights[i]];
            }
        }
    }

    int temp = w;
    for(int i = n-1; i >= 0; i--){
        if(opt[i+1][temp] > opt[i][temp]){
            sol[i] = 1;
            temp -= weights[i];
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,w=50;
    cin >> n;

    while(n--){
        int pac;
        cin >> pac;
        vector<int> values(pac),weights(pac);
        for(int i = 0; i < pac; i++){
            cin >> values[i] >> weights[i];
        }
        imatrix opt;
        vector<int> sol;
        knapsack_dp(pac,w,values,weights,opt,sol);

        int sol_weight = 0;
        for(int i = 0; i < pac; i++){
            if(sol[i] == 1){
                sol_weight += weights[i];
            }
        }

        cout << opt[pac][w] << " brinquedos" << endl;
        cout << "Peso: " << sol_weight << " kg" << endl;
        cout << "sobra(m) " << pac - accumulate(sol.begin(),sol.end(),0) << " pacote(s)" << endl;
        cout << endl;
    }

    return 0;
}
