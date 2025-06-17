#include "algebra/fft.hpp"

// fast fourier transform
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