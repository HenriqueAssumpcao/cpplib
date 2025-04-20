#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);

    map<int,vector<string>> int2braille;
    int2braille[0] = {".*","**",".."};
    int2braille[1] = {"*.","..",".."};
    int2braille[2] = {"*.","*.",".."};
    int2braille[3] = {"**","..",".."};
    int2braille[4] = {"**",".*",".."};
    int2braille[5] = {"*.",".*",".."};
    int2braille[6] = {"**","*.",".."};
    int2braille[7] = {"**","**",".."};
    int2braille[8] = {"*.","**",".."};
    int2braille[9] = {".*","*.",".."};

    map<vector<string>,int> braille2int;

    for(int i = 0; i < 10; i++){
        braille2int[int2braille[i]] = i;
    }
    
    int d;
    char mode;
    string inpt;
    while(cin >> d){
        if(d > 0){
            cin >> mode;
            if(mode == 'S'){
                cin >> inpt;
                for(int i =0; i < 3; i++){
                    for(int j = 0; j < d-1; j++){
                        cout << int2braille[(int)inpt[j]-48][i] << " ";
                    }
                    cout << int2braille[(int)inpt[d-1]-48][i] << endl;
                }
            }
            else if(mode == 'B'){
                vector<vector<string>> braille_inpt(d,vector<string>(3));
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < d; j++){
                        cin >> inpt;
                        braille_inpt[j][i] = inpt;
                    }
                }
                for(int i =0 ; i < d; i++){
                    cout << braille2int[braille_inpt[i]];
                }
                cout << endl;
            }
        }
    }


    return 0;
}
