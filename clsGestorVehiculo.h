#pragma once
#include "clsVehiculo.h"

class clsGestorVehiculo
{
private:
    std::string _rutaDireccion; /// Guarda la ruta del archivo donde se guardan los registros

public:
    clsGestorVehiculo();

    ///Se ENCARGA DE VALIDAR - NO DEJA NADA EN DISCO + PERO SI EL OBJETO LISTO PARA USAR
    void cargarUnVehiculo(clsVehiculo &vehiculo); // Agregar un nuevo Vehiculo al sistema.
    void mostrarUnVehiculo(clsVehiculo); // Visualizar los datos de un Vehiculo específico por su id.

    /// METODOS DE MANIPULACION
    bool ev(std::string texto, int minimo, int maximo);
    bool guardarEnDiscoVehiculo(clsVehiculo registro);
    bool guardarEnDiscoVehiculo(clsVehiculo registro, int posicion);
    int buscarVehiculoPorPatente(const char*);
    clsVehiculo leerVehiculo(int); /// El entero representa la posicion del registro en el archivo

    ///EJECUCION DE OPCIONES
    /// ESTA CREA UN NUEVO OBJETO VEHICULO VACIO - LLAMA A LA CARGAR DE ARRIBA PARA RELLENARLO
    /// COMPRUEBA SI EXISTE POR PATENTE EN EL ARCHIVO
    /// GUARDA EN DISCO O MUESTRA MENSAJE DE ERROR | EXITO
    ///clsGestorVehiculo gestor;
    ///gestor.cargarVehiculo();
    ///AHI SE MANEJA TODO

    void cargarVehiculo();
    void modificarVehiculo();
    void mostrarTodos();
    void bajaVehiculo();
    void buscarVehiculo();
};


/// **************** PREGUNTAS **********************************
/**
1) POR QUE UNO RECIBE REFERENCIA & Y EL OTRO NO
PORQUE CARGAR UN VEHICULO (&) MODIFICA UN OBJETO EXISTENTE,  QUE SUELE ESTAR VACIO
SI ES LA 1RA VEZ QUE SE USA, YA QUE AL INSTANCIARLO, USA LOS ATRIBUTOS DEL CONSTRUCTOR
Y LUEGO SE PISAN CON LO QUE EL USUARIO INGRESA, DENTRO DE LOS VALORES PERMITIDOS POR LOS SETTERS



CARGAR VEHICULO > NO NECESITA NINGUN PARAMETRO XQ CREA SU PROPIO OBJETO O INSTANCIA DE VEHICULO PARA
LLENARLO CON LA FUNCION CARGAR UN VEHICULO

















*/
