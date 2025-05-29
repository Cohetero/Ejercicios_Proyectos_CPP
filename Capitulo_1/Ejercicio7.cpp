/*
    Construir el TAD Natural para representar a los números naturales, con las operaciones:
    Cero, Sucesor, EsCero, Igual, Suma, Antecesor, Diferencia y Menor. Realizar la especificación
    informal y formal considerando como constructores las operaciones Cero y Sucesor
*/

#include <iostream>

class Natural
{
private:
    int numero;

public:
    // Constructor
    Natural(int numero)
    {
        if (numero < 0)
            this->numero = 0;
        else
            this->numero = numero;
    }

    // Operaciones
    int sucesor() const
    {
        return numero + 1;
    }

    bool esCero() const
    {
        return numero == 0;
    }

    bool esIgual(int otro) const
    {
        return numero == otro;
    }

    int suma(int otro) const
    {
        return numero + otro;
    }

    int antecesor() const
    {
        if (numero == 0)
            return 0;
        return numero - 1;
    }

    int diferencia(int otro) const
    {
        int resultado = numero - otro;
        return resultado < 0 ? 0 : resultado;
    }

    bool esMenorQue(int otro) const
    {
        return numero < otro;
    }

    int mostrar() const
    {
        return numero;
    }
};

int main()
{
    Natural n1(8);
    int numero;

    std::cout << "Numero actual: " << n1.mostrar() << "\n";
    std::cout << "Sucesor: " << n1.sucesor() << "\n";
    std::cout << "Es cero? " << (n1.esCero() ? "Si" : "No") << "\n";
    std::cout << "Antecesor: " << n1.antecesor() << "\n\n";

    std::cout << "Ingrese otro numero para comparar: ";
    std::cin >> numero;

    std::cout << "Es igual a " << numero << "? "
              << (n1.esIgual(numero) ? "Si" : "No") << "\n";

    std::cout << "Suma con " << numero << ": " << n1.suma(numero) << "\n";
    std::cout << "Diferencia con " << numero << ": " << n1.diferencia(numero) << "\n";
    std::cout << "Es menor que " << numero << "? "
              << (n1.esMenorQue(numero) ? "Si" : "No") << "\n";

    return 0;
}
