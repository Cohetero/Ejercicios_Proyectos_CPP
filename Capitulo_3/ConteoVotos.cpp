/*
    Los resultados de los ultimas elecciones a acalde en el pueblo x han sido los siguientes:

    Distro      Candidato       Candidato       Candidato       Candidato
                    A               B               C               D
    1              194             48              206             45
    2              180             20              320             16
    3              221             90              140             20
    4              432             50              821             14
    5              820             61              946             18

    Escribir un programa que haga las siguientes tareas:

        a) Imprimir la tabla anterior con cabeceras incluidas
        b) Calcular e imprimir el numero total de votos recibidos por cada candidato y el porcentaje
           del total de votos emitidos. Asimismo, visualizar el candidato mas votado.
        c) Si algun candidato recibe mas del 50 por 100 de los datos, el progrmama imprimira un mensaje
           declarandole ganador.
        d) Si ningun candidato recibe mas del 50 por 100 de los datos, el programa debe imprimir el nombre
           de los dos candidatos mas votados, que seran los que pasen a la segunda ronda de las elecciones.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

int ASCII_LETRA = 65;
struct Candidatos
{
    char letra;
    int total_votos;
    double porcentaje;
};

std::vector<std::vector<int>> llenarMatriz()
{
    int rows, columns;
    do
    {
        std::cout << "Numero de Distros: ";
        std::cin >> rows;
        std::cout << "Numero de Candidatos: ";
        std::cin >> columns;
    } while (rows <= 0 || columns <= 0);

    std::vector<std::vector<int>> matriz(rows, std::vector<int>(columns));

    std::cout << "\nInserte los valores para llenar la matriz\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << "M[" << i + 1 << "][" << j + 1 << "] = ";
            while (!(std::cin >> matriz[i][j]))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Entrada inválida. Intenta de nuevo: ";
            }
        }
    }

    return matriz;
}

void imprimirTabla(const std::vector<std::vector<int>> &matriz)
{
    int rows = matriz.size() + 2;
    int columns = matriz[0].size() + 1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                    std::cout << "Distrito\t";
                else
                    std::cout << "Candidato\t";
            }
            else if (i == 1)
            {
                if (j == 0)
                    std::cout << " \t\t";
                else
                    std::cout << static_cast<char>(ASCII_LETRA + j - 1) << "\t\t";
            }
            else if (i > 1)
            {
                if (j == 0)
                    std::cout << i - 1 << "\t\t";
                else
                    std::cout << matriz[i - 2][j - 1] << "\t\t";
            }
        }
        std::cout << std::endl;
    }
}

void calcularTotalVotos(const std::vector<std::vector<int>> &matriz)
{
    int total_votos = 0;
    int rows = matriz.size();
    int columns = matriz[0].size();
    std::vector<Candidatos> candidatos;
    Candidatos cand;

    for (int j = 0; j < columns; j++)
    {
        cand.letra = ASCII_LETRA + j;
        int votos = 0;
        for (int i = 0; i < rows; i++)
        {
            total_votos += matriz[i][j];
            votos += matriz[i][j];
        }
        cand.total_votos = votos;
        cand.porcentaje = 0;
        candidatos.push_back(cand);
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total de votos de las elecciones: " << total_votos << std::endl;
    for (auto &cad : candidatos)
    {
        cad.porcentaje = (static_cast<double>(cad.total_votos) / total_votos) * 100;
        std::cout << "Candidadto: " << cad.letra << std::endl
                  << "Total de Votos: " << cad.total_votos << std::endl
                  << "Porcentaje de los votos totales: %" << cad.porcentaje << std::endl;
    }

    std::sort(candidatos.begin(), candidatos.end(), [](const Candidatos &a, const Candidatos &b)
              { return a.porcentaje > b.porcentaje; });

    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        if (candidatos[i].porcentaje > 50)
        {
            std::cout << "\nEl Ganador de las elecciones es el Candidato " << candidatos[i].letra << std::endl;
            break;
        }
        else
        {
            std::cout << "\nLos candidatos que pasan a segunda ronda son:\n";
            std::cout << " - " << candidatos[0].letra << " (" << candidatos[0].porcentaje << "%)\n";
            std::cout << " - " << candidatos[1].letra << " (" << candidatos[1].porcentaje << "%)\n";
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matriz = llenarMatriz();
    /*std::vector<std::vector<int>> matriz = {
        {194, 48, 206, 45},
        {180, 20, 320, 16},
        {221, 90, 140, 20},
        {432, 50, 821, 14},
        {820, 61, 946, 18}};*/

    std::cout << std::endl;
    imprimirTabla(matriz);
    std::cout << std::endl;
    calcularTotalVotos(matriz);
    return 0;
}