#include "clsMenuPrincipal.h"
#include <iostream>

///CONSTRUCTORES
clsMenuPrincipal::clsMenuPrincipal()
{
    _salir=false;
}

///METODOS
void clsMenuPrincipal::mostrar()
{
    std::cout << "==== TALLER MECANICO PACHECO ====" << std::endl;
    std::cout << "1-Menu Clientes" << std::endl;
    std::cout << "2-Menu Vehiculos" << std::endl;
    std::cout << "3-Menu Reparaciones" << std::endl;
    std::cout << "9 === SALIR DEL MANU ===" << std::endl;
}

void clsMenuPrincipal::obtenerOpcion()
{
    std::cout << "INGRESE OPCION: ";
    std::cin >> _opcion;
}

void clsMenuPrincipal::opcionesMenu()
{
    switch(_opcion)
    {
    case 1:

        break;

    case 2: ///MENU VEHICULOS
        break;

    case 3: ///MENU REPARACIONES
        break;

    case 9:
        _salir=true;
        break;

    default:
        std::cout << "Error, ingrese una opcion valida" << std::endl;
    }
}

void clsMenuPrincipal::mostrarMenuClientes()
{
    std::cout << "=== MENU CLIENTES ===" << std::endl;
    std::cout << "1-Cargar cliente" << std::endl;
    std::cout << "2-Modificar cliente" << std::endl;
    std::cout << "3-Baja cliente" << std::endl;
    std::cout << "4-Mostrar todos los clientes" << std::endl;
    std::cout << "5-Buscar por CUIT" << std::endl;
    std::cout << "0 === VOLVER ===" << std::endl;
}

void clsMenuPrincipal::mostrarMenuVehiculos()
{
    std::cout << "=== MENU VEHICULOS ===" << std::endl;
    std::cout << "1-Cargar vehiculo" << std::endl;
    std::cout << "2-Modificar vehiculo" << std::endl;
    std::cout << "3-Baja vehiculo" << std::endl;
    std::cout << "4-Mostrar todos los vehiculos" << std::endl;
    std::cout << "5-Buscar por PATENTE" << std::endl;
    std::cout << "0 === VOLVER ===" << std::endl;
}

void clsMenuPrincipal::mostrarMenuReparaciones()
{
    std::cout << "=== MENU REPARACIONES ===" << std::endl;
    std::cout << "1-Cargar reparacion" << std::endl;
    std::cout << "2-Mostrar reparacion por codigo de reparacion" << std::endl;
    std::cout << "3-Mostrar todas las reparaciones activas" << std::endl;
    std::cout << "0 === VOLVER ===" << std::endl;
}



