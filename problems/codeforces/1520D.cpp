#include <iostream>
#include <vector>
#include <map>


#define forloop(i,start,end) for(ll i = start; i < end; i++)
#define ll long long

ll solve(ll &n,std::vector<ll> &arr, std::map<ll,ll>&m){

    forloop(i,0,n){
        m[arr[i] - (i+1)]++;
    }
    ll count = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second > 1){
            count += ((it->second)*(it->second-1))/2;
        }
    }

    return count;
}




int main(){
    ll t,n;
    std::cin >> t;

    std::map<ll,ll> m;

    forloop(i,0,t){
        std::cin >> n;
        std::vector<ll> arr(n);
        forloop(j,0,n){
            std::cin >> arr[j];
        }
        m.clear();
        std::cout<<solve(n,arr,m)<<std::endl;
    }


    return 0;
}