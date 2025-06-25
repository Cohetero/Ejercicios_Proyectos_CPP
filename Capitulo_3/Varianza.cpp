/*
    Si x representa la medida de los numeros X1, X2, ... Xn, entonces la varianza es la media de los
    cuadrados de las desviaciones de los números de la media.

                                       n
                        varianza = 1/n E (X1 - X)^2
                                      i=1

    Y la desviacion estandar es la raiz cuadrada de la varianza. Escribir un programa que lea una lista de numeros
    reales, los cuente y a continuacion calcule e imprime su media, varianza y desviacion estandar. Utilizar una funcion
    para calcular la media, otra para calcular la varianza y otra para la desviacion estandar
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

std::vector<double> llenarVector()
{
    int n;
    do
    {
        std::cout << "¿Cuántos números desea introducir? ";
        std::cin >> n;
    } while (n <= 0);

    std::vector<double> numeros(n);

    std::cout << "\nIntroduzca los numeros:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "A[" << i + 1 << "] = ";
        std::cin >> numeros[i];
    }

    return numeros;
}

double calcularMedia(const std::vector<double> &numeros)
{
    double media = 0;
    int n = numeros.size();

    for (const auto &i : numeros)
        media += i;

    return (media / n);
}

double calcularVarianza(const std::vector<double> &numeros, const double &media)
{
    double varianza = 0;
    int n = numeros.size();

    for (const auto &i : numeros)
        varianza += std::pow((i - media), 2.0);

    return (varianza / n);
}

double calcularDesviacionEstandar(const double &varianza)
{
    return std::sqrt(varianza);
}

int main()
{
    std::vector<double> numeros = llenarVector();
    double media, varianza, desviacion_estandar;

    std::cout << "\nDatos ingresados: ";
    for (double d : numeros)
        std::cout << d << " ";

    media = calcularMedia(numeros);
    varianza = calcularVarianza(numeros, media);
    desviacion_estandar = calcularDesviacionEstandar(varianza);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "La Media es de: " << media << std::endl
              << "La Varianza es de: " << varianza << std::endl
              << "La Desviacion Estandar: " << desviacion_estandar;

    return 0;
}