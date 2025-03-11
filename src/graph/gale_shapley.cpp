#include <vector>
#include <queue>

#include "common.hpp"
#include "graph/gale_shapley.hpp"


bool prefers(int s, int h, int hh, intmatrix &sp){
    // returns true if s prefers h to hh, otherwise returns false
    for (unsigned i = 0; i < sp.size(); i++){
    if (sp[s][i] == h){
        return true;
    }
    else if (sp[s][i] == hh){
        return false;
    }
    }
    return false;
}

void gale_shapley(int n, std::vector<int> &h2s, std::vector<int> &s2h, intmatrix &hp, intmatrix &sp){
    std::queue<int> q; // queue with hospitals
    for (int i = 0; i < n; i++){
        q.emplace(i);
    }

    int s, h, hh;
    std::vector<int> last_prop(n, -1); // last_prop[h] is the last index in hp[h] that was proposed to by h
    while (q.size()){
        h = q.front();
        q.pop();

        s = hp[h][last_prop[h] + 1]; // selects the highest priority student that was not proposed to by h
        last_prop[h]++;

        if (s2h[s] == -1){
            s2h[s] = h;
            h2s[h] = s;
        }
        else{
            hh = s2h[s];
            if (prefers(s, h, hh, sp)){ // if s is matched with hh but prefers h
                h2s[h] = s;
                s2h[s] = h;
                h2s[hh] = -1;
                q.emplace(hh);
            }
            else{ // s rejects h, so we put it again on the queue
                q.emplace(h);
            }
        }
    }
}