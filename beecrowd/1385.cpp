#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

void generate_valid_partitions(int p, int &n, string &s, vector<int> &state,vector<vector<string>> &valid_partitions,bool &is_final){
    if(p == n){
        if(accumulate(state.begin(),state.end(),0) != s.length()){
            return;
        }
        string temp = s.substr(0,state[0]);
        if(temp.length() > 1 && temp[0] == '0'){
            return;
        }
        vector<string> ans;
        ans.push_back(temp);
        int cumul = stoi(temp);
        int counter = state[0];
        for(int i = 1; i < n-1; i++){
            temp = s.substr(counter,state[i]);
            if(temp.length() > 1 && temp[0] == '0'){
                return;
            }
            ans.push_back(temp);
            cumul += stoi(temp);
            counter += state[i];
        }
        temp = s.substr(counter,state[n-1]);
        if(temp.length() > 1 && temp[0] == '0'){
            return;
        }
        ans.push_back(temp);
        if(stoi(temp) == cumul){
            valid_partitions.push_back(ans);
        }
    }
    else{
        int digit_lim = is_final ? 4 : 3;
        if(p == n-1){
            digit_lim++;
        }
        for(int i = 1; i <= digit_lim; i++){
            state.push_back(i);
            generate_valid_partitions(p+1,n,s,state,valid_partitions,is_final);
            state.pop_back();
        }
    }
}


bool find_ans(int p, int &m, int &n,vector<vector<string>> &state, vector<vector<vector<string>>> &possibilities,vector<vector<string>> &ans){
    if(p == m){
        bool is_valid = true;
        for(int col = 0; col < n; col++){
            int cumul = 0;
            for(int row = 0; row < m-1; row++){
                cumul += stoi(state[row][col]);
            }
            if(cumul != stoi(state[m-1][col])){
                is_valid = false;
                break;
            }
        }
        if(is_valid){
            ans = state;
        }
        return is_valid;
    }
    else{
        for(int i = 0; i < possibilities[p].size(); i++){
            state.push_back(possibilities[p][i]);
            if(find_ans(p+1,m,n,state,possibilities,ans) == true){
                return true;
            }
            state.pop_back();
        }
        return false;
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int c;
    cin >> c;
    while(c--){
        string temp;
        int n;
        cin >> temp;

        n = ((temp.length()-6)/2)+1;

        string aux = "";
        for(int i = 0; i < n-1; i++){
            aux += temp.substr(i*2,2) + " ";
        }
        aux += "Totals";
        cout << aux << endl;
        
        int right = 0;
        string name,number;

        vector<vector<vector<string>>> possibilities;
        vector<string> names;

        int m = 0;
        while(cin >> temp){
            right = 0;
            while(temp.at(right) < '0' || temp.at(right) > '9'){
                right++;
            }
            name = temp.substr(0,right);
            number = temp.substr(right);
            names.push_back(name);

            vector<int> state = {};
            vector<vector<string>> valid_partitions;
            bool is_final;
            if(temp.substr(0,2) != "TP"){
                is_final = false;
                generate_valid_partitions(0,n,number,state,valid_partitions,is_final);
                possibilities.push_back(valid_partitions);
                m++;
            }
            else{
                is_final = true;
                generate_valid_partitions(0,n,number,state,valid_partitions,is_final);
                possibilities.push_back(valid_partitions);
                m++;
                break;
            }

        }

        vector<vector<string>> ans,state = {};

        if(possibilities[m-1].size() > 2){
            reverse(possibilities[m-2].begin(),possibilities[m-2].end());
        }

        reverse(possibilities[0].begin(),possibilities[0].end());
        find_ans(0,m,n,state,possibilities,ans);

        for(int i = 0; i < m; i++){
            cout << names[i] << " ";
            for(int j = 0; j < n-1; j++){
                cout << ans[i][j] << " ";
            }
            cout << ans[i][n-1] << endl;
        }

    }

    return 0;
}
