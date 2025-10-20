///GESTOR VEHICULO CPP
#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>
#include "clsVehiculo.h"
#include "clsCliente.h"
#include "clsGestorVehiculo.h"

/// CONSTRUCTOR
/// EL ARCHIVO SE CREA EN GUARDAR EN DISCO ( CLS VEHICULO VEHICULO ) AUTOMATICAMENTE EN LA CARPETA DONDE SE EJECUTA EL PROGRAMA
clsGestorVehiculo::clsGestorVehiculo()
{
    _rutaDireccion = "Vehiculo.dat";
}


///METODOS DE MANIPULACION ESTO EVALUA EL RANGO MAXIMO Y MINIMO
bool clsGestorVehiculo::ev(std::string texto, int minimo, int maximo)
{
    /// SE USA SIZE() XQ DEVUELVE LA CANTIDAD DE CARACTERES QUE CONTIENE STD:: STRING SIN CONTAR EL TERMINADOR '\0'
    if( (texto.size()>=minimo)&&(texto.size()<=maximo))
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


void clsGestorVehiculo::cargarUnVehiculo(clsVehiculo &vehiculo)
{
    ///ACA LOS CASTEAMOS TEMPORALMENTE A STRING PARA PODER USAR SIZE Y TENER LA CANTIDAD DE CARACTERES, YA QUE SIZEOF TRABAJA CON BYTES
    std::string numPatente;
    std::string marca;
    std::string modelo;
    std::string tipoVehiculo;

    std::cin.ignore();

    ///PATENTE
    do
    {
        std::cout << "PATENTE: ";
        std::getline(std::cin, numPatente); ///LEE EL TEXTO INCLUIDO EL ESPACIO AAA
    }
    while(!(ev(numPatente, 6, 7)));

    vehiculo.setNumeroPatente(numPatente.c_str());


    ///MARCA
    do
    {
        std::cout << "MARCA: ";
        std::getline(std::cin, marca);
    }
    while(!(ev(marca, 1, 20)));

    vehiculo.setMarca(marca.c_str());


    ///MODELO
    do
    {
        std::cout << "MODELO: ";
        std::getline(std::cin, modelo);
    }
    while(!(ev(modelo, 1, 20)));

    /// ¿ QUE HACE .C_STR ?
    /// CONVIERTE UN STRING EN PUNTERO CONST CHAR *
    vehiculo.setModelo(modelo.c_str());


    ///TIPO DE VEHICULO
    char tipo;
    do
    {
        std::cout << "\n 1) Auto\n 2) Camioneta\n 3) Camion\n 4) Transporte\n" << std::endl;
        std::cout << "INGRESE UN NUMERO DE TIPO: ";
        std::getline(std::cin, tipoVehiculo);
    }
    ///SU LONGITUD TIENE QUE SER 1 SI O SI [ 1 2 3 4 ] SOLO SALE CUANDO AMBAS VALIDACIONES SON CORRECTAS
    while(!(ev(tipoVehiculo, 1, 1)) || (tipoVehiculo != "1" && tipoVehiculo != "2" && tipoVehiculo != "3" && tipoVehiculo != "4"));

    tipo=tipoVehiculo[0]; ///TOMA EL 1ER CARACTER DEL STRING Y LO GUARDA

    vehiculo.setTipoVehiculo(tipo); ///SE ASIGNA AL OBJETO QUE SE USA DESPUES EN EL SWITCH
    vehiculo.setEstado(true);
}


void clsGestorVehiculo::mostrarUnVehiculo(clsVehiculo vehiculo)
{
    std::cout << "PATENTE: " << vehiculo.getNumeroPatente() << std::endl;
    std::cout << "MARCA: " << vehiculo.getMarca() << std::endl;
    std::cout << "MODELO: " << vehiculo.getModelo() << std::endl;

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

    std::cout << "ESTADO: ";
    if (vehiculo.getEstado()==true) {std::cout<< "ACTIVO " <<std::endl;}
    else if (!vehiculo.getEstado()) {std::cout<< "DADO DE BAJA " <<std::endl;}
    std::cout << "-----------------------------------\n";
    std::cout << std::endl << std::endl;
}

/// ACA SE CREA EL ARCHIVO
bool clsGestorVehiculo::guardarEnDiscoVehiculo(clsVehiculo vehiculo)
{
    FILE *file;
    /// AB IGNORA EL FSEEK Y SIEMPRE ESCRIBE AL FINAL ENTONCES NO MODIFICA NADA
    file = fopen(_rutaDireccion.c_str(), "ab+"); /// APPEND ESCRIBE AL FINAL DEL ARCHIVO - SI NO EXISTE LO CREA

    if(file==NULL)
    {
        std::cout << "Direccion no encontrada";
        return false;
    }

    bool grabar = fwrite(&vehiculo, sizeof(clsVehiculo), 1, file);
    fclose(file);
    return grabar;
}

///SOBRESCRIBIR O DAR DE BAJA
bool clsGestorVehiculo::guardarEnDiscoVehiculo(clsVehiculo vehiculo, int posicion)
{
    bool grabar;
    FILE *file;
    /// RB+ PERMITE LEER Y ESCRIBIR NO CREA NADA + EMPIEZA AL PRINCIPIO SIRVE PARA MODIFICAR O DAR DE BAJA
    /// RB HARIA FALLAR AL FWRITE
    file = fopen(_rutaDireccion.c_str(), "rb+");

    if(file==NULL)
    {
        exit(1);
    }

    fseek(file, sizeof(clsVehiculo)*posicion, SEEK_SET);
    grabar = fwrite(&vehiculo, sizeof(clsVehiculo), 1, file);
    fclose(file);
    return grabar;
}


int clsGestorVehiculo::buscarVehiculoPorPatente(const char* patente)
{
    int posicion;
    clsVehiculo vehiculo;
    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL)
    {
        return -1;
    }


    int i=0;
    while(fread(&vehiculo, sizeof(clsVehiculo), 1, file))
    {
        if(strcmp(vehiculo.getNumeroPatente(), patente)==0)
        {
            posicion = i;
            fclose(file);
            return posicion;
        }
        i++;
    }

    fclose(file);
    return -1; /// RETORNA -1 YA QUE NO ENCONTRO LA PATENTE.
}


