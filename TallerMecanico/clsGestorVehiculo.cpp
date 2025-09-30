#include "clsGestorVehiculo.h"
#include <iostream>
#include <cstring>
#include <string> /// c_srt()
#include <cstdio>

clsGestorVehiculo::clsGestorVehiculo()
{
    _rutaDireccion = "Vehiculo.dat";
}

void clsGestorVehiculo::cargarUnVehiculo(clsVehiculo &vehiculo)
{
    char numPatente[8], descripcionFalla[100], marca[20];
    char tipoVehiculo;
    clsFecha ingreso;
    int dia, mes, anio;

    std::cout << "PATENTE: ";
    std::cin.getline(numPatente, 8);

    //std::cout << "DESCRIPCION FALLA: ";
    //std::cin.getline(descripcionFalla, 100);

    std::cout << "MARCA: ";
    std::cin.getline(marca, 20);

    std::cout << "DIA: ";
    std::cin >> dia;
    ingreso.setDia(dia);
    std::cout << "MES: ";
    std::cin >> mes;
    ingreso.setMes(mes);
    std::cout << "ANIO: ";
    std::cin >> anio;
    ingreso.setAnio(anio);

    //std::cout << "TIPO(1 - auto, 2 - camioneta, 3 - camion, 4 - transporte): ";
    //std::cin >> tipoVehiculo;

    vehiculo.setNumeroPatente(numPatente);
    //vehiculo.setFalla(descripcionFalla);
    vehiculo.setMarca(marca);
    vehiculo.setIngreso(ingreso);
    vehiculo.setTipoVehiculo(tipoVehiculo);
}

void clsGestorVehiculo::mostrarUnVehiculo(clsVehiculo vehiculo)
{
    std::cout << "PATENTE: " << vehiculo.getNumeroPatente() << std::endl;
    //std::cout << "DESCRIPCION: " << vehiculo.getDescripcion() << std::endl;
    std::cout << "MARCA: " << vehiculo.getMarca() << std::endl;
    std::cout << "FECHA INGRESO: " << vehiculo.getIngreso() << std::endl;
    //std::cout << "TIPO: " << vehiculo.getTipoVehiculo() << std::endl;
}
