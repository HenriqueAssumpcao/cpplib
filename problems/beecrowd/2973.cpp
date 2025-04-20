#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;


bool sol_t(int p,vector<int> &buckets, int c){
    vector<int> buckets_per_subarray(c,0);

    int curr_arr = 0;
    int right = 0;

    while(curr_arr < c && right < buckets.size()){
        if(buckets_per_subarray[curr_arr] + buckets[right] <= p){
            buckets_per_subarray[curr_arr] += buckets[right];
            right++;
        }
        else{
            curr_arr++;
        }
    }

    return right == buckets.size();
}

int bin_search_sol(int left, int right, vector<int> &buckets, int &c,int &t){
    if(left == right){
        if(sol_t(left*t,buckets,c)){
            return left;
        }
        else{
            return -1;
        }
    }
    else if(right-left == 1){
        if(!sol_t(right*t,buckets,c)){
            return -1;
        }
        else{
            if(!sol_t(left*t,buckets,c)){
                return right;
            }
            else{
                return left;
            }
        }
    }
    int middle = left + (right-left+1)/2;

    if(!sol_t(middle*t,buckets,c)){
        return bin_search_sol(middle+1,right,buckets,c,t);
    }
    else{
        return bin_search_sol(left,middle,buckets,c,t);
    }
}




int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,c,t;
    cin >> n >> c >> t;

    c = min(c,n);

    vector<int> buckets(n);
    
    for(int i = 0; i < n; i++){
        cin >> buckets[i];
    }

    int min_t = (*max_element(buckets.begin(),buckets.end()) - 1)/t;
    int max_t = ((accumulate(buckets.begin(),buckets.end(),0) - 1)/t)+1;

    cout << bin_search_sol(min_t,max_t,buckets,c,t) << endl;


    return 0;
}
