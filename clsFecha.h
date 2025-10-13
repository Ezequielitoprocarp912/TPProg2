#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

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
