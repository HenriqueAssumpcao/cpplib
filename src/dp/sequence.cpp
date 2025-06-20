#include "dp/sequence.hpp"

/*
Problem: Given two arrays A and B, find the longest common subsequence
Solution: Build a dp table where dp[i][j] is the longest common subsequence betweeen A[1,...,i] and B[1,...,j]
Complexity: O(nm)
*/
void longest_common_subsequence_dp(std::string &s1, std::string &s2, llmatrix &dp){
    int n = s1.size(),m = s2.size();
    dp = llmatrix(n+1,std::vector<ll>(m+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = std::max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
}

/*
Problem: Given two strings, find the longest common substring
Solution: Build a dp table where dp[i][j] is the size of the longest common suffix ending at i and j
Complexity: O(nm)
*/
int longest_common_substring_dp(std::string &s1, std::string &s2, llmatrix &dp, std::string &lcs){
    int n = s1.size(),m = s2.size();
    dp = llmatrix(n,std::vector<ll>(m,0));

    int ret = 0;
    lcs = "";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = (i > 1 && j > 1) ? (dp[i-1][j-1] + 1) : 1;
                if(dp[i][j] > ret){
                    lcs = s1.substr(i-ret+1,i);
                }
                else if(dp[i][j] == ret){
                    lcs += s1.substr(i-ret+1,i);
                }
            } 
            else{
                dp[i][j] = 0;
            }
        }
    }

    return ret;
}

/*
Problem: Given an array with n elements, find the longest increasing subsequence
Solution: DP where lis(i) is the size of the longest increasing subsequence ending at i
Complexity: O(n^2)
*/

int lis_dp(int &n, std::vector<int> &vec, std::vector<int> &lis){
    lis = std::vector<int>(n,0);

    lis[0] = 1;

    int ret = 0;

    for(int i = 1; i < n; i++){
        int aux = 0;
        for(int j = 0; j < i; j++){
            if(vec[j] < vec[i]){
                aux = std::max(aux,lis[j]);
            }
            lis[i] = 1 + aux;
            ret = std::max(ret,lis[i]);
        }
    }

    return ret;
}

/*
Problem: Given an array with n elements, find the longest increasing subsequence
Solution: DP + binary search
Complexity: O(nlogn)
*/

int bin_search_lesser(int s, int left, int right, std::vector<int> &arr){
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

int lis_dp_binsearch(int &n, std::vector<int> &vec, std::vector<int> &lis){
    std::vector<int> aux(n+1,IINF);
    aux[0] = -IINF;

    lis = std::vector<int>(n+1,0);

    int ret = 0;

    for(int i = 0; i < n; i++){
        int j = bin_search_lesser(vec[i],0,n,aux);
        lis[i+1] = j+1;
        ret = std::max(ret,lis[i+1]);
        if(j < n){
            aux[j+1] = vec[i];
        }
    }
    return ret;
}


/*
Problem: Given a sequence of integers, find the number of increasing subsequences of length k
Solution: Build a dp table where dp[i][j] stores the number of increasing subsequences ending at i of length j
Complexity: O(n^2k)
*/
void cis_dp(int &n, int &k,std::vector<ll> &a, llmatrix &dp){
    dp = llmatrix(n+1,std::vector<ll>(k+1,0));

    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= k; j++){
            for(int l = 1; l <= i-1; l++){
                if(a[l-1] < a[i-1]){
                    dp[i][j] += dp[l][j-1];
                }
            }
        }
    }
}