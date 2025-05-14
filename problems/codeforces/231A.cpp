#include <iostream>


int solve(int &n){
    int pcount = 0,count,aux;

    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < 3; j++){
            std::cin >> aux;
            count += aux;
        }
        if(count >= 2){
            pcount++;
        }
    }

    return pcount;
}


int main(){

    int n;
    std::cin>>n;
    std::cout << solve(n) << std::endl;

    return 0;
}