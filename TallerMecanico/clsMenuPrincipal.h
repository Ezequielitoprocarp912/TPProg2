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
    int obtenerOpcion();
    void opcionesMenu(int op);
    void mostrarMenuClientes();
    void mostrarMenuVehiculos();
    void mostrarMenuReparaciones();
    void ejecutarMenuPrincipal();


///CONSTRUCTORES
    clsMenuPrincipal();


};



#endif // CLSMENUPRINCIPAL_H_INCLUDED
