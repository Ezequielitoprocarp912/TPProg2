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

    /// MÉTODOS DE ARCHIVO
    bool guardarEnDiscoReparacion(clsReparacion);
    bool sobreEscribirEnDiscoReparacion(clsReparacion, int);
    int buscarReparacionPorCod(int);
    clsReparacion leerReparacion(int);
    int cantidadDeReparaciones();

    /// MÉTODOS DE MANIPULACIÓN
    bool ev(std::string texto, int minimo, int maximo);
    bool cargarUnaReparacion(clsReparacion &reparacion); /// AHORA ES BOOL XQ AUNQUE PONGA UNA PATENTE MAL GUARDABA UNA REPARACION VACIA
    void mostrarUnaReparacion(clsReparacion reparacion);

    /// METODOS DE EJECUCION

    void cargarReparacion();
    void mostrarTodas();
    void mostrarPorAnio();
    void buscarReparacion(); // POR CODIGO DE REPARACION

};
