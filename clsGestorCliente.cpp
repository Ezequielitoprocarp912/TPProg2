#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>
#include "clsGestorCliente.h"
#include "clsCliente.h"

/// CONSTRUCTOR
/// Guarda la ruta del archivo donde se guardan los registros
clsGestorCliente::clsGestorCliente()
{
    _rutaDireccion = "Cliente.dat";
}

/// MÉTODOS DE MANIPULACIÓN
bool clsGestorCliente::ev(std::string texto, int minimo, int maximo)
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


void clsGestorCliente::cargarUnCliente(clsCliente &cliente)
{
    std::string cuit;
    std::string nombre;
    std::string apellido;
    std::string telefono;
    std::string mail;
    std::string direccion;
    std::string tipoCliente;


    std::cin.ignore();

    ///CUIT
    do
    {
        std::cout << "CUIT: ";
        std::getline(std::cin, cuit);
    }
    while(!(ev(cuit, 11, 11)));

    cliente.setCuit(cuit.c_str());

    ///NOMBRE
    do
    {
        std::cout << "NOMBRE: ";
        std::getline(std::cin, nombre);
    }
    while(!(ev(nombre, 1, 20)));

    cliente.setNombre(nombre.c_str());

    ///APELLIDO
    do
    {
        std::cout << "APELLIDO: ";
        std::getline(std::cin, apellido);
    }
    while(!(ev(apellido, 1, 20)));

    cliente.setApellido(apellido.c_str());


    ///TELEFONO
    do
    {
        std::cout << "NUM TELEFONO : ";
        std::getline(std::cin, telefono);
    }
    while(!(ev(telefono, 1, 20)));

    cliente.setNumTelefono(telefono.c_str());


    ///MAIL
    do
    {
        std::cout << "MAIL : ";
        std::getline(std::cin, mail);
    }
    while(!(ev(mail, 1, 50)));

    cliente.setMail(mail.c_str());


    ///DIRECCION
    do
    {
        std::cout << "DIRECCION : ";
        std::getline(std::cin, direccion);
    }
    while(!(ev(direccion, 1, 50)));

    cliente.setDireccion(mail.c_str());


    ///TIPO DE CLIENTE
    char tipo;

    do
    {
        std::cout << "Seleccione tipo (1 Particular --- 2 Empresa): ";
        std::getline(std::cin, tipoCliente);
    }
    while(!(ev(tipoCliente, 1, 1)) || (tipoCliente != "1" && tipoCliente != "2"));

    tipo=tipoCliente[0];
    cliente.setTipoCliente(tipo);

    cliente.setEstado(true);
}


