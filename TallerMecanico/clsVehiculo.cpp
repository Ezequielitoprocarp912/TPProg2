#include <iostream>
#include <string>
#include <cstring>
#include "clsVehiculo.h"


///CONSTRUCTOR DEFAULT
clsVehiculo::clsVehiculo()
{
    strcpy(_numPatente,"0000000");
    strcpy(_marca,"SIN MARCA");
    strcpy(_modelo,"SIN MODELO");
    _tipoVehiculo = '0'; /// auto (1) - camion (2) - camioneta (3) - transporte (4)
    _estado=false;
}


///SETTERS
bool clsVehiculo::setNumeroPatente(const char* numPatente)
{
    if(strlen(numPatente) >=6 && strlen(numPatente) <= 7)
    {
        strcpy(_numPatente, numPatente);
        return true;
    }
    else
    {
        std::cout << "Patente no valida. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}


bool clsVehiculo::setMarca(const char* marca)
{
    if(strlen(marca) >= 1 && strlen(marca) <= 20)

    {
        strcpy(_marca, marca);
        return true;
    }
    else
    {
        return false;
    }
}

bool clsVehiculo::setModelo(const char* modelo)
{
    if(strlen(modelo) >= 1 && strlen(modelo) <= 20)

    {
        strcpy(_modelo, modelo);
        return true;
    }
    else
    {
        return false;
    }
}


bool clsVehiculo::setTipoVehiculo(char tipoVehiculo)
{
    if(tipoVehiculo == '1' || tipoVehiculo == '2' || tipoVehiculo == '3' || tipoVehiculo == '4')
    {
        _tipoVehiculo = tipoVehiculo;
        return true;
    }
    else
    {
        return false;
    }
}


void clsVehiculo::setEstado(bool estado)
{
    _estado = estado;
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


char clsVehiculo::getTipoVehiculo()
{
    return _tipoVehiculo;
}

const char* clsVehiculo::getModelo()
{
    return _modelo;
}

bool clsVehiculo::getEstado()
{
    return _estado;
}



