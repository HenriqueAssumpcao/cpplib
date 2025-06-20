#pragma once

#ifndef RATIONAL
#define RATIONAL

#include "common.hpp"
#include <cassert>
#include <numeric>

struct rational{
    ll p,q;
    rational(ll _p = 0, ll _q = 1):p(_p),q(_q){
        assert(q != 0);
        if(q < 0){
            p *= -1;
            q *= -1;
        }
        ll d = std::gcd(abs(p),q);
        p /= d;
        q /= d;
    };

    friend bool operator<(const rational &x1, const rational &x2){
        return (x1.p*x2.q) < (x2.p*x1.q);
    }
    friend rational operator+(const rational &x1, const rational &x2){
        return rational(x1.p*x2.q + x2.p*x1.q,x1.q*x2.q);
    }
    friend rational operator-(const rational &x1, const rational &x2){
        return rational(x1.p*x2.q - x2.p*x1.q,x1.q*x2.q);
    }
    friend rational operator*(const rational &x1, const rational &x2){
        return rational(x1.p*x2.p,x1.q*x2.q);
    }
    friend rational operator/(const rational &x1, const rational &x2){
        return rational(x1.p*x2.q,x1.q*x2.p);
    }
    friend std::ostream& operator<<(std::ostream &out, rational x){
        out << x.p << "/" << x.q;
        return out;
    }
};


#endif //RATIONAL