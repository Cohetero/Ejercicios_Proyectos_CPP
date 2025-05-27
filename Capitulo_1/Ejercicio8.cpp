/*
    Diseñar el TAD Bolsa como una colección de elementos no ordenados y que puede estar repetidos.
    Las operaciones del tipo abstracto:
        CrearBolsa
        Añadir      (un elemento )
        BolsaVacia  (verifica si tiene elementos)
        Dentro      (verifica si un elemento pertenece a la bolsa)
        Cuantos     (determina el numero de veces que se encuentra un elemento)
        Union       (Combina dos bolsas)
        Total       (Cantidad total de elementos en la bolsa)
    Realizar la especificacion informal y formal considerando como constructores las operaciones CrearBolsa y Añadir
*/

#include <iostream>
#include <vector>
#include <algorithm> // Para std::find y std::count

/*
    Clase que representa un Tipo de Dato Abstracto (TDA) llamado Bolsa
    Una Bolsa es una colección de elementos no ordenados que puede repetirse
*/
class Bolsa
{
private:
    // Vector para almacenar los elementos de la bolsa
    std::vector<int> elementos;

public:
    // Constructos: Crea una bolsa vacia
    Bolsa() {}

    // Añadir: agrega un elemento a la bolsa
    void anadir(int elemento)
    {
        elementos.push_back(elemento); // lo añade al final
    }

    // BolsaVacia: devuelve true si la bolsa no tiene elementos
    bool bolsaVacia() const
    {
        return elementos.empty(); // .empty() verifica si el vector está vacío
    }

    // Dentro: devuelve true si el elemento está en la bolsa (al menos una vez)
    bool dentro(int elemento) const
    {
        // std::find busca el elemento en el vector
        return std::find(elementos.begin(), elementos.end(), elemento) != elementos.end();
    }

    // Cuantos: cuenta cuántas veces aparece un elemento en la bolsa
    int cuantos(int elemento) const
    {
        // std::count cuenta cuántas veces aparece el elemento
        return std::count(elementos.begin(), elementos.end(), elemento);
    }

    // Union: devuelve una nueva bolsa que contiene los elementos de esta bolsa y de otra
    Bolsa unir(const Bolsa &otra) const
    {
        Bolsa resultado = *this; // copia la bolsa actual
        for (int e : otra.elementos)
        {
            resultado.anadir(e); // añade los elementos de la otra bolsa
        }

        return resultado;
    }

    // Total: devuelve el número total de elementos (contando repetidos)
    int total() const
    {
        return elementos.size(); // .size() devuelve el número total de elementos en el vector
    }

    // Mostrar: imprime todos los elementos de la bolsa (opcional, para pruebas)
    void mostrar() const
    {
        for (int e : elementos)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Bolsa b1;
    b1.anadir(3); // Añade 3
    b1.anadir(9);
    b1.anadir(3);

    Bolsa b2;
    b2.anadir(7);
    b2.anadir(2);

    // Unir b1 y b2 en una nueva bolsa
    Bolsa combinada = b1.unir(b2);

    // Total de elementos en la bolsa combinada
    std::cout << "Total en Bolsa combinada: " << combinada.total() << '\n';

    // Cuántas veces aparece el número 3
    std::cout << "Cuantos 3: " << combinada.cuantos(3) << '\n';

    // Verifica si el 5 está en la bolsa
    std::cout << "Esta 5? " << (combinada.dentro(5) ? "Si" : "No") << '\n';

    // Muestra todos los elementos
    std::cout << "Elementos: ";
    combinada.mostrar();

    return 0;
}