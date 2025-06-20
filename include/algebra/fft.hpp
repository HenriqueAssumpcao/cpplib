#pragma once

#ifndef FFT
#define FFT

#include <complex>
#include "common.hpp"

typedef std::complex<double> cd;

std::vector<cd> fft(int n, std::vector<cd> &coef, bool inverse_fft);
std::vector<ll> convolution(std::vector<ll> &a, std::vector<ll> &b);

#endif //FFT
