#include<bits/stdc++.h>

using namespace std;


int bin_search_lesser(int s, int left, int right, vector<int> &arr){
    // Finds the index of the greatest element in arr that is strictly smaller than s
    if(left == right || (right - left) == 1){
        if(arr[left] == s){
            return left-1;
        }
        else{
            return left;
        }
    }

    int middle = left + ((right-left+1)/2);

    if(arr[middle] < s){
        return bin_search_lesser(s,middle,right,arr);
    }
    else if(arr[middle] > s){
        return bin_search_lesser(s,left,middle,arr);
    }

    return middle-1;
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> aux(n+1,INT_MAX);
    aux[0] = -INT_MAX;

    vector<int> lis(n+1,0);

    int ret = 0;

    for(int i = 0; i < n; i++){
        int j = bin_search_lesser(nums[i],0,n,aux);
        lis[i+1] = j + 1;
        ret = max(ret,lis[i+1]);
        if(j < n){
            aux[j+1] = nums[i];
        }
    }
    return ret;
}