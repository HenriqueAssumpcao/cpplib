#pragma once

#ifndef COMMON
#define COMMON

#include <vector>
#include <climits>
#include <list>

#define ll long long
#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef std::vector<std::vector<bool>> bmatrix;
typedef std::vector<std::vector<int>> intmatrix;
typedef std::vector<std::vector<ll>> llmatrix;
typedef std::vector<std::vector<float>> fmatrix;
typedef std::vector<std::vector<double>> dmatrix;

typedef std::vector<std::list<unsigned>> graph; // type of a weightless graph
typedef std::vector<std::list<std::pair<unsigned,ll>>> wgraph; // type of a weighted graph



#endif // COMMON

