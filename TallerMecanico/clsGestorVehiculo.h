#pragma once
#include "clsVehiculo.h"

class clsGestorVehiculo
{
public:

    clsGestorVehiculo();

    void cargarUnVehiculo(clsVehiculo &); // Agregar un nuevo Vehiculo al sistema.
    void mostrarUnVehiculo(clsVehiculo); // Visualizar los datos de un Vehiculo específico por su id.

    /// MANIPULACION DE ARCHIVOS
    bool guardarEnDiscoVehiculo(clsVehiculo);
    bool guardarEnDiscoVehiculo(clsVehiculo,int);
    void listarTodosLosVehiculos();
    int buscarVehiculoPorPatente(const char*);
    clsVehiculo leerVehiculo(int); /// El entero representa la posicion del registro en el archivo
    void modificarVehiculoPorPatente();

private:
    std::string _rutaDireccion;
};
