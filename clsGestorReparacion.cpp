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

int clsGestorReparacion::cantidadDeReparaciones(){
    FILE *p = fopen(_rutaDireccion.c_str(),"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    int cantReparaciones = ftell(p)/sizeof(clsReparacion);
    return cantReparaciones;

}

void clsGestorReparacion::cargarUnaReparacion(clsReparacion &objRep){

    int codRep = cantidadDeReparaciones()+1;
    char descripcionFalla[200],cuit[12],numPatente[8];
    clsCliente objCliente;
    clsVehiculo objVeh;
    clsGestorCliente gesCliente;
    clsGestorVehiculo gesVehiculo;

    objRep.setEstado(true);
    std::cout<<"CODIGO DE REPARACION "<<codRep<<std::endl;
    objRep.setCodReparacion(codRep);

    std::cin.ignore();

    bool entradaValida=false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "DESCRIPCION DE LA FALLA: ";
        std::cin.getline(descripcionFalla, 200);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Demasiados caracteres, intente nuevamente" << std::endl;
            system("pause");
            continue;
        }
        else{

            entradaValida = true;
            objRep.setDescripcionFalla(descripcionFalla);

        }
    }

    entradaValida=false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "CUIT: ";
        std::cin.getline(cuit, 21);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Demasiados caracteres, intente nuevamente" << std::endl;
            system("pause");
            continue;
        }
        entradaValida = objCliente.setCuit(cuit);
    }

    int posCliente = gesCliente.buscarClientePorCuit(cuit);
    objCliente = gesCliente.leerCliente(posCliente);
    objRep.setCliente(objCliente);

    entradaValida=false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "PATENTE: ";
        std::cin.getline(numPatente, 8);

        if(std::cin.fail()) /// BANDERA DE ERROR SI HAY OVERFLOW
        {
            std::cin.clear(); /// LIMPIA LA BANDERA DE ERROR
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /// LIMPIA TODOS LOS CARACTERES HASTA EL TERMINADOR
            std::cout << "Demasiados ca racteres, intente nuevamente" << std::endl;
            system("pause");
            continue; /// VUELVE AL BUCLE HASTA QUE RECIBA ALGO VALIDO
        }

        entradaValida = objVeh.setNumeroPatente(numPatente);
    }
    int posVehiculo = gesVehiculo.buscarVehiculoPorPatente(numPatente);
    objVeh = gesVehiculo.leerVehiculo(posVehiculo);
    objRep.setVehiculo(objVeh);

    int dia,mes,anio;

    std::cout<<"INGRESE LA FECHA DE INGRESO : "<<std::endl;
    std::cout<<"DIA : ";
    std::cin>>dia;
    std::cout<<"MES : ";
    std::cin>>mes;
    std::cout<<"ANIO : ";
    std::cin>>anio;

    clsFecha F_ingreso;(dia,mes,anio);
    objRep.setFechaIngreso(F_ingreso);
}














