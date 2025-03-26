#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<int>> imatrix;

int brute_force(int &row, int &col,int &n, int &m, imatrix &tab, int curr_eaten){
    int ret = curr_eaten;
    int r,c,rr,cc;

    r = row-2;c=col-2;
    rr = row-1;cc=col-1;

    if((r >= 0 && r < n) && (c >= 0 && c < m) && tab[r][c] == 0){
        if(tab[rr][cc] == 2){
            tab[row][col] = 0;
            tab[r][c] = 1;
            tab[rr][cc] = 0;
            ret = max(ret,brute_force(r,c,n,m,tab,curr_eaten+1));
            tab[row][col] = 1;
            tab[r][c] = 0;
            tab[rr][cc] = 2;
        }
    }

    r = row-2;c=col+2;
    rr = row-1;cc=col+1;

    if((r >= 0 && r < n) && (c >= 0 && c < m) && tab[r][c] == 0){
        if(tab[rr][cc] == 2){
            tab[row][col] = 0;
            tab[r][c] = 1;
            tab[rr][cc] = 0;
            ret = max(ret,brute_force(r,c,n,m,tab,curr_eaten+1));
            tab[row][col] = 1;
            tab[r][c] = 0;
            tab[rr][cc] = 2;
        }
    }

    r = row+2;c=col-2;
    rr = row+1;cc=col-1;

    if((r >= 0 && r < n) && (c >= 0 && c < m) && tab[r][c] == 0){
        if(tab[rr][cc] == 2){
            tab[row][col] = 0;
            tab[r][c] = 1;
            tab[rr][cc] = 0;
            ret = max(ret,brute_force(r,c,n,m,tab,curr_eaten+1));
            tab[row][col] = 1;
            tab[r][c] = 0;
            tab[rr][cc] = 2;
        }
    }

    r = row+2;c=col+2;
    rr = row+1;cc=col+1;

    if((r >= 0 && r < n) && (c >= 0 && c < m) && tab[r][c] == 0){
        if(tab[rr][cc] == 2){
            tab[row][col] = 0;
            tab[r][c] = 1;
            tab[rr][cc] = 0;
            ret = max(ret,brute_force(r,c,n,m,tab,curr_eaten+1));
            tab[row][col] = 1;
            tab[r][c] = 0;
            tab[rr][cc] = 2;
        }
    }

    return ret;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m;

    while(cin >> n >> m){
        if(n == 0){
            break;
        }
        int k = (n*m) % 2 == 0 ? (n*m)/2 : ((n*m)/2)+1;
        vector<int> placements(k);


        int row,col;
        vector<vector<int>> tab(n,vector<int>(m,-1));
        vector<pair<int,int>> to_visit;
        for(int i = 0; i < k; i++){
            cin >> placements[i];
            row = (2*i) / m;
            col = (m%2 == 0) ? (((2*i) % m) + (row % 2)) : ((2*i) % m);

            tab[row][col] = placements[i];
            if(placements[i] == 1){
                to_visit.push_back({row,col});
            }
        }
    
        int ret = 0;
        for(auto [row,col] : to_visit){
            ret = max(ret,brute_force(row,col,n,m,tab,0));
        }

        cout << ret << endl;
    }

    return 0;
}
