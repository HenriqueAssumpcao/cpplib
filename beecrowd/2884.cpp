#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

void switch_lamps(vector<int> &lamps_on, vector<int> &tgt_lamps){
    for(int lamp: tgt_lamps){
        lamps_on[lamp] = (lamps_on[lamp] + 1) % 2;
    }
}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);


    int n,m;
    cin >> n >> m;

    vector<int> lamps_on(m,0);

    int l;
    cin >> l;
    int i;
    while(l--){
        cin >> i;
        i--;
        lamps_on[i] = 1;
    }

    vector<vector<int>> incd(n);
    int k,j;
    for(int i = 0; i < n; i++){
        cin >> k;
        while(k--){
            cin >> j;
            j--;
            incd[i].push_back(j);
        }
    }

    vector<vector<int>> memory(n+1,vector<int>(m,0));
    memory[0] = lamps_on;

    int counter = 0, ret = 0;
    while(1){
        switch_lamps(lamps_on,incd[counter]);
        ret++;
        counter = ret % n;
        if(accumulate(lamps_on.begin(),lamps_on.end(),0) == 0){
            break;
        }
        else if(memory[counter] == lamps_on){
            ret = -1;
            break;
        }
    }

    cout << ret << endl;

    return 0;
}
