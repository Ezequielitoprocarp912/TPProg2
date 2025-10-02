#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

#include <iostream>

class clsFecha
{

private:
///ATRIBUTOS
    int _dia;
    int _mes;
    int _anio;


///METODOS PRIVADOS
    bool validarFecha();
    bool esBisiesto(int);


public:
///SETTERS
    void setDia(int);
    void setMes(int);
    void setAnio(int);


///GETTERS
    int getDia();
    int getMes();
    int getAnio();


///CONSTRUCTORES
    clsFecha();
    clsFecha(int, int, int);


///METODOS PUBLICOS
std::string mostrar();


///SOBRECARGA PARA COMPARAR FECHAS
    bool operator == (clsFecha);
};


#endif // CLSFECHA_H_INCLUDED
