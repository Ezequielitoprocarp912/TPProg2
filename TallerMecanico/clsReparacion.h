#ifndef CLSREPARACION_H_INCLUDED
#define CLSREPARACION_H_INCLUDED
#include "clsCliente.h"
#include "clsVehiculo.h"

class clsReparacion
{
private:

///ATRIBUTOS
    int _codReparacion;
    char _descripcionFalla [200];
    clsCliente _cliente;
    clsVehiculo _vehiculo;

public:
///CONSTRUCTORES
   clsReparacion();

///SETTERS
    void setCodReparacion (int codReparacion);
    void setDescripcionFalla (const char* descripcionFalla);
    void setCliente (clsCliente cliente) ;
    void setVehiculo (clsVehiculo vehiculo);

///GETTERS
   int getCodReparacion();
   const char* getDescripcionFalla();
   clsCliente getCliente();
   clsVehiculo getVehiculo();
};


#endif // CLSREPARACION_H_INCLUDED
