/*
    Se sabe que en las lineas de que forma un texto hay valores numericos enteros, representan los
    kg de patatas recogidas en una finca. Los valores numericos estan separados de las palabras
    por un blanco, o el caracter fin de linea. Escribir un programa que lea el texto y obtenga
    la suma de los valores numericos
*/

#include <iostream>
#include <sstream> // Para la funcion istringstream y stoi
#include <vector>
#include <string>

std::vector<std::string> leerTexto()
{
    std::vector<std::string> texto;
    std::string linea;
    int num_Lineas;

    std::cout << "Numero de Lineas: ";
    std::cin >> num_Lineas;
    std::cin.ignore();

    for (int i = 0; i < num_Lineas; i++)
    {
        std::cout << "Linea " << i + 1 << ": ";
        std::getline(std::cin, linea);
        texto.push_back(linea);
    }

    return texto;
}

int sumaKiloPapas(const std::vector<std::string> &texto)
{
    int total = 0;

    for (const auto &linea : texto)
    {
        std::istringstream iss(linea); // Para dividir cada linea en palabras
        std::string palabra;

        while (iss >> palabra) // Extrae una palabra de la linea y la guarda en la variable palabra
        {
            // Intentamos convertir la palabra a numero
            try
            {
                size_t idx;
                int numero = std::stoi(palabra, &idx); // Intenta convertir una palabra en un numero entero y guarda cuantos caracteres se usaron en la conversion
                if (idx == palabra.length())           // Verifica que toda la palabra era un numero
                    total += numero;
            }
            catch (...)
            {
                // No era un numero se ignora
            }
        }
    }

    return total;
}

int main()
{
    std::vector<std::string> texto = leerTexto();

    std::cout << "La suma total de kilos es = " << sumaKiloPapas(texto);
    return 0;
}