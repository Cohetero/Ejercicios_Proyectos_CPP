/*
    Se  quiere sumar numeros grandes, tan grandes que no pueden almacenarse en variables de tipo long.
    Por lo que se ha pensado en introducir cada numero como una cadena de caracteres y realizar
    la suma extrayendo los digitos de ambas cadenas.
*/

#include <iostream>
#include <algorithm> // Funcion reverse
#include <string>
#include <typeinfo>

int main()
{
    std::string numero_1;
    std::string numero_2;

    std::cout << "Introduzca el primer Numero: ";
    std::cin >> numero_1;

    std::cout << "Introduzca el segundo Numero: ";
    std::cin >> numero_2;

    std::string resultado, numero_1_inv, numero_2_inv;
    int n1, n2, suma, acarreo, nuevo_digito, size_mayor;

    numero_1_inv = numero_1;
    numero_2_inv = numero_2;
    std::reverse(numero_1_inv.begin(), numero_1_inv.end());
    std::reverse(numero_2_inv.begin(), numero_2_inv.end());

    std::cout << numero_1_inv << std::endl
              << numero_2_inv << std::endl;

    if (numero_1_inv.length() >= numero_2_inv.length())
        size_mayor = numero_1_inv.length();
    else
        size_mayor = numero_2_inv.length();

    resultado = "";
    acarreo = 0;
    for (int i = 0; i < size_mayor; i++)
    {
        if (i >= numero_1_inv.length())
            n1 = 0;
        else
            n1 = numero_1_inv[i] - '0';

        if (i >= numero_2_inv.length())
            n2 = 0;
        else
            n2 = numero_2_inv[i] - '0';

        suma = n1 + n2 + acarreo;
        nuevo_digito = suma % 10;
        acarreo = suma / 10;

        std::cout << n1 << " + " << n2 << " = " << suma << std::endl;
        std::cout << suma << " % 10" << " = " << nuevo_digito << std::endl;
        std::cout << suma << " / 10" << " = " << acarreo << std::endl;

        resultado += '0' + nuevo_digito;
    }

    if (acarreo > 0)
        resultado += '0' + acarreo;
    std::reverse(resultado.begin(), resultado.end());
    std::cout << "\nresultado: " << resultado;

    return 0;
}