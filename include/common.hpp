#pragma once

#ifndef COMMON
#define COMMON

#include <vector>
#include <limits>

#define ll long long
#define inf std::numeric_limits<ll>::max()

#define bmatrix std::vector<std::vector<bool>>
#define intmatrix std::vector<std::vector<int>>
#define llmatrix std::vector<std::vector<ll>>
#define fmatrix std::vector<std::vector<float>>
#define dmatrix std::vector<std::vector<double>>

#define graph std::vector<std::list<unsigned>> // type of a weightless graph
#define wgraph std::vector<std::list<std::pair<unsigned,ll>>> // type of a weighted graph



#endif // COMMON

