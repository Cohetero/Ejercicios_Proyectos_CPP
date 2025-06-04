/*
    1.- Implementar la clase Fecha con miembros dato para el mes, dia y año. Cada objeto de esta clase representa una fecha,
    que almacena el dia, mes y año como enteros. Se debe incluir un costructor por defecto, funciones de acceso, la funcion
    reiniciar (int d, int m, int a) para reiniciar la fecha de un objeto existente, la funcion adelantar (int d, int m, int a)
    para avanzar una fecha existente (dia d, mes m y año a) y la funcion imprimir(). Escribir una funcion auxiliar de utilidad
    normalizar() que asegure que los miembros dato esten en el rango correcto 1 <= año, 1 <= mes <= 12, dia <= dias (Mes),
    siendo dias (Mes) otra funcion que devuelve el numero de dias de cada mes.

    2.- Ampliar el programa de modo que pueda aceptar años bisiestos. NOTA: un año bisiesto si es divisible por 400, o si
    es divisible por 4 pero no por 100. Por ejemplo el año 1992 y 200 son años bisiestos y 1997 y 1900 no son bisiestos.
*/
#include <iostream>
#include "Fecha.h"

int main()
{
    Fecha f;

    std::cout << "Fecha por defecto: ";
    f.imprimir();

    f.reiniciar(31, 12, 1999);
    std::cout << "Fecha reiniciada: ";
    f.imprimir();

    f.adelantar(1, 0, 0);
    std::cout << "Despues de adelantar 1 dia: ";
    f.imprimir();

    f.adelantar(0, 2, 0);
    std::cout << "Despues de adelantar 2 meses: ";
    f.imprimir();

    f.reiniciar(28, 2, 2024); // Año bisiesto
    std::cout << "Fecha bisiesto: ";
    f.imprimir();

    f.adelantar(1, 0, 0); // Debe quedar 29/02/2024
    std::cout << "Despues de adelantar 1 dia (bisiesto): ";
    f.imprimir();

    return 0;
}
