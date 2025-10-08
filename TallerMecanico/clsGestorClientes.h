#ifndef CLSGESTORCLIENTES_H_INCLUDED
#define CLSGESTORCLIENTES_H_INCLUDED
#include "clsCliente.h"
#include <iostream>

class clsGestorClientes{

public:
///CONSTRUCTORES
    clsGestorClientes();

///METODOS
    void CargarUnCliente(clsCliente &);
    void MostrarUnCliente(clsCliente); // Visualizar los datos de un cliente específico .


private:
    std::string _rutaDireccion;


};

#endif // CLSGESTORCLIENTES_H_INCLUDED
