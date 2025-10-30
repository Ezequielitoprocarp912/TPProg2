#pragma once
#include "clsFecha.h"

class clsPersona
{
    private:
    ///ATRIBUTOS
        char _cuit[12];
        char _nombre[21];
        char _apellido[21];
        char _direccion [51];

    public:
    ///CONSTRUCTORES
        clsPersona();

    ///SETTERS
        bool setCuit(const char* cuit);
        bool setNombre(const char* nombre);
        bool setApellido(const char* apellido);
        bool setDireccion(const char* direccion);

    ///GETTERS
        const char* getCuit();
        const char* getNombre();
        const char* getApellido();
        const char* getDireccion();
};
