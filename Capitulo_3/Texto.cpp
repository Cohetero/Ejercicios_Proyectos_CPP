/*
    Un texto de n lineas tiene ciertos caracteres que se consideran comdines. Hay dos comodines
    el # y el ? El primero indica que se ha de susitituir por la fecha actual, en formato dia (nn)
    de mes (nombre) año (aaaa), por ejemplo 21 de abril del 2025. El otro comodin indica que se
    debe remplazar por un nombre. Escribir el programa que lea las lineas del texto y cree un
    array de cadenas, cada elemento referencia a una cadena que es el resultado de realizar las
    sustituciones indicadas. La fecha y nombre se ha de obtener del flujo de entrada
*/

#include <iostream>
#include <string>
#include <vector>

std::string obtener_nombre_mes(int mes)
{
    std::string nombre_meses[] = {
        "enero", "febrero", "marzo", "abril", "mayo", "junio",
        "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    if (mes >= 1 && mes <= 12)
        return nombre_meses[mes - 1];
    else
        return "mes_invalido";
}

std::string obtener_fecha(int dia, int mes, int anio)
{
    return std::to_string(dia) + " de " + obtener_nombre_mes(mes) + " del " + std::to_string(anio);
}

std::string reemplazar_comodines(const std::string &linea, const std::string &fecha, const std::string &nombre)
{
    std::string resultado;

    for (char c : linea)
    {
        if (c == '#')
            resultado += fecha;
        else if (c == '?')
            resultado += nombre;
        else
            resultado += c;
    }

    return resultado;
}

int main()
{
    std::string lineas;
    std::string nombre;
    int dia, mes, anio, n_lineas;

    std::cout << "Introduzca un nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Introduza el numero de dia: ";
    std::cin >> dia;

    std::cout << "Introduza el numero del mes: ";
    std::cin >> mes;

    std::cout << "Introduza el numero de anio: ";
    std::cin >> anio;

    std::cout << "Introduza el numero de lineas para el texto: ";
    std::cin >> n_lineas;
    std::cin.ignore(); // Limpia el biffer

    std::string fecha = obtener_fecha(dia, mes, anio);
    std::vector<std::string> resultado;

    for (int i = 0; i < n_lineas; i++)
    {
        std::cout << "Linea " << i + 1 << ": ";
        std::getline(std::cin, lineas);
        resultado.push_back(reemplazar_comodines(lineas, fecha, nombre));
    }

    std::cout << "\nTexto con rememplazos:\n";
    for (const std::string &linea_resultado : resultado)
        std::cout << linea_resultado << "\n";

    return 0;
}