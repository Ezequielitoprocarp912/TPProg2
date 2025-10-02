/*gestor.cpp*/
#include <iostream>
#include <cstring>
#include <string> /// c_srt()
#include <cstdio>
#include "clsCliente.h"
#include "clsGestorClientes.h"
using namespace std;

///CONSTRUCTOR
clsGestorClientes::clsGestorClientes() {_rutaDireccion = "Cliente.dat";}

///METODOS
void clsGestorClientes::CargarUnCliente(clsCliente &cliente)
{
    char cuit[12], nombre[20], apellido[20], telefono[20], mail[50], direccion[50];
    char tipoCliente;
    bool estado;

    std::cout<< "INGRESE CUIT: ";
    std::cin.getline(cuit, 20);

    std::cout<< "INGRESE NOMBRE: ";
    std::cin.getline(nombre, 20);

    std::cout<< "INGRESE APELLIDO: ";
    std::cin.getline(apellido, 20);

    std::cout<< "INGRESE TELEFONO: ";
    std::cin.getline(telefono, 20);

    std::cout<< "INGRESE MAIL: ";
    std::cin.getline(mail, 50);

    std::cout<< "INGRESE DIRECCION: ";
    std::cin.getline(direccion, 50);

    std::cout<< "INGRESE TIPO (1=particular | 2=empresa): ";
    std::cin>> tipoCliente;

    std::cout<< "INGRESE ESTADO (1=activo | 0=inactivo): ";
    std::cin >> estado;
    std::cin.ignore();

    ///USAMOS LOS SETTERS DE clsCliente
    cliente.setCuit(cuit);
    cliente.setNombre(nombre);
    cliente.setApellido(apellido);
    cliente.setNumTelefono(telefono);
    cliente.setMail(mail);
    cliente.setDireccion(direccion);
    cliente.setTipoCliente(tipoCliente);
    cliente.setEstado(estado);



}


void clsGestorClientes::MostrarUnCliente(clsCliente cliente)
{
    std::cout<<"CUIT CLIENTE: " << cliente.getCuit() << std::endl;
    std::cout<<"NOMBRE CLIENTE: " << cliente.getNombre() << std::endl;
    std::cout<<"APELLIDO CLIENTE: " << cliente.getApellido() << std::endl;
    std::cout<<"TELEFONO CLIENTE: " << cliente.getNumTelefono() << std::endl;
    std::cout<<"MAIL CLIENTE: " << cliente.getNumTelefono() << std::endl;
    std::cout<<"DIRECCION CLIENTE: " << cliente.getNumTelefono() << std::endl;
    std::cout<<"TIPO CLIENTE: " << cliente.getTipoCliente() << std::endl;
    std::cout<<"ESTADO CLIENTE: " << cliente.getEstado() << std::endl;
    std::cout<<"\n";
}
