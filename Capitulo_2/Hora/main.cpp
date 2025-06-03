/*
    Implementar la clase Hora. Cada objeto de esta clase representa una hora especifica del dia,
    almacenando las horas, minutos y segundos como enteros. Se ha de incluir un constructor,
    metodos de acceso, un metodo adelantar(int h, int m, int s) para adelantar la hora
    actual de un objeto existente, un metodo reiniciar (int h, int m, int s) que reinicializa
    la hora actual de un objeto existente y un metodo imprimir()
*/

#include <iostream>
#include <string>
#include "Hora.h"

// Constantes Globales
const int HORASTOTAL = 24;
const int MINSEGTOTAL = 60;
const int MIN = 0;

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool validarDato(int dato, int tipo)
{
    return dato >= 0 && dato < tipo;
}

int mensaje(int limite, std::string tipo)
{
    int tiempo;
    while (true)
    {
        std::cout << tipo << ": ";
        std::cin >> tiempo;
        if (validarDato(tiempo, limite))
            break;
        std::cout << tipo << " debe estar entre " << MIN << " y " << limite - 1 << std::endl;
    }
    return tiempo;
}

int main()
{
    int h, m, s;
    int opcion = 1;
    bool formatoHora = false;

    std::cout << "=== INGRESE LA HORA ===\n";
    h = mensaje(HORASTOTAL, "Hora");
    m = mensaje(MINSEGTOTAL, "Minutos");
    s = mensaje(MINSEGTOTAL, "Segundos");
    Hora h1(h, m, s);

    while (opcion != 4)
    {
        limpiar_pantalla();

        if (formatoHora)
            h1.imprimir24();
        else
            h1.imprimir12();

        std::cout << "\n=== Opciones para la Hora ===\n";
        std::cout << "1. Adelantar hora\n";
        std::cout << "2. Reiniciar hora\n";
        std::cout << "3. Cambiar formato 24h/12h\n";
        std::cout << "4. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (opcion == 4)
        {
            std::cout << "Hasta luego\n";
            break;
        }

        switch (opcion)
        {
        case 1:
            std::cout << "\nIntroduzca el tiempo de cuanto se va adelantar\n";
            std::cout << "Horas a adelantar: ";
            std::cin >> h;
            std::cout << "Minutos a adelantar: ";
            std::cin >> m;
            std::cout << "Segundos a adelantar: ";
            std::cin >> s;
            h1.adelantar(h, m, s);
            break;
        case 2:
            std::cout << "\nSe va a reiniciar la hora como estaba al inicio: ";
            h1.reiniciar();
            break;
        case 3:
            char respuesta;
            std::cout << "\nQuieres cambiar de formato de hora (24h/12h)? (s/n): ";
            std::cin >> respuesta;
            if (respuesta == 's' || respuesta == 'S')
                formatoHora = true;
            else
                formatoHora = false;
            break;
        default:
            std::cout << "Opcion invalida\n";
            break;
        }

        std::cin.ignore(); // limpia el buffer
        std::cout << "\nPresiona Enter para continuar...";
        std::cin.get();
    }

    return 0;
}