#include <cstdio>
#include <limits>
#include <cstring>

#include "clsGestorCliente.h"
#include "clsGestorVehiculo.h"
#include "clsGestorReparacion.h"

/// CONSTRUCTOR
clsGestorReparacion::clsGestorReparacion()
{
    _rutaDireccion = "Reparacion.dat";
}


/// METODOS DE MANIPULACION
bool clsGestorReparacion::ev(std::string texto, int minimo, int maximo)
{
    if((texto.size()>=minimo)&&(texto.size()<=maximo))
    {
        return true;
    }
    else
    {
        system("cls");
        std::cout << "Entrada invalida. Ingrese nuevamente" << std::endl;
        return false;
    }
}


int clsGestorReparacion::cantidadDeReparaciones()
{
    FILE *p = fopen(_rutaDireccion.c_str(),"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,SEEK_END);
    int cantReparaciones = ftell(p)/sizeof(clsReparacion);
    return cantReparaciones;

}

void clsGestorReparacion::cargarUnaReparacion(clsReparacion &reparacion)
{

    int codRep = cantidadDeReparaciones()+1;
    std::string descripcionFalla;
    std::string cuit;
    std::string numPatente;
    clsCliente cliente;
    clsVehiculo vehiculo;
    clsGestorCliente gestorCliente;
    clsGestorVehiculo gestorVehiculo;

    reparacion.setEstado(true);
    std::cout<<"CODIGO DE REPARACION "<<codRep<<std::endl;
    reparacion.setCodReparacion(codRep);

    std::cin.ignore();



    ///CUIT
    do
    {
        std::cout << "CUIT: ";
        std::getline(std::cin, cuit);
    }
    while(!(ev(cuit, 11, 11)));

    int posCliente = gestorCliente.buscarClientePorCuit(cuit.c_str());

    if(posCliente!=-1)
    {
        cliente = gestorCliente.leerCliente(posCliente);
        reparacion.setCliente(cliente);
    }
    else
    {
        std::cout << "Cliente no encontrado." << std::endl;
        return;
    }


    ///PATENTE
    do
    {
        std::cout << "PATENTE: ";
        std::getline(std::cin, numPatente);
    }
    while(!(ev(numPatente, 6, 7)));

    int posVehiculo = gestorVehiculo.buscarVehiculoPorPatente(numPatente.c_str());

    if(posVehiculo!=-1)
    {
        vehiculo = gestorVehiculo.leerVehiculo(posVehiculo);
        reparacion.setVehiculo(vehiculo);
    }
    else
    {
        std::cout << "Vehiculo no encontrado." << std::endl;
        return;
    }


    ///DESCRIPCION DE LA FALLA
    do
    {
        std::cout << "DESCRIPCION DE LA FALLA: ";
        std::getline(std::cin, descripcionFalla);
    }
    while(!(ev(descripcionFalla, 1, 200)));

    reparacion.setDescripcionFalla(descripcionFalla.c_str());


    int dia,mes,anio;

    std::cout<<"INGRESE LA FECHA DE INGRESO : " <<std::endl;
    std::cout<<"DIA : ";
    std::cin>>dia;
    std::cout<<"MES : ";
    std::cin>>mes;
    std::cout<<"ANIO : ";
    std::cin>>anio;

    clsFecha F_ingreso;
    (dia,mes,anio);
    reparacion.setFechaIngreso(F_ingreso);
}

void clsGestorReparacion::cargarReparacion()
{
    clsReparacion reparacionNueva;

    cargarUnaReparacion(reparacionNueva);
}














