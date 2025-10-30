#include "clsCliente.h"
#include <iostream>
#include <cstdio>
#include <cstring>


/// CONSTRUCTOR DEFAULT
clsCliente::clsCliente()
{
    strcpy(_mail, "SIN MAIL");
    strcpy(_numTelefono, "SIN NUMERO");
    _tipoCliente = '0'; /// particular (1) - empresa (2)
    _estado = false;
}


///SETTERS

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


const char* clsCliente::getMail()
{
    return _mail;
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
