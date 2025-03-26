#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);

    string cypher,crib;

    cin >> cypher;
    cin >> crib;

    int cy_pos = 0, counter = 0, found_eq,i;

    while(cy_pos < cypher.size()){
        found_eq = 0;
        for(i = 0; i < crib.size();i++){
            if(cy_pos + i < cypher.size()){
                if(cypher[cy_pos+i] == crib[i]){
                    found_eq = 1;
                }
            }
            else{
                break;
            }
        }
        cy_pos++;
        if(found_eq == 0 && i == crib.size()){
            counter++;
        }
    }
    cout << counter << endl;

    return 0;
}
