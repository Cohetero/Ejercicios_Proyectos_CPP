#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo
{
private:
    double real, imaginario;

public:
    // Se quito los metodos de establecer ya que hace lo mismo que el constructor
    Complejo(double r = 0, double i = 0); // Sobrecarga de constructor

    // Metodos
    void imprimir() const;
    void agregar(const Complejo &otro);
    void agregar(double r, double i);

    // Operadores
    // Permite sobrecargar operadores como +, -, *, ==, etc para que se pueda usarlos
    // con objetos como si fueran tipos de datos normales
    Complejo operator+(const Complejo &otro_complejo) const;
    Complejo operator-(const Complejo &otro_complejo) const;
    Complejo operator*(const Complejo &otro_complejo) const;
    Complejo operator*(double escalar) const;
    Complejo operator~() const;

    // Función Amiga
    // para multiplicar real * Complejo
    friend Complejo operator*(double escalar, const Complejo &c);
};

#endif