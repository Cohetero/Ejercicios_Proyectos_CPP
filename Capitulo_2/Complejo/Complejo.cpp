#include <iostream>
#include <iomanip>
#include <cmath>

#include "Complejo.h"

Complejo::Complejo(double r, double i)
{
    real = r;
    imaginario = i;
}

void Complejo::imprimir() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << real << (imaginario >= 0 ? " + " : " - ")
              << std::abs(imaginario) << "i\n";
}

Complejo Complejo::operator+(const Complejo &otro_complejo) const
{
    return Complejo(real + otro_complejo.real, imaginario + otro_complejo.imaginario);
}

Complejo Complejo::operator-(const Complejo &otro_complejo) const
{
    return Complejo(real - otro_complejo.real, imaginario - otro_complejo.imaginario);
}

Complejo Complejo::operator*(const Complejo &otro_complejo) const
{
    double r = (real * otro_complejo.real) - (imaginario * otro_complejo.imaginario);
    double i = (real * otro_complejo.imaginario) + (imaginario * otro_complejo.real);
    return Complejo(r, i);
}

Complejo Complejo::operator*(double escalar) const
{
    return Complejo(real * escalar, imaginario * escalar);
}

Complejo operator*(double escalar, const Complejo &c)
{
    return Complejo(c.real * escalar, c.imaginario * escalar);
}

Complejo Complejo::operator~() const
{
    return Complejo(real, -imaginario);
}
