#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph
typedef vector<list<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;


int argmin(vector<int> &vec){
    int min = IINF;
    int idx = 0;
    for(int i = 0; i < vec.size();i++){
        if(vec[i] > 0 && vec[i] < min){
            min = vec[i];
            idx = i;
        }
    }

    return idx;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    vector<char> cards = {'A','2','3','4','5','6','7','8','9','D','Q','J','K'};
    map<char,int> card2id;
    for(int i = 0; i < cards.size(); i++){
        card2id[cards[i]] = i;
    }

    int n,k;
    int counter = 1;
    cin >> n >> k;
    k--;
    vector<vector<int>> handcount(n,vector<int>(cards.size(),0));

    string temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        for(int j = 0; j < 4; j++){
            handcount[i][card2id[temp[j]]]++;
        }
    }

    int card_recvd = 13;
    int curr_player = k;
    int has_joker = -1;

    for(int i = 0; i < n; i++){
        if(i != curr_player && (*max_element(handcount[i].begin(),handcount[i].end()) == 4)){
            cout << 1+i << endl;
            return 0;
        }
    }

    while(true){
        if(card_recvd == 13){ // received joker, passes one other card ahead
            has_joker = curr_player;

            int card_idx = argmin(handcount[curr_player]);
            handcount[curr_player][card_idx]--;
            card_recvd = card_idx;
        }
        else{
            handcount[curr_player][card_recvd]++;
            if(has_joker == curr_player){ // has joker and pass it ahead
                card_recvd = 13;
            }
            else{ // does not have joker and passes one other card ahead
                int card_idx = argmin(handcount[curr_player]);
                handcount[curr_player][card_idx]--;
                card_recvd = card_idx;
            }
            if(*max_element(handcount[curr_player].begin(),handcount[curr_player].end()) == 4){
                int winning_player = curr_player;
                for(int i = 0; i < curr_player; i++){
                    if(*max_element(handcount[i].begin(),handcount[i].end()) == 4){
                        winning_player = i;
                        break;
                    }
                }
                cout << 1+winning_player << endl;
                break;
            }
        }
        curr_player = (curr_player + 1) % n;
    }



    return 0;
}
