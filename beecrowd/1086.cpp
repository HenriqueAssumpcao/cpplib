#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


int sol(int height, int num_cols, int k,vector<int> &wood_sizes,vector<int> woodcount){
    int pieces_used = 0, cols_tiled = 0;

    if(woodcount[height] > 0){
        cols_tiled += min(num_cols,woodcount[height]);
        pieces_used = cols_tiled;
        woodcount[height] = 0;
    }
    for(int i = 0; i < k; i++){
        if(cols_tiled == num_cols){
            return pieces_used;
        }
        int curr_size = wood_sizes[i];
        int temp = height-curr_size;
        if(temp >= 0 && woodcount[curr_size] > 0 && woodcount[temp] > 0){
            if(temp == curr_size && woodcount[temp] == 1){
                continue;
            }
            woodcount[temp]--;
            woodcount[curr_size]--;
            pieces_used += 2;
            cols_tiled++;
        }
    }
    
    return IINF;
}





int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    
    int m,n;

    while(cin >> m >> n){
        if(m == 0){
            break;
        }
        int l,k;
        cin >> l;
        cin >> k;

        vector<int> wood_sizes(k);
        vector<int> woodcount(1e5,0);

        int temp;
        for(int i = 0; i < k; i++){
            cin >> temp;
            wood_sizes[i] = temp;
            woodcount[temp]++;
        }

        sort(wood_sizes.begin(),wood_sizes.end());

        int ret = IINF;
        if((m*100) % l == 0){
            ret = min(ret,sol(n,(m*100)/l,k,wood_sizes,woodcount));
        }
        if((n*100) % l == 0){
            ret = min(ret,sol(m,(n*100)/l,k,wood_sizes,woodcount));
        }

        if(ret == IINF){
            cout << "impossivel" << endl;
        }
        else{
            cout << ret << endl;
        }

    }




    return 0;
}
