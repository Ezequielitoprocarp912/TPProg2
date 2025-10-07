#include <cstring>
#include "clsCliente.h"



/// CONSTRUCTOR DEFAULT
clsCliente::clsCliente()
{
    strcpy(_cuit, "SIN CUIT");
    strcpy(_nombre, "SIN NOMBRE");
    strcpy(_apellido, "SIN APELLIDO");
    strcpy(_mail, "SIN MAIL");
    strcpy(_direccion, "SIN DIRECCION");
    _tipoCliente = '0'; /// 0 default - 1 particular - 2 empresa
    _estado = false;
}

///CONSTRUCTOR CON PARAMETROS
clsCliente::clsCliente(const char* cuit, const char* nombre, const char* apellido, const char* mail, const char* direccion, char tipoCliente)
{
    strcpy(_cuit, cuit);
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_mail, mail);
    strcpy(_direccion, direccion);
    _tipoCliente=tipoCliente;
    _estado=true;
}



///SETTERS
void clsCliente::setCuit (const char* cuit)
{
    ///VALIDACION
    if (strlen(cuit) >= 4 && strlen(cuit) <= 11 )
    {
        strcpy(_cuit, cuit);
    }
    else
    {
        strcpy(_cuit, "CUIT NO CARGADO");
    }
}

void clsCliente::setNombre (const char* nombre)
{
    if (strlen(nombre) > 0)
    {
        strcpy(_nombre, nombre);
    }
    else
    {
        strcpy(_nombre, "NOMBRE NO CARGADO");
    }
}


void clsCliente::setApellido (const char* apellido)
{
    if (strlen(apellido) > 0)
    {
        strcpy(_apellido, apellido);
    }
    else
    {
        strcpy(_apellido, "APELLIDO NO CARGADO");
    }
}
void clsCliente::setMail (const char* mail)
{
    if (strlen(mail) > 0)
    {
        strcpy(_mail, mail);
    }
    else
    {
        strcpy(_mail, "APELLIDO NO CARGADO");
    }
}

///TELEFONO
void clsCliente::setNumTelefono(const char *telefono)
{
        if (strlen(telefono) > 0)
    {
        strcpy(_numTelefono, telefono);
    }
    else
    {
        strcpy(_numTelefono, "TELEFONO NO CARGADO");
    }
}



void clsCliente::setDireccion (const char* direccion)
{
    if (strlen(direccion) > 0)
    {
        strcpy(_direccion, direccion);
    }
    else
    {
        strcpy(_direccion, "APELLIDO NO CARGADO");
    }
}
void clsCliente::setTipoCliente (char tipoCliente)
{
    _tipoCliente=tipoCliente;
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
const char * clsCliente::getNumTelefono()
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
