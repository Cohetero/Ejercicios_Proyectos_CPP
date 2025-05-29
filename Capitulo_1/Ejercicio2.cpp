/*
    Diseñar un diagrama de flujo y un algoritmo para calcular la velocidad (en m/s) de los corredores
    de la carrera de 1500 metros. La entrada consistirá en parejas de números (minutos, segundos)
    que dan el tiempo del corredor, por cada corredor, el algoritmo debe imprimir el tiempo en
    minutos y segundos así como la velocidad media. Ejemplo de entrada de datos: (3,53)(3,40)
    (3,46)(3,52)(4,0)(0,0); el último par de datos se utilizará como fin de entrada de datos
*/

#include <iostream>
#include <iomanip> // Para usar los manipuladores fixed y setprecision

struct Tiempo
{
    int minutos;
    int segundos;
};

int main(int argc, char *argv[])
{
    const int DISTANCIA = 1500;
    double velocidad;
    Tiempo t;

    std::cout << "Introduce tiempos de corredores (minutos segundos). Finaliza con 0 0 \n";

    while (true)
    {
        std::cout << "Tiempo (minutos segundos): ";
        std::cin >> t.minutos >> t.segundos;

        if (t.minutos == 0 && t.segundos == 0)
            break;

        int total_segundos = (t.minutos * 60) + t.segundos;
        velocidad = static_cast<double>(DISTANCIA) / total_segundos;

        std::cout << "Tiempo " << t.minutos << "m " << t.segundos << "s\n";
        std::cout << "Velocidad media: "
                  << std::fixed << std::setprecision(2)
                  << velocidad
                  << " m/s" << '\n';
    };

    std::cout << "Fin del programa\n";
    return 0;
}