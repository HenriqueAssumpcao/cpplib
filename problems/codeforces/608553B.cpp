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

template <typename T>
void print_vector(vector<T> &vec){
    for(unsigned i = 0; i < vec.size(); i++){
        cout << vec[i] << " "; 
    }
    cout << endl;
}

vector<int> sol(int n, vector<int> &order){
    int left_ptr = 1,right_ptr = n;
    stack<int> ans;
    int idx = n-2;
    while(left_ptr < right_ptr){
        if(order[idx] == 0){
            ans.push(left_ptr);
            left_ptr++;
        }
        else{
            ans.push(right_ptr);
            right_ptr--;
        }
        idx--;
    }
    ans.push(left_ptr);

    vector<int> ans2(n);
    for(int i = 0; i < n; i++){
        ans2[i] = ans.top();
        ans.pop();
    }

    return ans2;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        string s;
        cin >> s;
        vector<int> order(n-1,0);
        for(int i = 0; i < n-1; i++){
            if(s[i] == '>'){
                order[i] = 1;
            }
        }

        vector<int> ans = sol(n,order);
        print_vector<int>(ans);
    }

    return 0;
}
