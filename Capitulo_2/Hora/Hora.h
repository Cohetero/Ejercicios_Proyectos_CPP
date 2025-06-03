#ifndef HORA_H
#define HORA_H

class Hora
{
private:
    int hora, minutos, segundos;
    int h_original, m_original, s_original;
    static const int HORAS_TOTAL = 24;
    static const int MIN_SEG_TOTAL = 60;

public:
    Hora(int h, int m, int s);
    void adelantar(int h, int m, int s); // Para adelantar la hora
    void reiniciar();                    // Para reiniciar la hora actual
    void imprimir24() const;             // Formato 24h
    void imprimir12() const;             // Formato 12h con AM/PM
};

#endif