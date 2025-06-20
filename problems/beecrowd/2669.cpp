#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

const static long double pi = acos(-1);
typedef complex<double> cd;

vector<cd> fft(int n, vector<cd> &coef, bool inverse_fft){
    if(n == 1){
        return coef;
    }

    vector<cd> even_coeff(n/2),odd_coeff(n/2);
    for(int i = 0;i < n/2; i++){
        even_coeff[i] = coef[2*i];
        odd_coeff[i] = coef[2*i+1];
    }

    vector<cd> even_fft = fft(n/2,even_coeff,inverse_fft);
    vector<cd> odd_fft = fft(n/2,odd_coeff,inverse_fft);

    double ang = (2*pi)/n;
    if(inverse_fft){
        ang *= -1;
    }
    cd w(1),wn(cos(ang),sin(ang));
    
    vector<cd> ret(n);
    for(int i = 0; i < n/2; i++){
        ret[i] = even_fft[i] + w * odd_fft[i];
        ret[i+(n/2)] = even_fft[i] - w * odd_fft[i];
        if(inverse_fft){
            ret[i] /= 2;
            ret[i+(n/2)] /= 2;
        }
        w *= wn;
    }

    return ret;
}

vector<cd> copy_and_pad(int n, vector<int> &a){
    vector<cd> ac(n);
    for(int i = 0; i < a.size(); i++){
        ac[i] = a[i];
    }
    for(int i = a.size(); i < n; i++){
        ac[i] = 0;
    }

    return ac;
}

vector<int> convolution(vector<int> &a, vector<int> &b){
    int n = 1;
    while(n < a.size() + b.size()){
        n <<= 1;
    }
    vector<cd> fta = copy_and_pad(n,a),ftb = copy_and_pad(n,b);

    fta = fft(n,fta,false);
    ftb = fft(n,ftb,false);
    for(int i = 0; i < n; i++){
        fta[i] *= ftb[i];
    }
    fta = fft(n,fta,true);

    vector<int> ret(n);
    for(int i = 0; i < n; i++){
        ret[i] = round(fta[i].real());
    }

    return ret;

}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> weight(n),prefix(n+1);
    prefix[0] = 0;

    for(int i = 0; i < n; i++){
        weight[i] = s[i] - 96;
        prefix[i+1] = weight[i] + prefix[i];
    }
    
    int deg = prefix[n]+1;
    vector<int> a(deg),b(deg);

    for(int p : prefix){
        a[p] = 1;
        b[prefix[n]-p] = 1;
    }

    vector<int> res = convolution(a,b);

    int ret = 0;
    vector<bool> seen(deg,0);
    for(int i = deg; i < res.size(); i++){
        if(res[i] > 0){
            int curr = i - prefix[n];
            if(curr > 0 && !seen[curr]){
                seen[curr] = 1;
                ret++;
            }
        }
    }

    cout << ret << endl;


    return 0;
}
