#include <iostream>
#include "Fecha.h"

Fecha::Fecha() : dia(1), mes(1), anio(2000) {}

int Fecha::diasDelMes(int m, int a) const
{
    switch (m)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return esBisiesto(a) ? 29 : 28;
    default:
        return 31;
    }
}

bool Fecha::esBisiesto(int a) const
{
    return (a % 400 == 0) || (a % 4 == 0 && a % 100 != 0);
}

void Fecha::normalizar()
{
    int maxDias;
    if (anio < 1)
        anio = 1;
    if (mes < 1)
        mes = 1;
    else if (mes > 12)
        mes = 12;

    maxDias = diasDelMes(mes, anio);
    if (dia < 1)
        dia = 1;
    else if (dia > maxDias)
        dia = maxDias;
}

int Fecha::getDay() const
{
    return dia;
}

int Fecha::getMonth() const
{
    return mes;
}

int Fecha::getYear() const
{
    return anio;
}

void Fecha::reiniciar(int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::adelantar(int d, int m, int a)
{
    anio += a;
    mes += m;
    while (mes > 12)
    {
        mes -= 12;
        anio++;
    }

    dia += d;
    while (dia > diasDelMes(mes, anio))
    {
        dia -= diasDelMes(mes, anio);
        mes++;
        if (mes > 12)
        {
            mes = 1;
            anio++;
        }
    }

    normalizar();
}

void Fecha::imprimir() const
{
    std::cout << (dia < 10 ? "0" : "") << dia << "/"
              << (mes < 10 ? "0" : "") << mes << "/"
              << anio << std::endl;
}