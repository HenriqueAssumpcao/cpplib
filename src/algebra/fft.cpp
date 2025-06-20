#include "algebra/fft.hpp"
// fast fourier transform (this implementation uses copies, its significantly slower than the in-place iterative solution for large n)
const static long double pi = acosl(-1);
std::vector<cd> fft(int n, std::vector<cd> &coef, bool inverse_fft){
    if(n == 1){
        return coef;
    }

    std::vector<cd> even_coeff(n/2),odd_coeff(n/2);
    for(int i = 0;i < n/2; i++){
        even_coeff[i] = coef[2*i];
        odd_coeff[i] = coef[2*i+1];
    }

    std::vector<cd> even_fft = fft(n/2,even_coeff,inverse_fft);
    std::vector<cd> odd_fft = fft(n/2,odd_coeff,inverse_fft);

    double ang = (2*pi)/n;
    if(inverse_fft){
        ang *= -1;
    }
    cd w(1),wn(std::cos(ang),std::sin(ang));
    
    std::vector<cd> ret(n);
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

// creates a copy of a with size n, padding with zero
std::vector<cd> copy_and_pad(int n, std::vector<ll> &a){
    std::vector<cd> ac(n);
    for(unsigned int i = 0; i < a.size(); i++){
        ac[i] = a[i];
    }
    for(int i = a.size(); i < n; i++){
        ac[i] = 0;
    }

    return ac;
}

// computes the convolution of two vector a and b
std::vector<ll> convolution(std::vector<ll> &a, std::vector<ll> &b){
    int n = 1;
    while(n < (int)(a.size() + b.size())){
        n <<= 1;
    }
    std::vector<cd> fta = copy_and_pad(n,a),ftb = copy_and_pad(n,b);

    fta = fft(n,fta,false);
    ftb = fft(n,ftb,false);
    for(int i = 0; i < n; i++){
        fta[i] *= ftb[i];
    }
    fta = fft(n,fta,true);

    std::vector<ll> ret(n);
    for(int i = 0; i < n; i++){
        ret[i] = round(fta[i].real());
    }

    return ret;

}