clsVehiculo clsGestorVehiculo::leerVehiculo(int posicion)
{
    clsVehiculo vehiculo;
    FILE *file;
    ///
    file = fopen(_rutaDireccion.c_str(),"rb"); ///SI PONGO + LO CREA

    if(file == NULL)
    {
        exit(1);
    }

    /// ME POSICIONO EL CURSOR EN EL REGISTRO EXACTO
    fseek(file, sizeof(clsVehiculo)*posicion, SEEK_SET);
    fread(&vehiculo, sizeof(clsVehiculo), 1, file);
    /// CIERRO ARCHIVO
    fclose(file);
    return vehiculo;
}


///EJECUCION DE OPCIONES
void clsGestorVehiculo::cargarVehiculo()
{
    clsVehiculo vehiculoNuevo;
    bool check;

    cargarUnVehiculo(vehiculoNuevo); /// ACA SE LO PASA PARA CARGARLO

    if((buscarVehiculoPorPatente(vehiculoNuevo.getNumeroPatente()))!=-1)
    {
        system("cls");
        std::cout << "Error. Vehiculo ya existente." << std::endl;
        return;
    }


    check=guardarEnDiscoVehiculo(vehiculoNuevo); /// DEVUELVE TRUE O FALSE SI PUDO GUARDAR EN EL DISCO
    if(check==true)
    {
        std::cout << "Vehiculo guardado exitosamente" << std::endl;
    }
    else
    {
        std::cout << "El vehiculo no ha podido ser guardado" << std::endl;
    }
}


void clsGestorVehiculo::modificarVehiculo()
{
    char opcion;
    char patente[8];

    std::cout << "Patente de vehiculo a modificar: ";
    std::cin >> patente;

    int pos;
    pos=buscarVehiculoPorPatente(patente);

    if (pos!=-1)
    {
        clsVehiculo vehiculo = leerVehiculo(pos);

        std::cout << "DATOS ACTUALES: " << std::endl;
        std::cout << std::endl;

        mostrarUnVehiculo(vehiculo);

        /// MINI VALIDACION :)
        if (!vehiculo.getEstado()) {
            std::cout << "El cliente esta dado de baja y no puede modificarse.";
            return;
        }

        system("pause");
        do{
        std::cout << "Ingrese opcion de dato a cambiar: " << std::endl;
        std::cout << "\n 1) Marca\n 2) Modelo\n 3) Tipo\n 0) SALIR \n" << std::endl;
        std::cin >> opcion;
        std::cin.ignore();

        switch(opcion)
        {
        case '1':
        {
            std::string marca;
            do
            {
                std::cout << "MARCA: ";
                std::getline(std::cin, marca);
            }
             while(!(ev(marca, 1, 20)));

            vehiculo.setMarca(marca.c_str());
        }
        break;

        case '2':
        {
            std::string modelo;
            do
            {
                std::cout << "MODELO: ";
                std::getline(std::cin, modelo);
            }
            while(!(ev(modelo, 1, 20)));

            vehiculo.setModelo(modelo.c_str());
        }
        break;

        case '3':
        {
            char tipo;
            std::string tipoVehiculo;
            do
            {
                std::cout << "\n 1) Auto\n 2) Camioneta\n 3) Camion\n 4) Transporte\n" << std::endl;
                std::cout << "INGRESE UN NUMERO DE TIPO: ";
                std::getline(std::cin, tipoVehiculo);
            }
            while(!(ev(tipoVehiculo, 1, 1)) || (tipoVehiculo != "1" && tipoVehiculo != "2" && tipoVehiculo != "3" && tipoVehiculo != "4"));

            tipo=tipoVehiculo[0];

            vehiculo.setTipoVehiculo(tipo);
        }

        case '0': {break;}

        default: system("cls");

        break;
        }
    }while (opcion!='0');

        ///EDITA EL VEHICULO EN SU POSICION CORRESPONDIENTE
        if (guardarEnDiscoVehiculo(vehiculo, pos))
        {
            std::cout << "VEHICULO MODIFICADO CORRECTAMENTE" << std::endl;
        }
        else
        {
            std::cout << "ERROR: NO SE PUDO MODIFICAR VEHICULO" << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: VEHICULO NO ENCONTRADO" << std::endl;
        return;
    }
}

//MUESTRA ACTIVOS E INACTIVOS
void clsGestorVehiculo::mostrarTodos()
{
    clsVehiculo vehiculo;


    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL)
    {
        std::cout << "No hay vehiculos cargados actualmente " << std::endl;
        return;
    }

    while(fread(&vehiculo, sizeof(clsVehiculo), 1, file))
    {
        if( (vehiculo.getEstado()==true) || (!vehiculo.getEstado()) )
        {
            mostrarUnVehiculo(vehiculo);
        }
    }

    fclose(file);
}

