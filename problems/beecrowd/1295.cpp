#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define DINF DBL_MAX/2
typedef long long ll;
typedef pair<double,double> pt;

bool compare_xcoord(const pt &p, const pt &q){
    return p.first < q.first;
}

bool compare_ycoord(const pt &p, const pt &q){
    return p.second < q.second;
}

double squared_dist(pt &p, pt &q){
    double diff1 = p.first - q.first, diff2 = p.second-q.second;
    
    return (diff1*diff1) + (diff2*diff2);
}

double sol_dc(int l, int r, vector<pt> &pts_sorted_x,vector<pt> &pts_sorted_y){
    if(l == r){
        return DINF;
    }
    else if(r == l+1){
        return squared_dist(pts_sorted_x[l],pts_sorted_x[r]);
    }
    int middle = l + (r-l+1)/2;
    pt middle_pt = pts_sorted_x[middle];

    vector<pt> pts_sorted_y_left,pts_sorted_y_right;
    for(int i = 0; i < pts_sorted_y.size(); i++){
        if(pts_sorted_y[i].first <= middle_pt.first){
            pts_sorted_y_left.push_back(pts_sorted_y[i]);
        }
        else{
            pts_sorted_y_right.push_back(pts_sorted_y[i]);
        }
    }

    double d_l = sol_dc(l,middle,pts_sorted_x,pts_sorted_y_left);
    double d_r = sol_dc(middle+1,r,pts_sorted_x,pts_sorted_y_right);
    double d = min(d_l,d_r);

    vector<pt> middle_strip; 
    for(int i = 0; i < pts_sorted_y.size(); i++){
        if(abs(pts_sorted_y[i].first - middle_pt.first) <= d){
            middle_strip.push_back(pts_sorted_y[i]);
        }
    }

    int ssize = middle_strip.size();
    double ret = d;

    for(int i = 0; i < ssize; i++){
        for(int j = i + 1; j < min(i+8,ssize); j++){
            ret = min(ret,squared_dist(middle_strip[i],middle_strip[j]));
        }
    }

    return ret;

}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    double t = 1e8;
    cout << fixed;
    cout << setprecision(4);

    while(cin >> n){
        if(n == 0){
            break;
        }
        vector<pt> pts(n);
        for(int i = 0; i < n; i++){
            cin >> pts[i].first >> pts[i].second;
        }

        vector<pt> pts_sorted_y = pts;

        sort(pts.begin(),pts.end(),compare_xcoord); // sorts by x coordinate
        sort(pts_sorted_y.begin(),pts_sorted_y.end(),compare_ycoord); // sorts by y coordinate

        double min_dist_sqrd = sol_dc(0,n-1,pts,pts_sorted_y);
        if(n == 1 || min_dist_sqrd >= t){
            cout << "INFINITY" << endl;
        }
        else{
            cout << sqrt(min_dist_sqrd) << endl;
        }

        
    }

    return 0;
}
