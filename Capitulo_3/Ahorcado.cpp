/*
    El juego de ahorcado se juega con dos personas (o una persona y una compotadora). Un jugador
    selecciona una palabra y el otro jugador trata de adivinar la palabra, adivinando letras
    individuales. Diseñar un programa para jugar al ahorcado.
    Sugerencia: almacenar una lista de palabras en un vector y seleccionar palabras aleatoriamente
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool buscar_letra(const std::string &palabra, std::string &adivinar_palabra, char letra)
{
    bool encontrada = false;
    for (size_t i = 0; i < palabra.length(); ++i)
    {
        if (palabra[i] == letra)
        {
            adivinar_palabra[i] = letra;
            encontrada = true;
        }
    }
    return encontrada;
}

void mostrar_ahorcado(int intentos)
{
    const std::vector<std::string> ahorcado = {
        "  _____  ",
        " |     | ",
        " |     O ",
        " |    /|\\",
        " |    / \\",
        " |        ",
        "_|_       "};

    int total_vidas = ahorcado.size();

    for (int i = 0; i < intentos && i < ahorcado.size(); ++i)
        std::cout << ahorcado[i] << std::endl;

    std::cout << std::endl;
}

int main()
{
    std::string palabra;
    std::set<char> letras_usadas;

    limpiar_pantalla();
    std::cout << "Ahorcado — Jugador 1\n";
    std::cout << "Ingresa la palabra a adivinar (sin espacios): ";
    std::cin >> palabra;

    limpiar_pantalla();
    std::string adivinar_palabra(palabra.length(), '*');

    int intentos = 0;
    const int vidas_maximas = 7; // ajustado a dibujo

    while (true)
    {
        limpiar_pantalla();

        std::cout << "Palabra: " << adivinar_palabra << "\n";
        std::cout << "Vidas restantes: " << (vidas_maximas - intentos) << "\n";
        std::cout << "Letras usadas: ";
        for (char c : letras_usadas)
            std::cout << c << ' ';
        std::cout << "\n\n";

        mostrar_ahorcado(intentos);

        std::cout << "Ingresa una letra: ";
        char letra;
        std::cin >> letra;

        letra = tolower(letra); // normalizar

        if (letras_usadas.count(letra))
        {
            std::cout << "Ya intentaste con '" << letra << "'. No pierdes vida.\n";
        }
        else
        {
            letras_usadas.insert(letra);

            if (buscar_letra(palabra, adivinar_palabra, letra))
            {
                std::cout << "¡Bien! La letra '" << letra << "' esta en la palabra.\n";
            }
            else
            {
                std::cout << "Ups... La letra '" << letra << "' no esta.\n";
                intentos++;
            }
        }

        if (adivinar_palabra == palabra)
        {
            std::cout << "\n¡Felicidades, ganaste! La palabra era: " << palabra << "\n";
            break;
        }
        else if (intentos >= vidas_maximas)
        {
            std::cout << "\nPerdiste... El jugador 1 gana. La palabra era: " << palabra << "\n";
            mostrar_ahorcado(intentos);
            break;
        }

        std::cin.ignore();
        std::cout << "\nPresiona Enter para continuar...";
        std::cin.get();
    }

    return 0;
}
