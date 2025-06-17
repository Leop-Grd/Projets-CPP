#ifndef COMPLEX
#define COMPLEX

#include <iostream>

class Complex 
{
    public :
    Complex (double re);
    Complex(double re, double im);
    virtual ~Complex();
    
    double Module() const;
    operator double() const;
    Complex operator + (Complex &nbr_complex);
    std::ostream& printOn(std::ostream& os) const;

    private : 
    double m_re;
    double m_im;
};

#endif