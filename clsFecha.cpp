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
clsFecha::clsFecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

///METODOS PUBLICOS
std::string clsFecha::mesToString()
{
    switch (_mes) {
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Septiembre";
        case 10: return "Octubre";
        case 11: return "Noviembre";
        case 12: return "Diciembre";
        default: return "Mes inválido"; // Para proteger en caso de que llegue un valor fuera del rango 1-12
    }
}

std::string clsFecha::mostrar()
{
    return  std::to_string(_dia) + "/" + mesToString() + "/" + std::to_string(_anio);
}


///SOBRECARGA PARA COMPARAR FECHAS
bool clsFecha:: operator == (clsFecha fecha)
{

    if(getAnio()!=fecha.getAnio())
    {
        return false;
    }

    if(getMes()!=fecha.getMes())
    {
        return false;
    }

    if(getDia()!=fecha.getDia())
    {
        return false;
    }

    return true;
}

bool clsFecha:: operator < (clsFecha fecha)
{

    if(getAnio()<fecha.getAnio())
    {
        return true;
    }

    if(getMes()<fecha.getMes())
    {
        return true;
    }

    if(getDia()<fecha.getDia())
    {
        return true;
    }

    return false;
}

bool clsFecha:: operator > (clsFecha fecha)
{

    if(getAnio()>fecha.getAnio())
    {
        return true;
    }

    if(getMes()>fecha.getMes())
    {
        return true;
    }

    if(getDia()>fecha.getDia())
    {
        return true;
    }

    return false;
}

/// SI LOS VALORES PARECEN VALIDOS
bool clsFecha::setFecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;

    if (validarFecha()) {
        return true;
    } else {
        // Restaurar a default
        setDia(1);
        setMes(1);
        setAnio(1900);
        return false;
    }
}
