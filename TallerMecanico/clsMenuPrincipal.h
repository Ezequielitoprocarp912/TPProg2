#ifndef CLSMENUPRINCIPAL_H_INCLUDED
#define CLSMENUPRINCIPAL_H_INCLUDED

class clsMenuPrincipal
{

private:
///ATRIBUTOS
    int _opcion;
    bool _salir;

public:
///METODOS
    void mostrar();
    void obtenerOpcion();
    void opcionesMenu();
    void mostrarMenuClientes();
    void mostrarMenuVehiculos();
    void mostrarMenuReparaciones();


///CONSTRUCTORES
    clsMenuPrincipal();


};



#endif // CLSMENUPRINCIPAL_H_INCLUDED
