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
    void bajaCliente();
    void buscarCliente();
};
