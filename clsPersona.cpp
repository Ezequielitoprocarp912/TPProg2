#include "clsPersona.h"
#include <iostream>
#include <cstring>


/// CONSTRUCTOR DEFAULT
clsPersona::clsPersona()
{
    strcpy(_cuit, "SIN CUIT");
    strcpy(_nombre, "SIN NOMBRE");
    strcpy(_apellido, "SIN APELLIDO");
    strcpy(_direccion, "SIN DIRECCION");
}


///SETTERS
bool clsPersona::setCuit (const char* cuit)
{
    ///VALIDACION
    if (strlen(cuit)==11)
    {
        strcpy(_cuit, cuit);
        return true;
    }
    else
    {
        std::cout << "Cuit no valido. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}


bool clsPersona::setNombre (const char* nombre)
{
    if(strlen(nombre) >= 1 && strlen(nombre) <= 20)
    {
        strcpy(_nombre, nombre);
        return true;
    }
    else
    {
        std::cout << "Nombre no valido. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}


bool clsPersona::setApellido (const char* apellido)
{
    if(strlen(apellido) >= 1 && strlen(apellido) <= 20)
    {
        strcpy(_apellido, apellido);
        return true;
    }
    else
    {
        std::cout << "Apellido no valido. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}




bool clsPersona::setDireccion (const char* direccion)
{
    if(strlen(direccion) >= 1 && strlen(direccion) <= 50)
    {
        strcpy(_direccion, direccion);
        return true;
    }
    else
    {
        std::cout << "Direccion no valida. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}


///GETTERS

const char* clsPersona::getCuit()
{
    return _cuit;
}

const char* clsPersona::getNombre()
{
    return _nombre;
}

const char* clsPersona::getApellido()
{
    return _apellido;
}


const char* clsPersona::getDireccion()
{
    return _direccion;
}


