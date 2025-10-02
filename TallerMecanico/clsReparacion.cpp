#include "clsReparacion.h"
#include "clsCliente.h"
#include "clsVehiculo.h"
#include <cstring>

///CONSTRUCTORES
clsReparacion::clsReparacion()
{
    _codReparacion=0;
    strcpy(_descripcionFalla, "");
    _cliente=clsCliente();
    _vehiculo=clsVehiculo();
}

///SETTERS
void clsReparacion::setDescripcionFalla(const char* descripcionFalla)
{
    strcpy(_descripcionFalla, descripcionFalla);
}

void clsReparacion::setCliente(clsCliente cliente)
{
    _cliente=cliente;
}

void clsReparacion::setVehiculo(clsVehiculo vehiculo)
{
    _vehiculo=vehiculo;
}

///GETTERS
int clsReparacion::getCodReparacion()
{
    return _codReparacion;
}

const char* clsReparacion::getDescripcionFalla()
{
    return _descripcionFalla;
}

clsCliente clsReparacion::getCliente()
{
    return _cliente;
}

clsVehiculo clsReparacion::getVehiculo()
{
    return _vehiculo;
}
