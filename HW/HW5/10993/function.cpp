#include <iostream>
#include <stdio.h>
#include <string>
#include "function.h"
using namespace std;

Polynomial::Polynomial()
{
    for(int i = 0; i < 100; i++)
        coefficients[i] = 0;
    greatestPower = 0;
}

Polynomial::Polynomial(const int l, const int c[51])
{
    greatestPower = l;
    for(int i = 0; i <= l; i++){
        coefficients[i] = c[i];
    }
}

Polynomial Polynomial::add( const Polynomial p) const
{
    Polynomial ans;
    if(this->greatestPower > p.greatestPower){
        for(int i = 0; i <= p.greatestPower; i++)
            ans.coefficients[i] = this->coefficients[i] + p.coefficients[i];

        for(int i = p.greatestPower+1; i <= this->greatestPower; i++)
            ans.coefficients[i] = this->coefficients[i];

        ans.greatestPower = this->greatestPower;
    }
    else if(this->greatestPower < p.greatestPower){
        for(int i = 0; i <= this->greatestPower; i++){
            ans.coefficients[i] = this->coefficients[i] + p.coefficients[i];
        }
        for(int i = this->greatestPower+1; i <= p.greatestPower; i++){
            ans.coefficients[i] = p.coefficients[i];
        }
        ans.greatestPower = p.greatestPower;
    }
    else{
        ans.greatestPower = p.greatestPower;
        for(int i = 0; i <= p.greatestPower; i++)
            ans.coefficients[i] = this->coefficients[i] + p.coefficients[i];
    }

    return ans;
}

Polynomial Polynomial::subtract( const Polynomial p) const
{
    Polynomial ans;
    if(this->greatestPower > p.greatestPower){
        for(int i = 0; i <= p.greatestPower; i++){
            ans.coefficients[i] = this->coefficients[i] - p.coefficients[i];
        }
        for(int i = p.greatestPower+1; i <= this->greatestPower; i++){
            ans.coefficients[i] = this->coefficients[i];
        }
        ans.greatestPower = this->greatestPower;
    }
    else if(this->greatestPower < p.greatestPower){
        for(int i = 0; i <= this->greatestPower; i++){
            ans.coefficients[i] = this->coefficients[i] - p.coefficients[i];
        }
        for(int i = this->greatestPower+1; i <= p.greatestPower; i++){
            ans.coefficients[i] = -p.coefficients[i];
        }
        ans.greatestPower = p.greatestPower;
    }
    else{
        ans.greatestPower = p.greatestPower;
        for(int i = 0; i <= p.greatestPower; i++)
            ans.coefficients[i] = this->coefficients[i] - p.coefficients[i];
    }

    return ans;
}

Polynomial Polynomial::multiplication( const Polynomial p) const
{
    Polynomial ans;
    ans.greatestPower = this->greatestPower + p.greatestPower;
    for(int i = 0; i <= this->greatestPower; i++){
        for(int j = 0; j <= p.greatestPower; j++){
            ans.coefficients[i+j] += this->coefficients[i] * p.coefficients[j];
        }
    }
    return ans;
}

void Polynomial::output() const
{
    for(int i = greatestPower; i >= 0; i--){
        cout << coefficients[i];
        if(i != 0) cout << ' ';
    }
}
