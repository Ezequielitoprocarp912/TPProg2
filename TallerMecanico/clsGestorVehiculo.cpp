#include "clsGestorVehiculo.h"

/// CONSTRUCTOR
clsGestorVehiculo::clsGestorVehiculo()
{
    _rutaDireccion = "Vehiculo.dat";
}


///METODOS DE MANIPULACION
void clsGestorVehiculo::cargarUnVehiculo(clsVehiculo &vehiculo)
{
    char numPatente[8];
    char marca[20];
    char modelo[20];
    char tipoVehiculo;
    bool entradaValida;


    std::cin.ignore();
    entradaValida=false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "PATENTE: ";
        std::cin.getline(numPatente, 8);
        entradaValida=vehiculo.setNumeroPatente(numPatente);
    }

    entradaValida=false;
    while(entradaValida!=true)
    {
        std::cout << "MARCA: ";
        std::cin.getline(marca, 20);
        entradaValida=vehiculo.setMarca(marca);
    }

    entradaValida=false;
    while(entradaValida!=true)
    {
        std::cout << "MODELO: ";
        std::cin.getline(modelo, 20);
        entradaValida=vehiculo.setModelo(modelo);
    }

    entradaValida=false;
    while(entradaValida!=true)
    {
        std::cout << "\n 1) Auto\n 2) Camioneta\n 3) Camion\n 4) Transporte\n" << std::endl;
        std::cout << "INGRESE UN NUMERO DE TIPO: ";
        std::cin >> tipoVehiculo;
        entradaValida=vehiculo.setTipoVehiculo(tipoVehiculo);
    }

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
    std::cout << std::endl << std::endl;
}


bool clsGestorVehiculo::guardarEnDiscoVehiculo(clsVehiculo vehiculo)
{
    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "ab+");

    if(file==NULL)
    {
        std::cout << "Direccion no encontrada";
        return false;
    }

    bool grabar = fwrite(&vehiculo, sizeof(clsVehiculo), 1, file);
    fclose(file);
    return grabar;
}


bool clsGestorVehiculo::guardarEnDiscoVehiculo(clsVehiculo vehiculo, int posicion)
{
    bool grabar;
    FILE *file;
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
    file = fopen(_rutaDireccion.c_str(),"rb");

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

    cargarUnVehiculo(vehiculoNuevo);

    if((buscarVehiculoPorPatente(vehiculoNuevo.getNumeroPatente()))!=-1)
    {
        system("cls");
        std::cout << "Error. Vehiculo ya existente." << std::endl;
    }

    check=guardarEnDiscoVehiculo(vehiculoNuevo);

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
    char patente[8];
    std::cout << "Patente de vehiculo a modificar: ";
    std::cin >> patente;

    int pos;
    pos=buscarVehiculoPorPatente(patente);

    if (pos!=-1)
    {
        clsVehiculo vehiculo = leerVehiculo(pos);

        std::cout << "DATOS ACTUALES: " << std::endl;
        mostrarUnVehiculo(vehiculo);

        std::cout << "DATOS NUEVOS: " << std::endl;
        cargarUnVehiculo(vehiculo);

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


void clsGestorVehiculo::mostrarTodos()
{
    clsVehiculo vehiculo;

    FILE *file;
    file = fopen(_rutaDireccion.c_str(), "rb");

    if(file == NULL)
    {
        exit(1);
    }

    while(fread(&vehiculo, sizeof(clsVehiculo), 1, file))
    {
        if(vehiculo.getEstado()==true)
        {
            mostrarUnVehiculo(vehiculo);
        }
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
    char patente[8];
    std::cout << "Patente de vehiculo a buscar: ";
    std::cin >> patente;

    int pos;
    pos=buscarVehiculoPorPatente(patente);

    if (pos!=-1)
    {
        clsVehiculo vehiculo = leerVehiculo(pos);
        mostrarUnVehiculo(vehiculo);
    }
    else
    {
        std::cout << "Error. El vehiculo es inexistente" << std::endl;
    }
}
