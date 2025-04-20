#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

int sol_dp(int &n, vector<int> &height){
    vector<int> dp_left(n),dp_right(n);
    
    dp_left[0] = 1;
    for(int i = 1; i < n; i++){
        if(dp_left[i-1] < height[i]){
            dp_left[i] = dp_left[i-1] + 1;
        }
        else if(dp_left[i-1] == height[i]){
            dp_left[i] = dp_left[i-1];
        }
        else{
            dp_left[i] = height[i];
        }
    }
    
    dp_right[n-1] = 1;
    for(int i = n-2; i>=0; i--){
        if(dp_right[i+1] < height[i]){
            dp_right[i] = dp_right[i+1] + 1;
        }
        else if(dp_right[i+1] == height[i]){
            dp_right[i] = dp_right[i+1];
        }
        else{
            dp_right[i] = height[i];
        }
    }

    int ret = -1;
    for(int i = 0; i < n; i++){
        ret = max(ret,min(dp_left[i],dp_right[i]));
    }

    return ret;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    vector<int> height(n);

    for(int i = 0; i < n; i++){
        cin >> height[i];
    }

    cout << sol_dp(n,height) << endl;

    return 0;
}
