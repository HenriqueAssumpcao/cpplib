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


int num_flipped(string &s){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            count++;
        }
    }
    return count;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << num_flipped(s) << endl;
    }

    return 0;
}
