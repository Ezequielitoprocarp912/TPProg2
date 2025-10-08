#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#include "clsCliente.h"

class clsGestorClientes
{
    private:
        std::string _rutaDireccion;

    public:
    ///CONSTRUCTORES
        clsGestorClientes();

    ///METODOS
        void CargarUnCliente(clsCliente &);
        void MostrarUnCliente(clsCliente); // Visualizar los datos de un cliente específico .

};
