#include<bits/stdc++.h>

using namespace std;

#define endl '\n'


int sol(string s, int m){
    int n = s.length();
    map<char,int> visited;

    int left = 0, right = 0;
    int ret = 0, num_distinct = 0;
    while(right < n){
        // Move right pointer right as much as we can
        while(right < n && num_distinct <= m){
            visited[s[right]]++;
            if(visited[s[right]] == 1){
                num_distinct++;
            }
            right++;
        }

        // If moved beyond limit we need to subtract 1
        ret = (num_distinct > m) ? max(ret,right-left-1) : max(ret,right-left);

        // Move left pointer right until substring is within bounds
        while(num_distinct > m){
            visited[s[left]]--;
            if(visited[s[left]] == 0){
                num_distinct--;
            }
            left++;
        }
    }
    return ret;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int m;
    string s;
    while(cin >> m){
        if(m == 0){
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n' ); 
        getline(cin,s);

        cout << sol(s,m) << endl;
    }
    return 0;
}
