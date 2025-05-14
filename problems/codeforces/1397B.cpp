#include <iostream>
#include <vector>


int solve(std::vector<int> &arr){
    int evens_inc = 0, odds_inc = 0;

    for(int i = 0; i < arr.size(); i++){
        if(i % 2 != arr[i] % 2){
            if(arr[i] % 2 == 0){
                evens_inc++;
            }
            else{
                odds_inc++;
            }
        }
    }

    if(evens_inc == odds_inc){
        return evens_inc;
    }
    else{
        return -1;
    }
}



int main(int argc, char *argv[]){

    int t,n,temp,sol;

    std::cin >> t;
    
    for (int i = 0; i < t; i++){
        std::cin >> n;
        std::vector<int> arr(n);
        for(int j = 0; j < n; j++){
            std::cin >> temp;
            arr[j] = temp;
        }

        sol = solve(arr);
        std::cout << sol << std::endl;
    }

    return 0;
}