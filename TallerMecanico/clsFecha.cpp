#include "clsFecha.h"

///METODOS PRIVADOS
bool clsFecha::validarFecha()
{
    bool clsFechaValida = true;
    int meses[12] {31,28,31,30,31,30,30,31,30,31,30,31};
    if(esBisiesto(getAnio()))
    {
        meses[1]=29;
    }

    if(getDia()<1||getDia()>meses[getMes()-1]||getMes()<1||getMes()>12||getAnio()>2025)
    {
        clsFechaValida = false;
    }

    return clsFechaValida;
}

bool clsFecha::esBisiesto(int anio)
{
    if(((anio%4==0)||(anio%400==0))&&!(anio%100==0))
    {
        return true;
    }
    return false;
}


///SETTERS
void clsFecha::setDia(int dia)
{
    if(dia>0&&dia<32)
    {
        _dia=dia;
    }
}


///GETTERS
int clsFecha::getDia()
{
    return _dia;
}

int clsFecha::getMes()
{
    return _mes;
}

int clsFecha::getAnio()
{
    return _anio;
}

void clsFecha::setMes(int mes)
{
    if(mes>0&&mes<13)
    {
        _mes=mes;
    }
}

void clsFecha::setAnio(int anio)
{
    if(anio<2026)
    {
        _anio=anio;
    }
}


///CONSTRUCTOR DEFAULT
clsFecha::clsFecha()
{
    setDia(1);
    setMes(1);
    setAnio(1900);
}


///CONSTRUCTOR CON PARAMETROS
clsFecha::clsFecha(int dia = 1, int mes = 1, int anio = 2026)
{
    _dia=dia;
    _mes=mes;
    _anio=anio;
}


///METODOS PUBLICOS
std::string clsFecha::mostrar()
{
    return  std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}


///SOBRECARGA PARA COMPARAR FECHAS
bool clsFecha:: operator == (clsFecha clsFecha)
{

    if(getDia()!=clsFecha.getDia())
    {
        return false;
    }

    if(getMes()!=clsFecha.getMes())
    {
        return false;
    }

    if(getAnio()!=clsFecha.getAnio())
    {
        return false;
    }

    return true;
}
