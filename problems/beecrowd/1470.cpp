#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


vector<int> fold_tape(vector<int> &tape, int pos){
    int n = tape.size();
    vector<int> folded_tape;

    if(2*pos >= n){
        folded_tape.resize(pos);
        for(int i = 0; i < 2*pos-n; i++){
            folded_tape[i] = tape[i];
        }
        for(int i = 0; i < n-pos; i++){
            folded_tape[2*pos-n+i] = tape[2*pos-n+i] + tape[n-1-i];
        }
        
    }
    else{
        folded_tape.resize(n-pos);
        for(int i = 0; i < n-2*pos; i++){
            folded_tape[i] = tape[n-1-i];
        }
        for(int i = 0; i < pos; i++){
            folded_tape[n-2*pos+i] = tape[i] + tape[2*pos-1-i];
        }
    }

    return folded_tape;


}

bool brute_force(vector<int> &in_tape,vector<int> &out_tape){
    bool ret = 0;
    if(in_tape.size() == out_tape.size()){
        if(in_tape == out_tape || fold_tape(in_tape,0) == out_tape){
            ret = 1;
        }
    }
    else{
        int n = in_tape.size(),m = out_tape.size();
        if(*min_element(in_tape.begin(),in_tape.end()) > *max_element(out_tape.begin(),out_tape.end())){
            ret = 0;
        }
        else{
            for(int pos = 1; pos < n; pos++){
                if(max(pos,n-pos) >= m){
                    vector<int> temp = fold_tape(in_tape,pos);
                    ret |= brute_force(temp,out_tape);
                    if(ret == 1){
                        break;
                    }
                }
            }
        }
    }
    return ret;
}


int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m;

    while(cin >> n){
        vector<int> in_tape(n);
        for(int i = 0; i < n; i++){
            cin >> in_tape[i];
        }
        cin >> m;
        vector<int> out_tape(m);
        for(int i = 0; i < m; i++){
            cin >> out_tape[i];
        }
        if(brute_force(in_tape,out_tape) == 1){
            cout << "S" << endl;
        }
        else{
            cout << "N" << endl;
        }

    }


    return 0;
}
