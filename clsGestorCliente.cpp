#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>
#include "clsGestorCliente.h"
#include "clsCliente.h"

/// CONSTRUCTOR           /// /// Guarda la ruta del archivo donde se guardan los registros
clsGestorCliente::clsGestorCliente()
{
    _rutaDireccion = "Cliente.dat";
}

/// MÉTODOS DE MANIPULACIÓN /// este metodo pide al usuario un cliente y utiliza los setters para validar y guardar
void clsGestorCliente::cargarUnCliente(clsCliente &cliente)
{
    char cuit[21], nombre[21], apellido[21], telefono[21], mail[51], direccion[51];
    char tipoCliente;
    bool entradaValida;

    std::cin.ignore();

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
        entradaValida = cliente.setCuit(cuit);
    }


    entradaValida = false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "NOMBRE: ";
        std::cin.getline(nombre, 21);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Demasiados caracteres, intente nuevamente" << std::endl;
            system("pause");
            continue;
        }

        entradaValida = cliente.setNombre(nombre);
    }


    entradaValida = false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "APELLIDO: ";
        std::cin.getline(apellido, 21);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Demasiados caracteres, intente nuevamente" << std::endl;
            system("pause");
            continue;
        }

        entradaValida = cliente.setApellido(apellido);
    }


    entradaValida = false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "TELÉFONO: ";
        std::cin.getline(telefono, 21);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Demasiados caracteres, intente nuevamente" << std::endl;
            system("pause");
            continue;
        }

        entradaValida = cliente.setNumTelefono(telefono);
    }


    entradaValida = false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "MAIL: ";
        std::cin.getline(mail, 51);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Demasiados caracteres, intente nuevamente" << std::endl;
            system("pause");
            continue;
        }

        entradaValida = cliente.setMail(mail);
    }


    entradaValida = false;
    while(entradaValida!=true)
    {
        system("cls");
        std::cout << "DIRECCIÓN: ";
        std::cin.getline(direccion, 51);

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Demasiados caracteres, intente nuevamente" << std::endl;
            system("pause");
            continue;
        }

        entradaValida = cliente.setDireccion(direccion);
    }

    entradaValida = false;
    while(entradaValida!=true)
    {
        std::cout << "Seleccione tipo: (1 Particular --- 2 Empresa) ";
        std::cin >> tipoCliente;
        entradaValida = cliente.setTipoCliente(tipoCliente);
    }

    cliente.setEstado(true);
}


/// ESTE METODO MUESTRA LOS DATOS DE LOS CLIENTES
void clsGestorCliente::mostrarUnCliente(clsCliente cliente)
{
    std::cout << "CUIT: " << cliente.getCuit() << std::endl;
    std::cout << "NOMBRE: " << cliente.getNombre() << std::endl;
    std::cout << "APELLIDO: " << cliente.getApellido() << std::endl;
    std::cout << "TELÉFONO: " << cliente.getNumTelefono() << std::endl;
    std::cout << "MAIL: " << cliente.getMail() << std::endl;
    std::cout << "DIRECCIÓN: " << cliente.getDireccion() << std::endl;
    std::cout << "TIPO DE CLIENTE: " << (cliente.getTipoCliente() == '1' ? "Particular" : "Empresa") << std::endl; /// operador ternario
    std::cout << "-----------------------------------";
    std::cout << std::endl;
}

/// abre el archivo utilizando ab+ escribe registro final
bool clsGestorCliente::guardarEnDiscoCliente(clsCliente cliente)
{
    FILE *p = fopen(_rutaDireccion.c_str(), "ab+");
    if (p == NULL) return false;
    bool ok = fwrite(&cliente, sizeof(clsCliente), 1, p);
    fclose(p);
    return ok;
}
/// sobrescribe un registro existente en una pos especifica seek
bool clsGestorCliente::guardarEnDiscoCliente(clsCliente cliente, int pos)
{
    FILE *p = fopen(_rutaDireccion.c_str(), "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(clsCliente) * pos, SEEK_SET);
    bool ok = fwrite(&cliente, sizeof(clsCliente), 1, p);
    fclose(p);
    return ok;
}
/// recorre el archivo buscando un cliente
int clsGestorCliente::buscarClientePorCuit(const char *cuit)
{
    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL) return -1;

    int i = 0;
    while (fread(&cliente, sizeof(clsCliente), 1, p))
    {
        if (strcmp(cliente.getCuit(), cuit) == 0)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
/// lee un cliente en una pos especifica
clsCliente clsGestorCliente::leerCliente(int pos)
{
    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL) exit(1);
    fseek(p, sizeof(clsCliente) * pos, SEEK_SET);
    fread(&cliente, sizeof(clsCliente), 1, p);
    fclose(p);
    return cliente;
}

/// EJECUCIÓN DE OPCIONES DE MENU
void clsGestorCliente::cargarCliente()
{
    clsCliente nuevo;
    cargarUnCliente(nuevo);

    if (buscarClientePorCuit(nuevo.getCuit()) != -1)
    {
        std::cout << "ERROR: El Cliente ya existe";
        return;
    }

    if (guardarEnDiscoCliente(nuevo))
        std::cout << "Cliente guardado exitosamente";
    else
        std::cout << "ERROR: No se pudo guardar el cliente";
}

void clsGestorCliente::modificarCliente()
{
    char cuit[20];
    std::cout << "CUIT del cliente a modificar: ";
    std::cin >> cuit;

    int pos = buscarClientePorCuit(cuit);
    if (pos == -1)
    {
        std::cout << "ERROR: Cliente no encontrado";
        return;
    }

    clsCliente cliente = leerCliente(pos);
    std::cout << "DATOS ACTUALES:\n";
    mostrarUnCliente(cliente);

    system("pause");

    std::cout << "INGRESE NUEVOS DATOS:\n";
    cargarUnCliente(cliente);

    if (guardarEnDiscoCliente(cliente, pos))
        std::cout << "Cliente modificado correctamente.";
    else
        std::cout << "ERROR al modificar cliente.";
}

void clsGestorCliente::mostrarTodos()
{
    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL)
    {
        std::cout << "No hay clientes cargados actualmente.";
        return;
    }

    while (fread(&cliente, sizeof(clsCliente), 1, p))
    {
        if (cliente.getEstado())
            mostrarUnCliente(cliente);
    }
    fclose(p);
}

void clsGestorCliente::bajaCliente()
{
    char cuit[20];
    std::cout << "Ingrese el CUIT del cliente a eliminar: ";
    std::cin >> cuit;

    int pos = buscarClientePorCuit(cuit);
    if (pos == -1)
    {
        std::cout << "ERROR: Cliente no encontrado.";
        return;
    }

    clsCliente cliente = leerCliente(pos);
    cliente.setEstado(false);
    guardarEnDiscoCliente(cliente, pos);

    std::cout << "Cliente dado de baja correctamente.";
}

void clsGestorCliente::buscarCliente()
{
    char cuit[20];
    std::cout << "Ingrese el CUIT del cliente a buscar: ";
    std::cin >> cuit;

    int pos = buscarClientePorCuit(cuit);
    if (pos == -1)
    {
        std::cout << "Cliente inexistente.";
        return;
    }

    clsCliente cliente = leerCliente(pos);
    if (cliente.getEstado())
        mostrarUnCliente(cliente);
    else
        std::cout << "El cliente está dado de baja o inactivo";
}
