#pragma once

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
        ///HACER DESPUES
        //bool _estado /// 1 en reparacion - 0 reparado

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
