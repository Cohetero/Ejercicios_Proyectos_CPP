/*
Escribir un programa que lea las dimensiones de una matriz, lea y visualice la matriz y a continuacion
enecuentre el mayor y menor elementos de la matriz y sus posiciones
*/

#include <iostream>
#include <vector>
#include <string>

struct Posicion
{
    int rows;
    int columns;
};

std::vector<std::vector<int>> llenarMatriz()
{
    int rows, columns;
    do
    {
        std::cout << "Numero de Filas: ";
        std::cin >> rows;
        std::cout << "Numero de Columnas: ";
        std::cin >> columns;
    } while (rows <= 0 || columns <= 0);

    std::vector<std::vector<int>> matriz(rows, std::vector<int>(columns));

    std::cout << "\nInserte los valores para llenar la matriz\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << "M[" << i + 1 << "][" << j + 1 << "] = ";
            std::cin >> matriz[i][j];
        }
    }

    return matriz;
}

void printMatriz(const std::vector<std::vector<int>> &matriz)
{
    std::cout << "\nMatriz ingresada:\n";
    for (const auto &fila : matriz)
    {
        for (int val : fila)
            std::cout << val << "\t";
        std::cout << std::endl;
    }
}

void buscarMayorMenorElemento(const std::vector<std::vector<int>> &matriz)
{
    int menor = matriz[0][0];
    int mayor = matriz[0][0];
    std::vector<Posicion> posicion_menor;
    std::vector<Posicion> posicion_mayor;

    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz[0].size(); j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                posicion_menor = {{i, j}}; // reiniciar
            }
            else if (matriz[i][j] == menor)
                posicion_menor.push_back({i, j});

            if (matriz[i][j] > mayor)
            {
                mayor = matriz[i][j];
                posicion_mayor = {{i, j}}; // reiniciar
            }
            else if (matriz[i][j] == mayor)
                posicion_menor.push_back({i, j});
        }
    }

    std::cout << "El numero menor es: " << menor << ", en las posiciones:\n";
    for (const auto &pos : posicion_menor)
        std::cout << " M[" << pos.rows + 1 << "][" << pos.columns + 1 << "]\n";

    std::cout << "El numero mayor es: " << mayor << ", en las posicones:\n";
    for (const auto &pos : posicion_mayor)
        std::cout << " M[" << pos.rows + 1 << "][" << pos.columns + 1 << "]\n";
}

int main()
{
    std::vector<std::vector<int>> matriz = llenarMatriz();
    printMatriz(matriz);
    buscarMayorMenorElemento(matriz);
    return 0;
}
