/*
    Escribir un programa que lea una cadena clave y un texto de como maximo 50 lineas-
    El programa debe de eliminar las lineas que contengan la clave.
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> leerTexto()
{
    std::vector<std::string> texto;
    std::string linea;
    int num_Lineas;

    std::cout << "Numero de Lineas (max 50): ";
    std::cin >> num_Lineas;
    std::cin.ignore();

    if (num_Lineas > 50)
        num_Lineas = 50;

    for (int i = 0; i < num_Lineas; i++)
    {
        std::cout << "Linea " << i + 1 << ": ";
        std::getline(std::cin, linea);
        texto.push_back(linea);
    }

    return texto;
}

void eliminarPalabraClave(std::vector<std::string> &texto)
{
    std::string palabra;
    std::cout << "Introduzca una palabra a eliminar: ";
    std::cin >> palabra;

    for (auto &linea : texto)
    {
        size_t pos = 0;
        while ((pos = linea.find(palabra, pos)) != std::string::npos)
            // No se incrementa pos porque la linea se acorot
            linea.erase(pos, palabra.length());
    }
}

void eliminarLineasClave(std::vector<std::string> &texto)
{
    std::string clave;
    std::cout << "Introduzca una palabra clave: ";
    std::cin >> clave;

    std::vector<std::string> resultado;

    for (const auto &linea : texto)
    {
        // std::string::npos significa que no encontro nada o nulo
        // Si no encontro nada es igual a no encontro nada?
        // Guarda la linea
        if (linea.find(clave) == std::string::npos)
            resultado.push_back(linea);
    }

    texto = resultado;
}

void imprimirTexto(const std::vector<std::string> &texto)
{
    for (const auto &linea : texto)
        std::cout << linea << std::endl;
}

int main()
{
    std::vector<std::string> texto = leerTexto();
    int opcion;

    do
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Eliminar Palabra Clave\n";
        std::cout << "2. Eliminar Lineas Clave\n";
        std::cout << "3. Salir\n>";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            eliminarPalabraClave(texto);
            imprimirTexto(texto);
            break;
        case 2:
            eliminarLineasClave(texto);
            imprimirTexto(texto);
            break;
        case 3:
            std::cout << "Hasta Luego!!!";
            break;
        default:
            std::cout << "\nNo es una opcion valida...\n";
            break;
        }
    } while (opcion != 3);

    return 0;
}