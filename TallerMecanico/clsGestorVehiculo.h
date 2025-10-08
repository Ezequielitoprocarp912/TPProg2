#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#include "clsVehiculo.h"

class clsGestorVehiculo
{
    private:
        std::string _rutaDireccion;

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

};
