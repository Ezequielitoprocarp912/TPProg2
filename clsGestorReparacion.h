#pragma once
#include <iostream>
#include "clsReparacion.h"

class clsGestorReparacion
{
private:
    std::string _rutaDireccion;

public:
    /// CONSTRUCTOR
    clsGestorReparacion();

    /// M�TODOS DE ARCHIVO
    bool guardarEnDiscoReparacion(clsReparacion);
    bool SobreEscribirEnDiscoReparacion(clsReparacion, int);
    int buscarReparacionPorCod(int);
    clsReparacion leerReparacion(int);
    int cantidadDeReparaciones();

    /// M�TODOS DE MANIPULACI�N
    void cargarUnaReparacion(clsReparacion &);
    void mostrarUnaReparacion(clsReparacion);

};
