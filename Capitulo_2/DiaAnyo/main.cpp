/*
    Definir una clases DiaAnyoi con los atributos mes y día, los métodos igual() y visualizar().
    El mes se registra como un valor entero (1, Enero, 2, Febrero,etc.). El día del mese se registra
    en otra variable entera día. Escribir un programa que compruebe si una fecha es su cumpleaños
*/

#include <iostream>
#include "DiaAnyo.h"

int main()
{
    DiaAnyo *hoy;
    DiaAnyo *cumpleanyos;
    int dia, mes;

    std::cout << "Introduzca fecha de hoy, dia: ";
    std::cin >> dia;
    std::cout << "Introduzca el numero de mes: ";
    std::cin >> mes;

    hoy = new DiaAnyo(dia, mes);

    std::cout << "Introduzca su fecha de nacimiento, dia: ";
    std::cin >> dia;
    std::cout << "Introduzca el numero de mes: ";
    std::cin >> mes;

    cumpleanyos = new DiaAnyo(dia, mes);

    std::cout << "La fecha de hoy es: ";
    hoy->visualizar();

    std::cout << "Su fecha de nacimiento es: ";
    cumpleanyos->visualizar();

    if (hoy->igual(*cumpleanyos))
        std::cout << "¡¡¡Feliz cumpleaños!!!\n";
    else
        std::cout << "¡¡¡Feliz no cumpleaños!!!\n";
    return 0;
}