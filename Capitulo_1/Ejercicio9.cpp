/*
    Diseñar el TAD Complejo para representar a los números complejos.
    Las operaciones que se deben definir:
        AsignaReal              (asigna un valor a la parte real)
        AsignaImaginaria        (asigna un valor a la parte imaginaria)
        ParteReal               (devuelve la parte real de un complejo)
        ParteImaginaria         (devuelve la parte imaginaria de un compeljo)
        Modulo                  (De un complejo)
        Suma                    (De dos numeros complejos)
    Realizar la especificacion informal y formal considerando como constructores las operaciones que desee.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

class Complejo
{
private:
    double real;
    double imaginaria;

public:
    // Construir por defecto (Cero)
    Complejo() : real(0), imaginaria(0) {}

    // Construir personalizado
    Complejo(double r, double i) : real(r), imaginaria(i) {}

    // Asignaciones
    void asignaReal(double r)
    {
        real = r;
    }

    void asignaImaginaria(double i)
    {
        imaginaria = i;
    }

    // Consultas
    double parteReal() const
    {
        return real;
    }

    double parteImaginaria() const
    {
        return imaginaria;
    }

    // Módulo (sqrt(real^2 + imag^2))
    double modulo() const
    {
        return std::sqrt(real * real + imaginaria * imaginaria);
    }

    // Suma de dos complejos
    Complejo suma(const Complejo &otro) const
    {
        return Complejo(real + otro.real, imaginaria + otro.imaginaria);
    }

    // Mostrar complejo
    void mostrar() const
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << real << (imaginaria >= 0 ? " + " : " - ")
                  << std::abs(imaginaria) << "i";
    }
};

int main()
{
    Complejo c1(3, 4);
    Complejo c2;

    c2.asignaReal(1);
    c2.asignaImaginaria(2);

    Complejo resultado = c1.suma(c2);

    std::cout << "Numero 1: ";
    c1.mostrar();
    std::cout << "\nNumero 2: ";
    c2.mostrar();
    std::cout << "\nSuma: ";
    resultado.mostrar();
    std::cout << "\nModulo de la suma: " << resultado.modulo() << "\n";

    return 0;
}