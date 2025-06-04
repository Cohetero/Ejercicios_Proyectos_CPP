#ifndef FECHA_H
#define FECHA_H

class Fecha
{
private:
    int dia, mes, anio;
    int diasDelMes(int m, int a) const;
    bool esBisiesto(int a) const;
    void normalizar();

public:
    Fecha(); // Constructor por defecto

    // Accesores
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Metodos
    void reiniciar(int d, int m, int a);
    void adelantar(int d, int m, int a);
    void imprimir() const;
};

#endif