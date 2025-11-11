#pragma once

#include "clsCliente.h"
#include "clsVehiculo.h"
#include "clsFecha.h"

class clsReparacion
{
private:
    int _codReparacion;
    char _descripcionFalla[200];
    clsCliente _cliente;
    clsVehiculo _vehiculo;
    clsFecha _ingreso;
    clsFecha _reparado;
    clsFecha _egreso;
    bool _estado;

public:
    // CONSTRUCTORES
    clsReparacion();

    // SETTERS
    void setCodReparacion(int codReparacion);
    bool setDescripcionFalla(const char *descripcionFalla);
    void setCliente(clsCliente cliente);
    void setVehiculo(clsVehiculo vehiculo);
    void setFechaIngreso(clsFecha ingreso);
    void setFechaReparado(clsFecha reparado);
    void setFechaEgreso(clsFecha egreso);
    void setEstado(bool estado);

    // GETTERS
    int getCodReparacion();
    const char *getDescripcionFalla();
    clsCliente getCliente();
    clsVehiculo getVehiculo();
    clsFecha getFechaIngreso();      /// DEVUELVE clsFecha, no string
    clsFecha getFechaReparado();
    clsFecha getFechaEgreso();
    bool getEstado();
};

