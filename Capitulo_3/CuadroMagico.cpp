/*
    Escribir un programa que visualice un cuadro magico de orden impar n comprendiendo entre 3 y 11;
    el usuario debe elegir el valor de n. Un cuadro magico se compone de numeros enteros comprendidos
    entre 1 y n. La suma de los numeros que figuran en cada fila, columna y diagonal son iguales.
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> cuadroMagico(int n)
{
    std::vector<std::vector<int>> matriz(n, std::vector<int>(n, 0));
    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n)
    {
        matriz[i][j] = num++;

        int nueva_i = (i - 1 + n) % n;
        int nueva_j = (j + 1) % n;

        if (matriz[nueva_i][nueva_j] != 0)
            i = (i + 1) % n;
        else
        {
            i = nueva_i;
            j = nueva_j;
        }
    }

    return matriz;
}

int main()
{
    int n;
    std::cout << "Introducee un numero impar entre 3 y 11: ";
    std::cin >> n;

    if (n < 3 || n > 11 || n % 2 == 0)
    {
        std::cout << "Numero invalido. Debe ser impar entre 3 y 11";
        return 1;
    }

    auto matriz = cuadroMagico(n);

    std::cout << "\nCuadro Magico de orden " << n << ":\n";
    for (const auto &fila : matriz)
    {
        for (int val : fila)
            std::cout << val << "\t";
        std::cout << "\n";
    }

    int suma_magica = n * (n * n + 1) / 2;
    std::cout << "\nLa suma magica es: " << suma_magica << "\n";

    return 0;
}