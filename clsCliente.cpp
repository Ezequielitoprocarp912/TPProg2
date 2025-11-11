#include "clsCliente.h"
#include <iostream>
#include <cstdio>
#include <cstring>


/// CONSTRUCTOR DEFAULT
clsCliente::clsCliente()
{
    strcpy(_cuit, "SIN CUIT");
    strcpy(_nombre, "SIN NOMBRE");
    strcpy(_apellido, "SIN APELLIDO");
    strcpy(_mail, "SIN MAIL");
    strcpy(_direccion, "SIN DIRECCION");
    _tipoCliente = '0'; /// particular (1) - empresa (2)
    _estado = false;
}


///SETTERS
bool clsCliente::setCuit (const char* cuit)
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


bool clsCliente::setNombre (const char* nombre)
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


bool clsCliente::setApellido (const char* apellido)
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


bool clsCliente::setMail (const char* mail)
{
    if(strlen(mail) >= 1 && strlen(mail) <= 50)
    {
        strcpy(_mail, mail);
        return true;
    }
    else
    {
        std::cout << "Mail no valido. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}


bool clsCliente::setNumTelefono(const char *telefono)
{
    if(strlen(telefono) >= 1 && strlen(telefono) <= 20)
    {
        strcpy(_numTelefono, telefono);
        return true;
    }
    else
    {
        std::cout << "Telefono no valido. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}


bool clsCliente::setDireccion (const char* direccion)
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


bool clsCliente::setTipoCliente (char tipoCliente)
{
    if(tipoCliente == '1' || tipoCliente == '2')
    {
        _tipoCliente=tipoCliente;
        return true;
    }
    else
    {
        std::cout << "Tipo de cliente no valido. Ingrese nuevamente." << std::endl;
        system("pause");
        return false;
    }
}

void clsCliente::setEstado (bool estado)
{
    _estado = estado;
}


///GETTERS

const char* clsCliente::getCuit()
{
    return _cuit;
}

const char* clsCliente::getNombre()
{
    return _nombre;
}

const char* clsCliente::getApellido()
{
    return _apellido;
}

const char* clsCliente::getMail()
{
    return _mail;
}

const char* clsCliente::getDireccion()
{
    return _direccion;
}

const char* clsCliente::getNumTelefono()
{
    return _numTelefono;
}

char clsCliente::getTipoCliente()
{
    return _tipoCliente;
}

bool clsCliente::getEstado ()
{
    return _estado;
}
