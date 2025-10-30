#include <iostream>

#include "rlutil.h"
#include "clsGestorCliente.h"
#include "clsGestorVehiculo.h"
#include "clsGestorReparacion.h"
#include "clsMenuPrincipal.h"

///CONSTRUCTORES
clsMenuPrincipal::clsMenuPrincipal()
{
    _opcion = 0;
    _salir = false;
}

///METODOS MENU PRINCIPAL

void clsMenuPrincipal::mostrar()
{
    //rlutil::cls();
    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(30, 8); std::cout << "TALLER MECANICO PACHECO" << std::endl;
    rlutil::locate(30, 10); std::cout << "CLIENTES" << std::endl;
    rlutil::locate(30, 11); std::cout << "VEHICULOS" << std::endl;
    rlutil::locate(30, 12); std::cout << "REPARACIONES" << std::endl;
    rlutil::locate(30, 13); std::cout << " SALIR" << std::endl;
    rlutil::locate(28, 10 + _opcion); std::cout << (char)175 << std::endl; ///DIBUJAMOS EL CURSOR
}

void clsMenuPrincipal::opcionesMenu()
{
    switch(rlutil::getkey())
    {
        case 14: ///ARRIBA
        {
            rlutil::locate(28, 10 + _opcion); std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion--; ///MOVEMOS EL CURSOR

            if(_opcion < 0){ _opcion = 3; }
        }break;
        case 15: ///ABAJO
        {
            rlutil::locate(28, 10 + _opcion); std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion++; ///MOVEMOS EL CURSOR

            if(_opcion > 3){ _opcion = 0; }
        }break;
        case 1: ///ENTER
        {
            switch(_opcion)
            {
                case 0:
                    rlutil::cls();
                    ejecutarMenuClientes();
                    break;
                case 1:
                    rlutil::cls();
                    ejecutarMenuVehiculos();
                    break;
                case 2:
                    rlutil::cls();
                    ejecutarMenuReparaciones();
                    break;
                case 3:
                    _salir=true;
                    break;
            }break;
        }
    }
}

void clsMenuPrincipal::ejecutarMenuPrincipal()
{
    do{
        mostrar();
        opcionesMenu();

    }while(!_salir);
}


///METODOS MENU CLIENTES
void clsMenuPrincipal::mostrarMenuClientes()
{
    //rlutil::cls();
    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(30, 8); std::cout << "CLIENTES" << std::endl;
    rlutil::locate(30, 10); std::cout << "CARGAR" << std::endl;
    rlutil::locate(30, 11); std::cout << "MODIFICAR" << std::endl;
    rlutil::locate(30, 12); std::cout << "BAJA" << std::endl;
    rlutil::locate(30, 13); std::cout << "MOSTRAR TODOS" << std::endl;
    rlutil::locate(30, 14); std::cout << "BUSCAR" << std::endl;
    rlutil::locate(30, 15); std::cout << " VOLVER" << std::endl;
    rlutil::locate(28, 10 + _opcion); std::cout << (char)175 << std::endl; ///DIBUJAMOS EL CURSOR
}

void clsMenuPrincipal::opcionesMenuClientes()
{
    clsGestorCliente gestorClientes;

    switch(rlutil::getkey())
    {
        case 14: ///ARRIBA
        {
            rlutil::locate(28, 10 + _opcion);
            std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion--; ///MOVEMOS EL CURSOR

            if(_opcion < 0){ _opcion = 5; }
        }break;
        case 15: ///ABAJO
        {
            rlutil::locate(28, 10 + _opcion); std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion++; ///MOVEMOS EL CURSOR

            if(_opcion > 5){ _opcion = 0; }
        }break;
        case 1: ///ENTER
        {
            switch(_opcion)
            {
                case 0:
                    rlutil::cls();
                    gestorClientes.cargarCliente();
                    break;
                case 1:
                    rlutil::cls();
                    gestorClientes.modificarCliente();
                    break;
                case 2:
                    rlutil::cls();
                    gestorClientes.bajaCliente();
                    break;
                case 3:
                    rlutil::cls();
                    gestorClientes.mostrarTodos();
                    break;
                case 4:
                    rlutil::cls();
                    gestorClientes.buscarCliente();
                    break;
                case 5:
                    rlutil::cls();
                    ejecutarMenuPrincipal();
                    break;
            }
        }break;
    }
}

void clsMenuPrincipal::ejecutarMenuClientes()
{
    do{
        mostrarMenuClientes();
        opcionesMenuClientes();
    }while(!_salir);
}

