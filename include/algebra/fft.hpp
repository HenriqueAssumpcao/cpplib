#pragma once

#ifndef FFT
#define FFT

#include <complex>
#include "common.hpp"

typedef std::complex<double> cd;
const double pi = std::acos(-1);

std::vector<cd> fft(int n, std::vector<cd> &coef, bool inverse_fft);

#endif //FFT
