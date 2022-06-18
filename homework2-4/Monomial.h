#pragma once
#include<iostream>
#include <string>


class Monomial
{
private:
    int coe;//系数
    int deg;//次数
    
public:
    std::string mono;
    Monomial();
    Monomial(int _c, int _d);
    Monomial operator+( const Monomial &x) const;
    Monomial operator-(const Monomial &x) const;
    Monomial operator*(const Monomial &x) const;
    Monomial operator/( const Monomial &x) const;
    int definite_integral(const int a, const int b) const;
    Monomial derive() const;
    int get_val(int x) const;
    friend std::istream& operator>>(std::istream& in,Monomial& model);
    friend std::ostream& operator<<(std::ostream& out, Monomial& model);
    
};

 