#include <iostream>

using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex():re(0), im(0){}        //default constructor
    Complex(double re, double im): re(re), im(im){}
    Complex(const Complex& c){      //copy constructor
        this->re = c.re;
        this->im = c.im;
    }

    void show();
    //a non-static member function with a argument
    Complex operator+(const Complex&);
    //a non-member function with 2 arguments
    friend Complex operator*(const Complex&, const Complex&);

    //a non-static member function with 0 argument
    void operator-();
    //a non-member function with 1 argument
    friend Complex operator~(const Complex&);
};

void Complex::show()
{
    if(im > 0)
        cout << this->re << "+" << this->im << 'i' << endl;
    else if(im < 0)
        cout << this->re << "-" << -this->im << 'i' << endl;
    else
        cout << this->re << endl;
}

Complex Complex::operator+(const Complex& c)
{
    Complex ans;
    ans.re = this->re + c.re;
    ans.im = this->im + c.im;
    return ans;
}

Complex operator*(const Complex& a, const Complex& b)
{
    Complex c;
    c.re = a.re*b.re - a.im*b.im;
    c.im = a.re*b.im + a.im*b.re;
    return c;
}

void Complex::operator-()
{
    this->re = -this->re;
    this->im = -this->im;
}

Complex operator~(const Complex& c)
{
    return Complex(c.re, -c.im);
}

int main()
{
    Complex a(10, 20);
    Complex b(30, 40);
    -a;
    Complex c = ~a;
    c.show();
}
