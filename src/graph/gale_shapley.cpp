#include "graph/gale_shapley.hpp"

std::vector<int> gale_shapley(intmatrix &PA, intmatrix &PB){
    int n = PA.size(),m = PB.size();

    std::vector<int> matching(n,-1); // a-th entry is the element of B matched to a, -1 if unmatched
    std::vector<int> inv_matching(m,-1); // b-th entry is the element of A matched to b, -1 if unmatched
    std::vector<int> last_proposed(n,-1); // a-th entry stores the index of the last element proposed by a in its preference list
    
    intmatrix b_ids(m,std::vector<int>(n)); // b_ids[b][a] stores the index of a in b's preference list, hence b_ids[b][a] < b_ids[b][aa] if b prefers a to aa
    for(int b = 0; b < m; b++){
        for(int i = 0; i < n; i++){
            b_ids[b][PB[b][i]] = i; 
        }
    }

    std::queue<int> q; // stores the std::queue of elements of A yet to be matched
    for(int i = 0; i < n; i++){
        q.emplace(i);
    }
    int a,aa,b;
    while(q.size()){
        a = q.front();
        q.pop();
        b = PA[a][last_proposed[a]+1];
        last_proposed[a]++;

        if(inv_matching[b] == -1){
            matching[a] = b;
            inv_matching[b] = a;
        }
        else{
            aa = inv_matching[b];
            if(b_ids[b][a] < b_ids[b][aa]){
                matching[a] = b;
                inv_matching[b] = a;
                matching[aa] = -1;
                q.emplace(aa);
            }
            else{
                q.emplace(a);
            }
        }
    }
    return matching;
}