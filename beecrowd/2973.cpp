#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

template <typename T>
void print_vector(vector<T> &vec){
    for(unsigned i = 0; i < vec.size(); i++){
        cout << vec[i] << " "; 
    }
    cout << endl;
}

template <typename T>
void print_matrix(vector<vector<T>> &M){
    for(unsigned i = 0; i < M.size(); i++){
        print_vector<T>(M[i]);
    }
}


int sol_t(int t,vector<int> &times, int c){
    // cout << "here!" << endl;
    // cout << "c = " << c << endl;
    vector<int> times_per_subarray(c,0);


    int curr_arr = 0;
    int right = 0;
    int max = -1;
    
    // cout << "here!!" << endl;

    while(curr_arr < c){
        if(times_per_subarray[curr_arr] + times[right] <= t){
            times_per_subarray[curr_arr] += times[right];
            right++;
            if(times_per_subarray[curr_arr] > max){
                max = times_per_subarray[curr_arr];
            }
        }
        else{
            curr_arr++;
        }
    }
    if(right < times.size()){
        max = -1;
    }

    // print_vector<int>(times_per_subarray);
    return max;
}

int bin_search_sol(int left, int right, vector<int> &times, int &c){
    cout << "left = " << left << ";right = " << right << endl;
    if(left == right){
        return sol_t(left,times,c);
    }
    else if(right-left == 1){
        int ret_left = sol_t(left,times,c);
        int ret_right = sol_t(right,times,c);
        if(ret_right == -1){
            return ret_right;
        }
        else{
            if(ret_left == -1){
                return ret_right;
            }
            else{
                return ret_left;
            }
        }
    }
    int middle = left + (right-left+1)/2;
    cout << "middle = " << middle << endl;
    cout << sol_t(middle,times,c) << endl;

    if(sol_t(middle,times,c) == -1){
        return bin_search_sol(middle+1,right,times,c);
    }
    else{
        return bin_search_sol(left,middle,times,c);
    }
}




int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);

    int n,c,t;
    cin >> n >> c >> t;

    c = min(c,n);

    // vector<int> buckets(n);
    vector<int> times(n);
    
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        times[i] = 1 + ((temp-1)/t);
    }
    cout << n << " " << c << " " << t << endl;

    print_vector<int>(times);

    int min_t = *max_element(times.begin(),times.end());
    int max_t = accumulate(times.begin(),times.end(),0);

    cout << bin_search_sol(min_t,max_t,times,c) << endl;


    return 0;
}