///METODOS MENU VEHICULOS
void clsMenuPrincipal::mostrarMenuVehiculos()
{
    //rlutil::cls();
    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(30, 8); std::cout << "VEHICULOS" << std::endl;
    rlutil::locate(30, 10); std::cout << "CARGAR" << std::endl;
    rlutil::locate(30, 11); std::cout << "MODIFICAR" << std::endl;
    rlutil::locate(30, 12); std::cout << "BAJA" << std::endl;
    rlutil::locate(30, 13); std::cout << "MOSTRAR TODOS" << std::endl;
    rlutil::locate(30, 14); std::cout << "BUSCAR" << std::endl;
    rlutil::locate(30, 15); std::cout << " VOLVER" << std::endl;
    rlutil::locate(28, 10 + _opcion); std::cout << (char)175 << std::endl; ///DIBUJAMOS EL CURSOR
}

void clsMenuPrincipal::opcionesMenuVehiculos()
{
    clsGestorVehiculo gestorVehiculos;

    switch(rlutil::getkey())
    {
        case 14: ///ARRIBA
        {
            rlutil::locate(28, 10 + _opcion);
            std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion--; ///MOVEMOS EL CURSOR

            if(_opcion < 0){ _opcion = 5; }
        }break;
        case 15: ///ABAJO
        {
            rlutil::locate(28, 10 + _opcion); std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion++; ///MOVEMOS EL CURSOR

            if(_opcion > 5){ _opcion = 0; }
        }break;
        case 1: ///ENTER
        {
            switch(_opcion)
            {
                case 0:
                    rlutil::cls();
                    gestorVehiculos.cargarVehiculo();
                    break;
                case 1:
                    rlutil::cls();
                    gestorVehiculos.modificarVehiculo();
                    break;
                case 2:
                    rlutil::cls();
                    gestorVehiculos.bajaVehiculo();
                    break;
                case 3:
                    rlutil::cls();
                    gestorVehiculos.mostrarTodos();
                    break;
                case 4:
                    rlutil::cls();
                    gestorVehiculos.buscarVehiculo();
                    break;
                case 5:
                    rlutil::cls();
                    ejecutarMenuPrincipal();
                    break;
            }
        }break;
    }
}

void clsMenuPrincipal::ejecutarMenuVehiculos()
{
    do{
        mostrarMenuVehiculos();
        opcionesMenuVehiculos();
    }while(!_salir);
}

///METODOS MENU REPARACIONES
void clsMenuPrincipal::mostrarMenuReparaciones()
{
    //rlutil::cls();
    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(30, 8); std::cout << "REPARACIONES" << std::endl;
    rlutil::locate(30, 10); std::cout << "CARGAR" << std::endl;
    rlutil::locate(30, 11); std::cout << "BUSCAR" << std::endl;
    rlutil::locate(30, 12); std::cout << "MOSTRAR ACTIVAS" << std::endl;
    rlutil::locate(30, 13); std::cout << " VOLVER" << std::endl;
    rlutil::locate(28, 10 + _opcion); std::cout << (char)175 << std::endl; ///DIBUJAMOS EL CURSOR
}

void clsMenuPrincipal::opcionesMenuReparaciones()
{
    clsGestorReparacion gestorReparacion;

    switch(rlutil::getkey())
    {
        case 14: ///ARRIBA
        {
            rlutil::locate(28, 10 + _opcion);
            std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion--; ///MOVEMOS EL CURSOR

            if(_opcion < 0){ _opcion = 3; }
        }break;
        case 15: ///ABAJO
        {
            rlutil::locate(28, 10 + _opcion); std::cout << " " << std::endl; ///BORRAMOS EL CURSOR ANTERIOR

            _opcion++; ///MOVEMOS EL CURSOR

            if(_opcion > 3){ _opcion = 0; }
        }break;
        case 1: ///ENTER
        {
            switch(_opcion)
            {
                case 0:
                    rlutil::cls();
                    gestorReparacion.cargarReparacion();
                    break;
                case 1:
                    rlutil::cls();

                    break;
                case 2:
                    rlutil::cls();

                    break;
                case 3:
                    rlutil::cls();
                    ejecutarMenuPrincipal();
                    break;
            }
        }break;
    }
}

void clsMenuPrincipal::ejecutarMenuReparaciones()
{
    do{
        mostrarMenuReparaciones();
        opcionesMenuReparaciones();
    }while(!_salir);
}
