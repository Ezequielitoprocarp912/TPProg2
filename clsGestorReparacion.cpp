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


/// METODOS DE MANIPULACION EV
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
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL)
    {
        return -1;
    }

    fseek(p, 0, SEEK_END);
    int cantReparaciones = ftell(p) / sizeof(clsReparacion);
    fclose(p);

    return cantReparaciones;
}




bool clsGestorReparacion::cargarUnaReparacion(clsReparacion &reparacion)
{
    int cant = cantidadDeReparaciones();
    int codRep;

    if (cant == -1)
    {
        codRep = 1;
    }
    else
    {
        codRep = cant + 1;
    }

    reparacion.setCodReparacion(codRep);
    reparacion.setEstado(true);

    std::string cuit, numPatente, descripcionFalla;
    clsCliente cliente;
    clsVehiculo vehiculo;
    clsGestorCliente gestorCliente;
    clsGestorVehiculo gestorVehiculo;

    std::cin.ignore();

    // CUIT
    do {
        std::cout << "CUIT: ";
        std::getline(std::cin, cuit);
    } while (!ev(cuit, 11, 11));

    int posCliente = gestorCliente.buscarClientePorCuit(cuit.c_str());
    if (posCliente == -1) {
        std::cout << "Cliente no encontrado.\n";
        return false;
    }

    cliente = gestorCliente.leerCliente(posCliente);
    reparacion.setCliente(cliente);

    // PATENTE
    do {
        std::cout << "PATENTE: ";
        std::getline(std::cin, numPatente);
    } while (!ev(numPatente, 6, 7));

    int posVehiculo = gestorVehiculo.buscarVehiculoPorPatente(numPatente.c_str());
    if (posVehiculo == -1) {
        std::cout << "Vehiculo no encontrado.\n";
        return false;
    }

    vehiculo = gestorVehiculo.leerVehiculo(posVehiculo);
    reparacion.setVehiculo(vehiculo);

    // DESCRIPCION
    do {
        std::cout << "DESCRIPCION DE LA FALLA: ";
        std::getline(std::cin, descripcionFalla);
    } while (!ev(descripcionFalla, 1, 200));
    reparacion.setDescripcionFalla(descripcionFalla.c_str());


    /// FECHA Y VALIDACIONES
    clsFecha F_ingreso;
    bool fechaValida = false;
    std::string diaStr, mesStr, anioStr;
    int dia = 0, mes = 0, anio = 0;

    while (!fechaValida)
    {
        system("cls");
        std::cout << "=== INGRESE LA FECHA DE INGRESO ===" << std::endl;

        // DIA
        bool diaOk = false;
        do
        {
            std::cout << "Dia: ";
            std::getline(std::cin, diaStr);

            if (!ev(diaStr, 1, 2)) continue;

            dia = atoi(diaStr.c_str());
            if (dia >= 1 && dia <= 31)
            {
                diaOk = true;
            }
            else
            {
                system("cls");
                std::cout << "Dia invalido. Ingrese nuevamente." << std::endl;
            }

        } while (!diaOk);

        // MES
        bool mesOk = false;
        do
        {
            std::cout << "Mes: ";
            std::getline(std::cin, mesStr);

            if (!ev(mesStr, 1, 2)) continue;

            mes = atoi(mesStr.c_str());
            if (mes >= 1 && mes <= 12)
            {
                mesOk = true;
            }
            else
            {
                system("cls");
                std::cout << "Mes invalido. Ingrese nuevamente." << std::endl;
            }

        } while (!mesOk);

        // ANIO
        bool anioOk = false;
        do
        {
            std::cout << "Anio: ";
            std::getline(std::cin, anioStr);

            if (!ev(anioStr, 4, 4)) continue;

            anio = atoi(anioStr.c_str());
            if (anio >= 1900 && anio <= 2025)
            {
                anioOk = true;
            }
            else
            {
                system("cls");
                std::cout << "Anio invalido. Ingrese nuevamente." << std::endl;
            }

        } while (!anioOk);

        // VALIDACION COMPLETA (31/2, 29/2, etc.)
        fechaValida = F_ingreso.setFecha(dia, mes, anio);

        if (!fechaValida)
        {
            system("cls");
            std::cout << "La combinacion de fecha es invalida (por ejemplo 31/2 o 29/2 no bisiesto)." << std::endl;
            system("pause");
        }
    }

    reparacion.setFechaIngreso(F_ingreso);
    std::cout << "\nFecha cargada correctamente: " << F_ingreso.mostrar() << std::endl;

    return true;
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

    if (cargarUnaReparacion(reparacionNueva)) {
        guardarEnDiscoReparacion(reparacionNueva);
        std::cout << "Reparacion guardada correctamente.\n";
    } else {
        std::cout << "No se guardó la reparación (faltan datos válidos).\n";
    }
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

///BUSCAR REPARACION POR CODIGO DE REP
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













