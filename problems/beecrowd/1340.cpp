#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    
    int n,c,x,stest,qtest,pqtest;
    while(cin >> n){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        
        stest = 1,qtest = 1,pqtest = 1;
        for(int i = 0; i < n; i++){
            cin >> c >> x;
            if(c == 1){
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else if(c == 2){
                if(s.top() != x){
                    stest = 0;
                }
                if(q.front() != x){
                    qtest = 0;
                }
                if(pq.top() != x){
                    pqtest = 0;
                }
                s.pop();
                q.pop();
                pq.pop();
            }
        }
        if(stest + qtest + pqtest > 1){
            cout << "not sure" << endl;
        }
        else if(stest + qtest + pqtest == 0){
            cout << "impossible" << endl;
        }
        else{
            if(stest == 1){
                cout << "stack" << endl;
            }
            else if(qtest == 1){
                cout << "queue" << endl;
            }
            else{
                cout << "priority queue" << endl;
            }
        }
    }

    return 0;
}
