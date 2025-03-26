#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

string reconstruct(string &preo, string &ino){
    int pos = ino.find(preo[0]);
    string ret;
    
    string left_ino = ino.substr(0,pos);
    string right_ino = ino.substr(pos+1,ino.length());

    if(left_ino.length() != 0 || right_ino.length() != 0){
        if(left_ino.length() > 0){
            string left_preo = preo.substr(1,left_ino.length());
            string ret_left = reconstruct(left_preo,left_ino);
            ret.append(ret_left);
        }
        if(right_ino.length() > 0){
            string right_preo = preo.substr(1+left_ino.length(),left_ino.length()+right_ino.length());
            string ret_right = reconstruct(right_preo,right_ino);
            ret.append(ret_right);
        }
    }
    ret += preo[0];

    return ret;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,bt_size;
    string preo, ino, poso;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> bt_size >> preo >> ino;
        poso = reconstruct(preo,ino);
        cout << poso << endl;
    }
    return 0;
}
