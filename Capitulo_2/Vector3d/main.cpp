/*
    Se desea realizar la clase Vector3d3d que permita manipular Vector3des de tres componentes
    (coordenadas x, y, z) de acuerdo a las siguientes normas:
        * Sólo posee un método constructor
        * Tiene una función miembro igual() que permite saber si dos Vector3des tienen sus
                componentes o coordenadas iguales
    Incluir la función normaMax que permita obtener la norma de unn Vector3d (NOTA: la norma de un
    Vector3d v =(x, y, z) es √(x^2 + y^2 + z^2))
*/

#include <iostream>
#include "Vector3d.h"

int main()
{
    int x, y, z;

    std::cout << "Ingresa los valores del primer Vector3d:\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "z: ";
    std::cin >> z;
    Vector3d a(x, y, z);

    std::cout << "\nIngresa los valores del segundo vector:\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "z: ";
    std::cin >> z;
    Vector3d b(x, y, z);

    std::cout << "\n¿Los vectores A y B son iguales? "
              << (a.esIgual(b) ? "Si" : "No") << std::endl;

    std::cout << "La norma del Vector3d A es: " << a.normaMax() << std::endl;

    return 0;
}