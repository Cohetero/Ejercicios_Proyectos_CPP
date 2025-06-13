/*
    Escribir un programa que permita visualizar el triangulo de Pascal:

                      1
                     1  1
                   1  2  1
                 1   3  3  1
               1   4   6  4  1
             1   5  10  10  5  1
            1  6  15  20  15  6  1

    En el tringulo de Pascal cada numero es la suma de los dos numeros situados encima de el.
    Este problema se debe resolver utilizando un array de una sola dimension
*/

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int n;
    std::cout << "¿Cuántas filas del Triángulo de Pascal quieres imprimir? ";
    std::cin >> n;

    int anterior[n]; // Arreglo para guardar la fila anterior
    int actual[n];   // Arreglo para guardar la fila actual

    anterior[0] = 1; // Primera fila: solo un 1
    std::cout << "      " << anterior[0] << std::endl;

    for (int i = 1; i < n; i++)
    {
        actual[0] = 1; // Primer número de la fila siempre es 1

        // Espacios para centrar
        for (int s = 0; s < n - i - 1; s++)
            std::cout << "  ";

        std::cout << actual[0] << "   "; // Imprimir el primer 1

        // Calcular los del medio
        for (int j = 1; j < i; j++)
        {
            actual[j] = anterior[j - 1] + anterior[j];
            std::cout << actual[j] << "   ";
        }

        actual[i] = 1; // Último número también es 1
        std::cout << actual[i] << std::endl;

        // Copiar actual en anterior para la siguiente iteración
        for (int j = 0; j <= i; j++)
        {
            anterior[j] = actual[j];
        }
    }

    return 0;
}