#include <iostream>
#include <iomanip> // Para setw y setfill
#include "Hora.h"

Hora::Hora(int h, int m, int s)
{
    hora = h;
    minutos = m;
    segundos = s;
    h_original = hora;
    m_original = minutos;
    s_original = segundos;
}

void Hora::adelantar(int h, int m, int s)
{
    segundos += s;
    minutos += segundos / MIN_SEG_TOTAL; // acarreo de segundos por si supera los 60 seg
    segundos %= MIN_SEG_TOTAL;           // Se evita que se pase de los 60 seg

    minutos += m;
    hora += minutos / MIN_SEG_TOTAL; // acarreo de minutos por si supera los 60 min
    minutos %= MIN_SEG_TOTAL;

    hora += h;
    hora %= HORAS_TOTAL;
}

void Hora::reiniciar()
{
    hora = h_original;
    minutos = m_original;
    segundos = s_original;
}

void Hora::imprimir24() const
{
    // Es para que le de formato en la salida a la hora (05:08:06)
    std::cout << std::setfill('0');
    std::cout << "Hora (24h): "
              << std::setw(2) << hora << ":"
              << std::setw(2) << minutos << ":"
              << std::setw(2) << segundos << "\n";
}

void Hora::imprimir12() const
{
    std::cout << std::setfill('0');
    int h12 = hora % 12;
    if (h12 == 0)
        h12 = 12;
    std::string periodo = (hora < 12) ? "AM" : "PM";

    std::cout << "Hora (12h): "
              << std::setw(2) << h12 << ":"
              << std::setw(2) << minutos << ":"
              << std::setw(2) << segundos << " "
              << periodo << "\n";
}