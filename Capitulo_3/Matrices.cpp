#include <iostream>
#include <algorithm> // Para min
#include <vector>

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void leerFilasColumnas(int &rows, int &columns)
{
    std::cout << "Numero de Filas: ";
    std::cin >> rows;
    std::cout << "Numero de Columnas: ";
    std::cin >> columns;
}

std::vector<std::vector<int>> llenarMatrix()
{
    int rows, columns;
    leerFilasColumnas(rows, columns);

    std::vector<std::vector<int>> matriz(rows, std::vector<int>(columns)); // Reserva espacio, osea que define el tamaño de la matriz, ejemplo matriz[3][3]
    std::cout << "\nInserte los valores para llenar la matriz\n";
    for (int i = 0; i < rows; i++)
    {
        std::cout << "Fila " << i + 1 << ": ";
        for (int j = 0; j < columns; j++)
            std::cin >> matriz[i][j];
    }

    return matriz;
}

void printMatrix(const std::vector<std::vector<int>> &matriz)
{
    for (const auto &fila : matriz)
    {
        for (int val : fila)
            std::cout << val << " ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> matrizTranspuesta(const std::vector<std::vector<int>> &matriz)
{
    int rows = matriz.size();
    int columns = matriz[0].size();
    std::vector<std::vector<int>> transpuesta(columns, std::vector<int>(rows));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            transpuesta[j][i] = matriz[i][j];

    return transpuesta;
}

void sumaMatrixNoDiagonal(const std::vector<std::vector<int>> &matriz)
{
    int suma = 0, diagonal = 0;
    int rows = matriz.size();
    int columns = matriz[0].size();

    for (const auto &fila : matriz)
        for (int val : fila)
            suma += val;

    // Suma Diagonal
    for (int i = 0; i < std::min(rows, columns); i++) // MIN para sacar la columna o fila mas pequeña
        diagonal += matriz[i][i];

    std::cout << "\nSuma Total: " << suma;
    std::cout << "\nSuma Diagonal: " << diagonal;
    std::cout << "\nSuma total - Suma Diagonal: " << suma - diagonal << "\n";
}

void intercambiarFilas(std::vector<std::vector<int>> &matriz)
{
    int fila_1, fila_2;
    int rows = matriz.size();

    std::cout << "Ingrese el numero de fila a intercambiar: (0 a " << rows - 1 << "): ";
    std::cin >> fila_1;
    std::cout << "Ingrese otro numero de fila a intercambiar: ";
    std::cin >> fila_2;

    if (fila_1 < 0 || fila_1 >= rows || fila_2 < 0 || fila_2 >= rows)
    {
        std::cout << "Indice de fila invalido\n";
        return;
    }

    /*for (int i = 0; i < columns; i++)
    {
        temp = matriz[fila_1][i];
        matriz[fila_1][i] = matriz[fila_2][i];
        matriz[fila_2][i] = temp;
    }*/

    std::swap(matriz[fila_1], matriz[fila_2]); // Intercambio el contenido de un contenedor por otro vector del mismo tipo
}

int main()
{
    char opcion_matriz;
    int opcion = 6;
    std::vector<std::vector<int>> A, B;

    do
    {
        limpiar_pantalla();
        std::cout << "=== Calculadora de Matrices ===\n";
        std::cout << "1. Llenar Matrices\n";
        std::cout << "2. Mostrar Matrices\n";
        std::cout << "3. Transposicion\n";
        std::cout << "4. Suma de todos los elementos menos de la diagonal principal\n";
        std::cout << "5. Intercambiar Filas de una Matriz\n";
        std::cout << "6. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            std::cout << "\n=== Matriz A ===\n";
            A = llenarMatrix();
            std::cout << "\n=== Matriz B ===\n";
            B = llenarMatrix();
            break;
        case 2:
            std::cout << "Matriz A:\n";
            printMatrix(A);
            std::cout << "Matriz B:\n";
            printMatrix(B);
            break;
        case 3:
            std::cout << "Matriz A o B: ";
            std::cin >> opcion_matriz;

            if (opcion_matriz == 'A' || opcion_matriz == 'a')
            {
                // Forma normal
                std::cout << "Forma Normal de la Matriz A:\n";
                printMatrix(A);
                // Transposicion de matriz
                std::cout << "Transposicion de la Matriz A\n";
                auto C = matrizTranspuesta(A);
                printMatrix(C);
            }
            else
            {
                std::cout << "Forma Normal de la Matriz B:\n";
                printMatrix(B);
                std::cout << "Transposicion de la Matriz B\n";
                auto C = matrizTranspuesta(B);
                printMatrix(C);
            }
            break;
        case 4:
            // Suma de todos los elementos que no pertenecen a la diagonal principal
            std::cout << "Matriz A o B: ";
            std::cin >> opcion_matriz;

            if (opcion_matriz == 'A' || opcion_matriz == 'a')
                sumaMatrixNoDiagonal(A);
            else
                sumaMatrixNoDiagonal(B);
            break;
        case 5:
            std::cout << "Matriz A o B: ";
            std::cin >> opcion_matriz;

            if (opcion_matriz == 'A' || opcion_matriz == 'a')
            { // Forma normal
                std::cout << "\nAntes:\n";
                printMatrix(A);
                // Intercambio de Filas
                intercambiarFilas(A);
                std::cout << "Despues:\n";
                printMatrix(A);
            }
            else
            {
                std::cout << "\nAntes:\n";
                std::cout << "\nMatriz B\n";
                printMatrix(B);
                intercambiarFilas(B);
                std::cout << "Despues:\n";
                printMatrix(B);
            }
            break;
        case 6:
            std::cout << "Hasta Luego!!!";
            break;
        default:
            std::cout << "Opcion invalida\n";
            break;
        }

        std::cin.ignore(); // limpia el buffer
        std::cout << "\nPresiona Enter para continuar...";
        std::cin.get();
    } while (opcion != 6);

    return 0;
}
