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

    /// MÉTODOS DE MANIPULACIÓN
    void cargarUnCliente(clsCliente &);
    void mostrarUnCliente(clsCliente);

    /// MÉTODOS DE ARCHIVO
    bool guardarEnDiscoCliente(clsCliente);
    bool guardarEnDiscoCliente(clsCliente, int);
    int buscarClientePorCuit(const char *);
    clsCliente leerCliente(int);

    /// EJECUCIÓN DE OPCIONES
    void cargarCliente();
    void modificarCliente();
    void mostrarTodos();
    void bajaCliente();
    void buscarCliente();
};
