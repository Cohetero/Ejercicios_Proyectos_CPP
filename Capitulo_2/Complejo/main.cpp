/*
    Realizar la clase Complejo que permita la gestión de números complejos (un número complejo consta
    de dos números reales de tipo double : una parte real + una parte imaginaria.)
    Las operaciones a implementar son las siguientes:
        * establecer() permite inicializar  un objeto de tipo Complejo a partir de dos componentes double.
        * imprimir() realiza la visualizacion formateada de un Complejo
        * agregar() (sobrercargado) para añadir, respectivamente, un Complejo a otro y añadir de dos componentes double a un Complejo.
        * Suma: a + c = (A + C, (B + D)i)
        * Resta: a - b = (A - C, (B - D)i)
        * Multiplicación: a * c = (A * C - B * D, (A * D + B * C)i)
        * Multiplicación: x * c = (x * C, x * Di), donde x es real.
        * Conjugado: ~a = (A, -Bi)
        Siendo a = A + Bi; c = C + Di
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "Complejo.h"

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrar(const std::string &nombre, const Complejo &c)
{
    std::cout << nombre << ": ";
    c.imprimir();
}

void Operacion(const Complejo &c1, const Complejo &c2, int opcion)
{
    Complejo resultado;
    std::string mensaje;

    switch (opcion)
    {
    case 1:
        resultado = c1 + c2;
        mensaje = "Suma";
        break;
    case 2:
        resultado = c1 - c2;
        mensaje = "Resta";
        break;
    case 3:
        resultado = c1 * c2;
        mensaje = "Multiplicacion";
        break;
    case 4:
    {
        double real;
        std::cout << "Real a multiplicar: ";
        std::cin >> real;
        resultado = c1 * real;
        mensaje = "Multiplicacion por real";
        break;
    }
    case 5:
        resultado = ~c1;
        mensaje = "Conjugado de c1";
        break;
    default:
        std::cout << "Opcion invalida\n";
        break;
    }

    std::cout << "\n"
              << mensaje << ": ";
    resultado.imprimir();
}

int main()
{
    double real, imaginario;
    int opcion;

    std::cout << "=== INGRESO DE DATOS PARA c1 ===\n";
    std::cout << "Real: ";
    std::cin >> real;
    std::cout << "Imaginario: ";
    std::cin >> imaginario;
    Complejo c1(real, imaginario);

    std::cout << "\n=== INGRESO DE DATOS PARA c2 ===\n";
    std::cout << "Real: ";
    std::cin >> real;
    std::cout << "Imaginario: ";
    std::cin >> imaginario;
    Complejo c2(real, imaginario);

    while (true)
    {
        limpiar_pantalla();

        std::cout << "\n=== OPERACIONES CON NUMEROS COMPLEJOS ===\n";
        mostrar("c1", c1);
        mostrar("c2", c2);

        std::cout << "\nElige una opcion:\n";
        std::cout << "1. Suma\n";
        std::cout << "2. Resta\n";
        std::cout << "3. Multiplicacion\n";
        std::cout << "4. Multiplicacion con Real\n";
        std::cout << "5. Conjugado\n";
        std::cout << "6. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (opcion == 6)
        {
            std::cout << "Hasta luego\n";
            break;
        }

        Operacion(c1, c2, opcion);

        std::cin.ignore(); // limpia el buffer
        std::cout << "\nPresiona Enter para continuar...";
        std::cin.get();
    }

    return 0;
}