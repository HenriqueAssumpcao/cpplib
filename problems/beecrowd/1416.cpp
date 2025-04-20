#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

vector<pair<int,int>> subvec_withids(vector<int> &vec, vector<int> &ids){
    vector<pair<int,int>> ret;

    for(int id : ids){
        ret.push_back({vec[id],id});
    }

    return ret;
}

bool comparator (const pair<int,int> &l, const pair<int,int> &r){
    return l.first < r.first;
}

void update_bounds(int bigger, int smaller,int &lb, int &ub, vector<int> &fattempts, vector<int> &times, bool strict){
    if((fattempts[bigger] == fattempts[smaller]) || (times[bigger] == times[smaller]) || ((fattempts[bigger] > fattempts[smaller]) && (times[bigger] > times[smaller]))){
        lb = max(lb,1);
        ub = min(ub,IINF);
    }
    else{
        int temp;
        if((fattempts[bigger] > fattempts[smaller]) && (times[bigger] < times[smaller])){
            temp = ((times[smaller]-times[bigger])/(fattempts[bigger]-fattempts[smaller]));
            if(strict){
                temp++;
            }
            lb = max(lb,temp);
        }
        else if((fattempts[bigger] < fattempts[smaller]) && (times[bigger] > times[smaller])){
            temp = ((times[bigger]-times[smaller] - 1)/(fattempts[smaller]-fattempts[bigger]))+1;
            if(strict){
                temp--;
            }
            ub = min(ub,temp);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int t,p;
    int counter = 1;
    while(cin >> t >> p){
        if(t == 0){
            break;
        }

        vector<int> fattempts(t,0),times(t,0);
        vector<int> penalties(t,0);
        vector<vector<int>> solved(p+1);

        string temp;
        int num_solved;
        for(int i = 0; i < t; i++){
            num_solved = 0;
            for(int j = 0; j < p; j++){
                cin >> temp;
                int bar_pos = temp.find('/',0);
                string s = temp.substr(bar_pos+1,temp.size());
                if(s != "-"){
                    int a = stoi(temp.substr(0,bar_pos)), is = stoi(s);
                    fattempts[i] += (a-1);
                    times[i] += is;
                    penalties[i] += is + 20*(a-1);
                    num_solved++;
                }
            }
            solved[num_solved].push_back(i);
        }

        int lb = 1,ub = IINF;
        bool found_eq = false;

        for(int i = solved.size()-1; i > 0; i--){
            vector<int> ids = solved[i];
            if(ids.size() >= 2){
                vector<pair<int,int>> aux = subvec_withids(penalties,ids);
                sort(aux.begin(),aux.end());
                int i = aux.size()-1;
                while(i > 0){
                    int bigger = aux[i].second;
                    int smaller = aux[i-1].second;
                    bool strict = aux[i].first > aux[i-1].first;
                    if(!strict && (fattempts[bigger] != 0 || fattempts[smaller] != 0)){
                        lb = 20;
                        ub = 20;
                        found_eq = true;
                        break;
                    }
                    else{
                        update_bounds(bigger,smaller,lb,ub,fattempts,times,strict);
                    }
                    i--;
                }
                if(found_eq){
                    break;
                }
            }
        }
        cout << lb << " ";
        if(ub == IINF){
            cout << "*";
        }
        else{
            cout << ub;
        }
        cout << endl;
        counter++;
    }
    return 0;
}
