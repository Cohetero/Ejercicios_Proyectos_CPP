/*
    Escribir un algoritmo que encuentre el salario semanal de un trabajador, dada la tarifa
    horaria y el número de horas trabajadas diariamente
*/

#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    double tarifa;
    int horas_diarias, dias_trabajados;

    std::cout << "Ingrese la tarifa horaria (por hora): ";
    std::cin >> tarifa;

    std::cout << "Ingrese el numero de horas trabajadas diariamente: ";
    std::cin >> horas_diarias;

    std::cout << "Ingrese el numero de dias trabajados a la semana: ";
    while (true)
    {
        std::cin >> dias_trabajados;
        if (1 <= dias_trabajados && dias_trabajados <= 7)
            break;
        std::cout << "El numero de dias tiene que estar entre 1 a 7\n";
        std::cout << "Al menos que vivas en otro planeta 🌍👽\n";
    }

    double salario_semanal = tarifa * horas_diarias * dias_trabajados;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "El salario semanal es de: $" << salario_semanal << std::endl;

    return 0;
}