#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include "clsCliente.h"

class clsGestorClientes {
private:
    std::string _rutaDireccion; /// Guarda la ruta del archivo donde se guardan los registros

public:
    /// CONSTRUCTOR
    clsGestorClientes();

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
