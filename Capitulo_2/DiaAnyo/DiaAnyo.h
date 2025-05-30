#ifndef PUNTO_H // Pregunta si no está definido el símbolo PUNTO_H. Si no está definido, el código continúa.
#define PUNTO_H // Define el símbolo PUNTO_H. Esto indica que ya se incluyó el contenido de este archivo.

class DiaAnyo
{
private:
    int dia, mes;

public:
    DiaAnyo(int d, int m);
    bool igual(const DiaAnyo &d) const;
    void visualizar() const;
};

#endif // Cierra la condición.