void clsGestorVehiculo::mostrar_Activos_Inactivos()
{
    clsVehiculo vehiculo;


    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL)
    {
        std::cout << "No hay vehiculos cargados actualmente " << std::endl;
        return;
    }
    char opcion;
    std::cout<< "1 ACTIVOS - 2 INACTIVOS ";
    std::cin>>opcion;

    while(fread(&vehiculo, sizeof(clsVehiculo), 1, file))
    {
        if( (vehiculo.getEstado()==true && opcion==1) )
        {
            mostrarUnVehiculo(vehiculo);
        }
        else if ( (!vehiculo.getEstado() && opcion==2) ) mostrarUnVehiculo(vehiculo);
    }

    fclose(file);
}


void clsGestorVehiculo::bajaVehiculo()
{
    clsVehiculo vehiculoEliminado;
    char patente[8];

    std::cin.ignore();
    std::cout << "Patente de vehiculo a eliminar: ";
    std::cin.getline(patente, 8);

    int pos;

    pos=buscarVehiculoPorPatente(patente);
    vehiculoEliminado=leerVehiculo(pos);
    vehiculoEliminado.setEstado(false);

    guardarEnDiscoVehiculo(vehiculoEliminado, pos);
}

void clsGestorVehiculo::buscarVehiculo()
{
    clsVehiculo vehiculoBuscado;
    char patente[8];

    std::cin.ignore();
    std::cout << "Patente de vehiculo a buscar: ";
    std::cin.getline(patente, 8);

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Demasiados caracteres, intente nuevamente:" << std::endl;
        return;
    }


    int pos;
    pos=buscarVehiculoPorPatente(patente);

    vehiculoBuscado = leerVehiculo(pos);

    if ((pos!=-1) && (vehiculoBuscado.getEstado() == true))
    {
        mostrarUnVehiculo(vehiculoBuscado);
    }
    else
    {
        std::cout << "Error. El vehiculo es inexistente" << std::endl;
    }
}

/**
1) POR QUE BUSCAR POR PATENTE PREGUNTA SI ES DISTINTO DE -1 PARA SABER SI YA ES EXISTENTE
///EJECUCION DE OPCIONES
void clsGestorVehiculo::cargarVehiculo()
{
    clsVehiculo vehiculoNuevo;
    bool check;

    cargarUnVehiculo(vehiculoNuevo);

    if((buscarVehiculoPorPatente(vehiculoNuevo.getNumeroPatente()))!=-1)
    {
        system("cls");
        std::cout << "Error. Vehiculo ya existente." << std::endl;
        return;
    }



    MIREMOS EL DESARROLLO DE BUSCAR VEHICULO X PATENTE



    int clsGestorVehiculo::buscarVehiculoPorPatente(const char* patente)
{
    int posicion;
    clsVehiculo vehiculo;
    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL)
    {
        return -1;
    }

    int i=0;
    while(fread(&vehiculo, sizeof(clsVehiculo), 1, file))
    {
        if(strcmp(vehiculo.getNumeroPatente(), patente)==0)
        {
            posicion = i;
            fclose(file);
            return posicion;
        }
        i++;
    }

    fclose(file);
    return -1; /// RETORNA -1 YA QUE NO ENCONTRO LA PATENTE.
}

ESTA FUNCION 1RO PIDE UNA PATENTE DE TIPO CHAR, CON SRING COMPARE Y EL GET PATENTE LAS COMPARA, SI ES IGUAL A 0 SON IDENTICAS
ENTONCES SI POSICION ES != -1 ESTA DEVOLVIENDO LA POSICION CORRECTA DEL VEHICULO EN EL ARCHIVO

        SIEZEOF(); DEVUELVE EL TAMAÑO EN BYTES!!!! DEL OBJETO TEXTO, ES DECIR DE LA ESTRUCTURA INTERNA DE STD::STRING
        NO DE SU CONTENIDO!! POR ESO NO SIRVE PARA MEDIR CUANTOS CARACTERTES TIENE EL TEXTO


        std::string palabra = "auto";

std::cout << palabra.size() << std::endl;   // + Imprime 4
std::cout << sizeof(palabra) << std::endl;  // + Imprime algo como 32 (depende del compilador)



*/
