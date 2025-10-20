#pragma once
#include <iostream>
#include "clsCliente.h"

class clsGestorCliente
{
private:
    std::string _rutaDireccion;

public:
    /// CONSTRUCTOR
    clsGestorCliente();

    /// M�TODOS DE MANIPULACI�N
    bool ev(std::string texto, int minimo, int maximo);
    void cargarUnCliente(clsCliente &);
    void mostrarUnCliente(clsCliente);

    /// M�TODOS DE ARCHIVO
    bool guardarEnDiscoCliente(clsCliente);
    bool guardarEnDiscoCliente(clsCliente, int);
    int buscarClientePorCuit(const char *);
    clsCliente leerCliente(int);

    /// EJECUCI�N DE OPCIONES
    void cargarCliente();
    void modificarCliente();
    void mostrarTodos();
    void mostrar_Activos_Inactivos();
    void bajaCliente();
    void buscarCliente();
};
