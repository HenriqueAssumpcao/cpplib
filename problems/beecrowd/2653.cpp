#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    //

    string line;
    unordered_map<string,int> m;

    while(getline(cin,line)){
        m[line]++;
    }
    
    cout << m.size() << endl;

    return 0;
}