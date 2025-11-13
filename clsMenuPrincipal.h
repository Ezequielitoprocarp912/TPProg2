#pragma once
#include "clsGestorCliente.h"

class clsMenuPrincipal
{
    private:
    ///ATRIBUTOS
        int _opcion;
        bool _salir;

    public:
    ///METODOS
        void mostrar();
        void elegirOpcion();
        void opcionesMenu();
        void ejecutarMenuPrincipal();
        //
        void mostrarMenuClientes();
        void opcionesMenuClientes();
        void ejecutarMenuClientes();

        void mostrarSubMenuCUIT();
        void opcionesSubMenuCUIT(clsGestorCliente &gestorClientes);
        void ejecutarSubMenuCUIT(clsGestorCliente &gestorClientes);
        //
        void mostrarMenuVehiculos();
        void opcionesMenuVehiculos();
        void ejecutarMenuVehiculos();
        //
        void mostrarMenuReparaciones();
        void opcionesMenuReparaciones();
        void ejecutarMenuReparaciones();

    ///CONSTRUCTORES
        clsMenuPrincipal();
};
