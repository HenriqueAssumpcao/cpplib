#include<bits/stdc++.h>

using namespace std;

#define IINF INT_MAX/2

int maxSubArray(vector<int>& nums) {
    int curr_sum = 0;
    int best_sum = -IINF;

    for(int i = 0; i < nums.size(); i++){
        curr_sum = max(nums[i],curr_sum+nums[i]);
        best_sum = max(curr_sum,best_sum);
    }

    return best_sum;
}