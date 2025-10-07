#include <iostream>
#include <string>
#include <cstring>
#include "clsVehiculo.h"
#include "clsFecha.h"



///CONSTRUCTOR DEFAULT
clsVehiculo::clsVehiculo()
{
    strcpy(_numPatente,"SIN NUMERO PATENTE");
    strcpy(_marca,"SIN MARCA");
    _tipoVehiculo = '0'; /// auto (a) - camion (b) - camioneta (c) - transporte (t)
    _ingreso=clsFecha();

}

///CONSTRUCTOR CON PARAMETROS

clsVehiculo::clsVehiculo(const char* patente, const char* marca , int dia, int mes, int anio, char tipoVehiculo)
{
    strcpy(_numPatente,patente);
    strcpy(_marca,marca);
    _ingreso = clsFecha(dia,mes,anio);
    _tipoVehiculo = tipoVehiculo;
}


///SETTERS
void clsVehiculo::setNumeroPatente(const char* numPatente)
{
    ///VALIDACION
    if (strlen(numPatente) >= 6 && strlen(numPatente) <= 7 )
    {
        strcpy(_numPatente, numPatente);
    }
    else
    {
        strcpy(_numPatente, "PATENTE NO CARGADA");
    }
}


void clsVehiculo::setMarca(const char* marca)
{
    ///VALIDACION
    if (strlen(marca) >= 4 && strlen(marca) <= 20 )
    {
        strcpy(_marca, marca);
    }
    else
    {
        strcpy(_marca, "MARCA SIN CARGAR");
    }
}


void clsVehiculo::setIngreso(clsFecha ingreso)
{
    _ingreso = ingreso;
}


void clsVehiculo::setTipoVehiculo(char tipoVehiculo)
{
   _tipoVehiculo = tipoVehiculo;
}


///GETTERS

const char* clsVehiculo::getNumeroPatente()
{
    return _numPatente;
}

const char* clsVehiculo::getMarca()
{
    return _marca;
}


std::string clsVehiculo::getIngreso()
{
    return _ingreso.mostrar();
}


char clsVehiculo::getTipoVehiculo()
{
    return _tipoVehiculo;
}



