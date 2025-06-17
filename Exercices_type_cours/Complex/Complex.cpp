#include <cmath>
#include "Complex.hpp"

using namespace std;

Complex::Complex(double re, double im) : m_re(re), m_im(im)
{
}

Complex::Complex(double re) : m_re(re), m_im(0)
{
}

Complex::~Complex()
{
}

double Complex::Module() const
{
    return sqrt(m_re*m_re + m_im*m_im);
}

Complex::operator double() const
{
    return Module();
}

ostream& Complex::printOn(ostream& os) const
{
    return os << m_re << " +i" << m_im ;
}

Complex Complex::operator +(Complex &nbr_complex)
{
    return Complex(m_re+nbr_complex.m_re,m_im+nbr_complex.m_im); //Complex(...) pour convertir en type Complex m_re et m_im qui sont de type double
}