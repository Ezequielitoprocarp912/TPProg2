#pragma once

class clsMenuPrincipal
{
    private:
    ///ATRIBUTOS
        int _opcion;
        bool _salir;

    public:
    ///METODOS

        void mostrar();
        void opcionesMenu();
        void ejecutarMenuPrincipal();
        //
        void mostrarMenuClientes();
        void opcionesMenuClientes();
        void ejecutarMenuClientes();
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
