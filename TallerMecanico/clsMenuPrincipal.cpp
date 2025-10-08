#include "clsMenuPrincipal.h"

///CONSTRUCTORES
clsMenuPrincipal::clsMenuPrincipal()
{
    _salir=false;
}

///METODOS MENU PRINCIPAL
void clsMenuPrincipal::mostrar()
{
    system("cls");
    std::cout << "==== TALLER MECANICO PACHECO ====" << std::endl;
    std::cout << "1-Menu Clientes" << std::endl;
    std::cout << "2-Menu Vehiculos" << std::endl;
    std::cout << "3-Menu Reparaciones" << std::endl;
    std::cout << "9 === SALIR DEL MENU ===" << std::endl;
}

void clsMenuPrincipal::elegirOpcion()
{
    std::cout << "INGRESE OPCION: ";
    std::cin >> _opcion;
    std::cout<<std::endl;
}

void clsMenuPrincipal::opcionesMenu()
{
    switch(_opcion)
    {
    case 1:
        ejecutarMenuClientes();
        break;

    case 2:
        ejecutarMenuVehiculos();
        break;

    case 3:
        ejecutarMenuReparaciones();
        break;

    case 9:
        _salir=true;
        break;

    default:
        std::cout << "Error, ingrese una opcion valida" << std::endl;
        system("pause");
    }
}

void clsMenuPrincipal::ejecutarMenuPrincipal()
{
    while(_salir!=true)
    {
        mostrar();
        elegirOpcion();
        opcionesMenu();
    }


}


///METODOS MENU CLIENTES
void clsMenuPrincipal::mostrarMenuClientes()
{
    system("cls");
    std::cout << "=== MENU CLIENTES ===" << std::endl;
    std::cout << "1-Cargar cliente" << std::endl;
    std::cout << "2-Modificar cliente" << std::endl;
    std::cout << "3-Baja cliente" << std::endl;
    std::cout << "4-Mostrar todos los clientes" << std::endl;
    std::cout << "5-Buscar por CUIT" << std::endl;
    std::cout << "0 === VOLVER ===" << std::endl;
}

void clsMenuPrincipal::opcionesMenuClientes()
{
    switch(_opcion)
    {
    case 1:
        ///clsGestorClientes.CargarUnCliente();
        break;

    case 2:
        ///MODIFICAR CLIENTE
        break;

    case 3:
        ///BAJA CLIENTE
        break;

    case 4:
        ///MOSTRAR TODOS LOS CLIENTES
        break;
    case 5:
        ///BUSCAR X CUIT
        break;

    case 0:
        return;
        break;

    default:
        std::cout << "Error, ingrese una opcion valida" << std::endl;
        system("pause");
        break;
    }
}

void clsMenuPrincipal::ejecutarMenuClientes()
{
    mostrarMenuClientes();
    elegirOpcion();
    opcionesMenuClientes();
}

///METODOS MENU VEHICULOS
void clsMenuPrincipal::mostrarMenuVehiculos()
{
    system("cls");
    std::cout << "=== MENU VEHICULOS ===" << std::endl;
    std::cout << "1-Cargar vehiculo" << std::endl;
    std::cout << "2-Modificar vehiculo" << std::endl;
    std::cout << "3-Baja vehiculo" << std::endl;
    std::cout << "4-Mostrar todos los vehiculos" << std::endl;
    std::cout << "5-Buscar por PATENTE" << std::endl;
    std::cout << "0 === VOLVER ===" << std::endl;
}

void clsMenuPrincipal::opcionesMenuVehiculos()
{
    clsGestorVehiculo gestorVehiculos;

    switch(_opcion)
    {

    case 1:
        system("cls");
        gestorVehiculos.cargarVehiculo();
        system("pause");
        break;

    case 2://
        system("cls");
        gestorVehiculos.modificarVehiculo();
        system("pause");
        break;

    case 3:
        ///BAJA VEHICULO
        system("cls");
        gestorVehiculos.bajaVehiculo();        system("pause");
        break;

    case 4:
        system("cls");
        gestorVehiculos.mostrarTodos();
        system("pause");
        break;
    case 5:
        system("cls");
        gestorVehiculos.buscarVehiculo();
        system("pause");
        break;

    case 0:
        return;
        break;

    default:
        std::cout << "Error, ingrese una opcion valida" << std::endl;
        system("pause");
    }
}

void clsMenuPrincipal::ejecutarMenuVehiculos()
{
    mostrarMenuVehiculos();
    elegirOpcion();
    opcionesMenuVehiculos();
}

///METODOS MENU REPARACIONES
void clsMenuPrincipal::mostrarMenuReparaciones()
{
    system("cls");
    std::cout << "=== MENU REPARACIONES ===" << std::endl;
    std::cout << "1-Cargar reparacion" << std::endl;
    std::cout << "2-Mostrar reparacion por codigo de reparacion" << std::endl;
    std::cout << "3-Mostrar todas las reparaciones activas" << std::endl;
    std::cout << "0 === VOLVER ===" << std::endl;
}

void clsMenuPrincipal::opcionesMenuReparaciones()
{
    switch(_opcion)
    {
    case 1:
        ///CARGAR REPARACION
        break;

    case 2:
        ///MOSTRAR REPARACION X COD
        break;

    case 3:
        ///MOSTRAR TODAS
        break;

    case 0:
        return;
        break;

    default:
        std::cout << "Error, ingrese una opcion valida" << std::endl;
        system("pause");
    }
}

void clsMenuPrincipal::ejecutarMenuReparaciones()
{
    mostrarMenuReparaciones();
    elegirOpcion();
    opcionesMenuReparaciones();
}
