#pragma once
#include "clsVehiculo.h"


class clsGestorVehiculo
{
public:

    clsGestorVehiculo();

    void cargarUnVehiculo(clsVehiculo &vehiculo); // Agregar un nuevo Vehiculo al sistema.
    void mostrarUnVehiculo(clsVehiculo); // Visualizar los datos de un Vehiculo específico por su id.

    /// METODOS DE MANIPULACION
    bool guardarEnDiscoVehiculo(clsVehiculo registro);
    bool guardarEnDiscoVehiculo(clsVehiculo registro, int posicion);
    int buscarVehiculoPorPatente(const char*);
    clsVehiculo leerVehiculo(int); /// El entero representa la posicion del registro en el archivo

    ///EJECUCION DE OPCIONES
    void cargarVehiculo();
    void modificarVehiculo();
    void mostrarTodos();
    void bajaVehiculo();
    void buscarVehiculo();

private:
    std::string _rutaDireccion;
};
