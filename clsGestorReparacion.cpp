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
    std::cout<<"CODIGO DE REPARACION: "<<codRep<<std::endl;
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

    ///FECHA
    int dia,mes,anio;

    std::cout<<"INGRESE LA FECHA DE INGRESO : " <<std::endl;
    std::cout<<"DIA : ";
    std::cin>>dia;
    std::cout<<"MES : ";
    std::cin>>mes;
    std::cout<<"ANIO : ";
    std::cin>>anio;

    clsFecha F_ingreso;
    F_ingreso.setDia(dia);
    F_ingreso.setMes(mes);
    F_ingreso.setAnio(anio);

    reparacion.setFechaIngreso(F_ingreso);
}


void clsGestorReparacion::mostrarUnaReparacion(clsReparacion reparacion)
{
    std::cout << "CODIGO DE REPARACION: " << reparacion.getCodReparacion() << std::endl;
    std::cout << "DESCRIPCION DE FALLA: " << reparacion.getDescripcionFalla() << std::endl;
    std::cout << "CLIENTE: " << reparacion.getCliente().getCuit() << std::endl;
    std::cout << "VEHICULO: " << reparacion.getVehiculo().getNumeroPatente() << std::endl;
    std::cout << "FECHA DE INGRESO: " << reparacion.getFechaIngreso() << std::endl;
    std::cout << "-----------------------------------";
    std::cout << std::endl;
}


///METODOS DE ARCHIVO
bool clsGestorReparacion::guardarEnDiscoReparacion(clsReparacion reparacion)
{
    FILE *p = fopen(_rutaDireccion.c_str(), "ab+");
    if (p == NULL)
    {
        std::cout << "Direccion no encontrada";
        return false;
    }

    bool grabar = fwrite(&reparacion, sizeof(clsReparacion), 1, p);
    fclose(p);
    return grabar;
}


bool clsGestorReparacion::sobreEscribirEnDiscoReparacion(clsReparacion reparacion, int pos)
{
    FILE *p = fopen(_rutaDireccion.c_str(), "rb+");
    if (p == NULL)
    {
        std::cout << "Direccion no encontrada";
        return false;
    }
    fseek(p, sizeof(clsReparacion)*pos, SEEK_SET);
    bool grabar = fwrite(&reparacion, sizeof(clsReparacion), 1, p);
    fclose(p);
    return grabar;
}


int clsGestorReparacion::buscarReparacionPorCod(int codigo)
{
    clsReparacion reparacion;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL) return -1;

    int i = 0;
    while (fread(&reparacion, sizeof(clsReparacion), 1, p))
    {
        if (reparacion.getCodReparacion() == codigo)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}


clsReparacion clsGestorReparacion::leerReparacion(int pos)
{
    clsReparacion reparacion;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL) exit(1);
    fseek(p, sizeof(clsReparacion)*pos, SEEK_SET);
    fread(&reparacion, sizeof(clsReparacion), 1, p);
    fclose(p);
    return reparacion;
}


///METODOS DE EJECUCION
void clsGestorReparacion::cargarReparacion()
{
    clsReparacion reparacionNueva;

    cargarUnaReparacion(reparacionNueva);

    guardarEnDiscoReparacion(reparacionNueva);
}

void clsGestorReparacion::mostrarTodas()
{
    clsReparacion reparacion;

    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL)
    {
        std::cout << "No hay reparaciones cargadas actualmente " << std::endl;
        return;
    }

    while(fread(&reparacion, sizeof(clsReparacion), 1, file))
    {
        if(reparacion.getEstado()==true)
        {
            mostrarUnaReparacion(reparacion);
        }
    }

    fclose(file);
}


void clsGestorReparacion::buscarReparacion()
{
    clsReparacion reparacionBuscada;

    int codReparacion;

    std::cin.ignore();
    std::cout << "Codigo de reparacion a buscar: ";
    std::cin >> codReparacion;


    int pos;
    pos=buscarReparacionPorCod(codReparacion);

    reparacionBuscada = leerReparacion(pos);

    if ((pos!=-1) && (reparacionBuscada.getEstado() == true))
    {
        mostrarUnaReparacion(reparacionBuscada);
    }
    else
    {
        std::cout << "Error. Reparacion inexistente" << std::endl;
    }
}













