/*
    Escribir un algoritmo de flujo y un algoritmo que cuente el número de ocurrencias de cada letra en una palabra
    leída como entrada. Por ejemplo, "Mortimer" contiene dos "m", una "o", dos "r", una "y", una "t" y una "e"
*/

#include <iostream>
#include <string> // Para usar la clase std::string
#include <map>    // Para usar std::map

int main(int argc, char *argv[])
{
    std::string palabra;
    std::cout << "Ingrese una palabra: ";
    std::cin >> palabra;

    // Convierte todo a minúsculas (opcional)
    for (char &c : palabra) // char &c es para modificar directamente cada letra de la palabra original
        c = tolower(c);     // conviete una letra a minúsculas

    // Crea un mapa vacío llamado ocurrencias
    std::map<char, int> ocurrencias;

    // Contamos cada letra
    for (char c : palabra) // Si una letra ya existe en el mapa, le suma 1
        ocurrencias[c]++;  // Si no existe, se crea con valor 0 y luego se incrementa a 1 automáticamente

    // Mostramos resultados
    for (const auto &par : ocurrencias)
        // par.first -> la letra, par.second -> el número de veces
        std::cout << "La letra '" << par.first << "' aparece " << par.second << " veces.\n";

    return 0;
}