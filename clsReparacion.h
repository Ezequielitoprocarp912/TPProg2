#pragma once

#include "clsCliente.h"
#include "clsVehiculo.h"
#include "clsFecha.h"

class clsReparacion
{
    private:
    ///ATRIBUTOS
        int _codReparacion;
        char _descripcionFalla [200];
        clsCliente _cliente;
        clsVehiculo _vehiculo;
        clsFecha _ingreso;
        clsFecha _reparado;
        clsFecha _egreso;
        bool _estado;

    public:
    ///CONSTRUCTORES
        clsReparacion();

    ///SETTERS
        void setCodReparacion (int codReparacion);
        bool setDescripcionFalla (const char* descripcionFalla);
        bool setCliente (clsCliente cliente);
        bool setVehiculo (clsVehiculo vehiculo);
        bool setFechaIngreso(clsFecha ingreso);
        bool setFechaReparado(clsFecha reparado);
        bool setFechaEgreso(clsFecha egreso);
        void setEstado(bool estado);


    ///GETTERS
        int getCodReparacion();
        const char* getDescripcionFalla();
        clsCliente getCliente();
        clsVehiculo getVehiculo();
        clsFecha getFechaIngreso();
        clsFecha getFechaReparado();
        clsFecha getFechaEgreso();
        bool getEstado();
};
