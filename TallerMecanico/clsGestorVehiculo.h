#pragma once
#include "clsVehiculo.h"

class clsGestorVehiculo
{
public:

    clsGestorVehiculo();
    void cargarUnVehiculo(clsVehiculo &); // Agregar un nuevo Vehiculo al sistema.
    void mostrarUnVehiculo(clsVehiculo); // Visualizar los datos de un Vehiculo específico por su id.

    /// MANIPULACION DE ARCHIVOS
    /**bool guardarEnDiscoVehiculo(Vehiculo);
    bool guardarEnDiscoVehiculo(Vehiculo,int);
    void listarTodosLosVehiculos();
    int buscarVehiculoPorId(int); /// El entero representa el id del Vehiculo
    void leerUnRegistro(int);
    Vehiculo leerVehiculo(int); /// El entero representa la posicion del registro en el archivo*/


private:
    std::string _rutaDireccion;
};
