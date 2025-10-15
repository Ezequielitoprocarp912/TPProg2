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
    bool sobreEscribirEnDiscoReparacion(clsReparacion, int);
    int buscarReparacionPorCod(int);
    clsReparacion leerReparacion(int);
    int cantidadDeReparaciones();

    /// M�TODOS DE MANIPULACI�N
    bool ev(std::string texto, int minimo, int maximo);
    void cargarUnaReparacion(clsReparacion &reparacion);
    void mostrarUnaReparacion(clsReparacion reparacion);

    /// METODOS DE EJECUCION

    void cargarReparacion();
    void mostrarTodas();
    void buscarReparacion();

};