/// ESTE METODO MUESTRA LOS DATOS DE LOS CLIENTES
void clsGestorCliente::mostrarUnCliente(clsCliente cliente)
{
    std::cout << "CUIT: " << cliente.getCuit() << std::endl;
    std::cout << "NOMBRE: " << cliente.getNombre() << std::endl;
    std::cout << "APELLIDO: " << cliente.getApellido() << std::endl;
    std::cout << "TELEFONO: " << cliente.getNumTelefono() << std::endl;
    std::cout << "MAIL: " << cliente.getMail() << std::endl;
    std::cout << "DIRECCION: " << cliente.getDireccion() << std::endl;
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
    char opcion;
    char cuit[20];

    std::cout << "CUIT del cliente a modificar: ";
    std::cin >> cuit;

    int pos;
    pos=buscarClientePorCuit(cuit);

    if (pos !=-1)
    {
        clsCliente cliente = leerCliente(pos);

        std::cout << "DATOS ACTUALES: " << std::endl;
        std::cout << std::endl;

        mostrarUnCliente(cliente);

        system("pause");

        std::cout << "\n 1) Nombre\n 2) Apellido\n 3) Mail\n 4) Telefono\n 5) Direccion\n 6) Tipo de cliente\n " << std::endl;
        std::cout << "Ingrese opcion de dato a cambiar: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch(opcion)
        {
        case '1':
        {
            std::string nombre;
            do
            {
                std::cout << "NOMBRE: ";
                std::getline(std::cin, nombre);
            }
            while(!(ev(nombre, 1, 20)));

            cliente.setNombre(nombre.c_str());
        }
        break;

        case '2':
        {
            std::string apellido;
            do
            {
                std::cout << "APELLIDO: ";
                std::getline(std::cin, apellido);
            }
            while(!(ev(apellido, 1, 20)));

            cliente.setApellido(apellido.c_str());
        }
        break;

        case '3':
        {
            std::string mail;
            do
            {
                std::cout << "MAIL : ";
                std::getline(std::cin, mail);
            }
            while(!(ev(mail, 1, 50)));

            cliente.setMail(mail.c_str());
        }
        break;

        case '4':
        {
            std::string telefono;
            do
            {
                std::cout << "NUM TELEFONO : ";
                std::getline(std::cin, telefono);
            }
            while(!(ev(telefono, 1, 20)));

            cliente.setNumTelefono(telefono.c_str());
        }
        break;


        case '5':
        {
            std::string direccion;
            do
            {
                std::cout << "DIRECCION : ";
                std::getline(std::cin, direccion);
            }
            while(!(ev(direccion, 1, 50)));

            cliente.setDireccion(direccion.c_str());
        }
        break;

        case '6':
        {
            char tipo;
            std::string tipoCliente;
            do
            {
                std::cout << "Seleccione tipo (1 Particular --- 2 Empresa): ";
                std::getline(std::cin, tipoCliente);
            }
            while(!(ev(tipoCliente, 1, 1)) || (tipoCliente != "1" && tipoCliente != "2"));

            tipo=tipoCliente[0];
            cliente.setTipoCliente(tipo);
        }

        break;
        }


        ///EDITA EL VEHICULO EN SU POSICION CORRESPONDIENTE
        if (guardarEnDiscoCliente(cliente, pos))
        {
            std::cout << "CLIENTE MODIFICADO CORRECTAMENTE" << std::endl;
        }
        else
        {
            std::cout << "ERROR: NO SE PUDO MODIFICAR EL CLIENTE" << std::endl;
        }
    }

    else
    {
        std::cout << "ERROR: CLIENTE NO ENCONTRADO" << std::endl;
        return;
    }
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


int obtenerCantidadReg (std::string pfile, clsCliente obj)
{
    FILE *p = fopen(pfile.c_str(), "rb");
    if (p == NULL)
    {
        std::cout << "No hay datos cargados actualmente.";
        return 0;
    }

    int cont = 0;
    while (fread(&obj, sizeof(clsCliente), 1, p))
    {
        if (obj.getEstado())
        {
            cont++;
        }
    }

    fclose(p);

    return cont;
}

/*void clsGestorCliente::mostrarTodosxCUIT()
{
    //int contClientes = 0;

    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL)
    {
        std::cout << "No hay clientes cargados actualmente.";
        return;
    }


    clsCliente c;
    int cantidad = obtenerCantidadReg("Clientes.dat", c);

    if (cantidad > 0)
    {
        clsCliente *vecClientes = new clsCliente[cantidad];
    }
    else
    {
        std::cout << "No hay clientes cargados actualmente." << std::endl;
    }



    ///GRABO EN EL VECTOR LOS CLIENTES
    rewind(p);
    int i = 0;
    while (fread(&cliente, sizeof(clsCliente), 1, p))
    {
        if (cliente.getEstado())
        {
            vecClientes[i]=cliente;
            i++;
        }
    }

    fclose(p);
    delete [] vecClientes;
}*/

void clsGestorCliente::mostrarTodosxCUIT()
{
    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL)
    {
        std::cout << "No hay clientes cargados actualmente." << std::endl;
        return;
    }

    clsCliente c;
    int cantidad = obtenerCantidadReg("Clientes.dat", c);

    if (cantidad <= 0)
    {
        std::cout << "No hay clientes cargados actualmente." << std::endl;
        fclose(p);
        return;
    }

    // Declarar el puntero antes del if
    clsCliente *vecClientes = new clsCliente[cantidad];

    // Cargar los clientes activos en el vector
    rewind(p);
    int i = 0;
    while (fread(&cliente, sizeof(clsCliente), 1, p))
    {
        if (cliente.getEstado())
        {
            vecClientes[i] = cliente;
            i++;
        }
    }
    fclose(p);

    // Si no hay clientes activos
    if (i == 0)
    {
        std::cout << "No hay clientes activos actualmente." << std::endl;
        delete[] vecClientes;
        return;
    }

    // Ordenar por CUIT (ascendente)
    for (int a = 0; a < i - 1; a++)
    {
        for (int b = a + 1; b < i; b++)
        {
            if (vecClientes[a].getCuit() > vecClientes[b].getCuit())
            {
                clsCliente aux = vecClientes[a];
                vecClientes[a] = vecClientes[b];
                vecClientes[b] = aux;
            }
        }
    }


    // Mostrar los clientes
    std::cout << "=== CLIENTES ORDENADOS POR CUIT (MENOR A MAYOR) ===" << std::endl;
    for (int j = 0; j < i; j++)
    {
        mostrarUnCliente(vecClientes[j]);
        std::cout << std::endl;
    }

    delete[] vecClientes;
}

