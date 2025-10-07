#include "clsGestorVehiculo.h"
#include <iostream>
#include <cstring>
#include <string> /// c_srt()
#include <cstdio>

clsGestorVehiculo::clsGestorVehiculo() {_rutaDireccion = "Vehiculo.dat";}

void clsGestorVehiculo::cargarUnVehiculo(clsVehiculo &vehiculo)
{
    char numPatente[8];
    char marca[20];
    char tipoVehiculo;
    clsFecha ingreso;
    int dia, mes, anio;

    std::cout << "PATENTE: ";
    std::cin >> numPatente;

    std::cout << "MARCA: ";
    std::cin >> marca;

    std::cout << "DIA: ";
    std::cin >> dia;

    ingreso.setDia(dia);

    std::cout << "MES: ";
    std::cin >> mes;
    ingreso.setMes(mes);

    std::cout << "ANIO: ";
    std::cin >> anio;
    ingreso.setAnio(anio);

    std::cout << "TIPO(1 - auto, 2 - camioneta, 3 - camion, 4 - transporte): ";
    std::cin >> tipoVehiculo;

    vehiculo.setNumeroPatente(numPatente);
    vehiculo.setMarca(marca);
    vehiculo.setIngreso(ingreso);
    vehiculo.setTipoVehiculo(tipoVehiculo);
}

void clsGestorVehiculo::mostrarUnVehiculo(clsVehiculo vehiculo)
{
    std::cout << "PATENTE: " << vehiculo.getNumeroPatente() << std::endl;
    std::cout << "MARCA: " << vehiculo.getMarca() << std::endl;
    std::cout << "FECHA INGRESO: " << vehiculo.getIngreso() << std::endl;
    std::cout << "TIPO: ";
    switch(vehiculo.getTipoVehiculo())
    {
    case '1':
        std::cout << "AUTO" << std::endl;
        break;
    case '2':
        std::cout << "CAMIONETA" << std::endl;
        break;
    case '3':
        std::cout << "CAMION" << std::endl;
        break;
    case '4':
        std::cout << "TRANSPORTE" << std::endl;
        break;
    default:
        std::cout << "AUTO" << std::endl;
    }
    std::cout << std::endl << std::endl;
}

bool clsGestorVehiculo::guardarEnDiscoVehiculo(clsVehiculo registro)
{
    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "ab+");

    if(file==NULL){exit(1);}

    bool grabar = fwrite(&registro, sizeof(clsVehiculo), 1, file);
    fclose(file);
    return grabar;
}

bool clsGestorVehiculo::guardarEnDiscoVehiculo(clsVehiculo registro, int posicion)
{
    bool grabar;
    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb+");

    if(file==NULL){exit(1);}

    fseek(file, sizeof(clsVehiculo)*posicion, SEEK_SET);
    grabar = fwrite(&registro, sizeof(clsVehiculo), 1, file);
    fclose(file);
    return grabar;
}

void clsGestorVehiculo::listarTodosLosVehiculos()
{
    clsVehiculo registro;

    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL){exit(1);}

    while(fread(&registro, sizeof(clsVehiculo), 1, file))
    mostrarUnVehiculo(registro);
    fclose(file);
}

int clsGestorVehiculo::buscarVehiculoPorPatente(const char* patente){
    int posicion;
    clsVehiculo registro;
    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL){exit(1);}

    int i=0;
    while(fread(&registro, sizeof(clsVehiculo), 1, file))
    {
        if(registro.getNumeroPatente()==patente)
        {
            posicion = i;
            fclose(file);
            return posicion;
        }
        i++;
    }

    fclose(file);
    return -1;
}

clsVehiculo clsGestorVehiculo::leerVehiculo(int posicion){
    clsVehiculo registro;
    FILE *file;
    ///
    file = fopen(_rutaDireccion.c_str(),"rb");

    if(file == NULL){exit(1);}

    /// ME POSICIONO EL CURSOR EN EL REGISTRO EXACTO
    fseek(file, sizeof(clsVehiculo)*posicion, SEEK_SET);
    fread(&registro, sizeof(clsVehiculo), 1, file);
    /// CIERRO ARCHIVO
    fclose(file);
    return registro;
}

void clsGestorVehiculo::modificarVehiculoPorPatente()
{
    char patente[8];
    std::cout << "PATENTE: ";
    std::cin >> patente;

    int posicion = buscarVehiculoPorPatente(patente);
    if (posicion == -1) {
        std::cout << "ERROR: VEHICULO NO ENCONTRADO" << std::endl;
        return;
    }

    clsVehiculo vehiculo = leerVehiculo(posicion);

    std::cout << "DATOS ACTUALES: " << std::endl;
    mostrarUnVehiculo(vehiculo);

    std::cout << "DATOS NUEVOS: " << std::endl;
    cargarUnVehiculo(vehiculo);

    // Reemplazar el vehiculo en la posicion
    if (guardarEnDiscoVehiculo(vehiculo, posicion)) {std::cout << "VEHICULO MODIFICADO CORRECTAMENTE" << std::endl;}
    else {std::cout << "ERROR: NO SE PUDO MODIFICAR VEHICULO" << std::endl;}
}
