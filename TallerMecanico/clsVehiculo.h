#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

class clsVehiculo
{
    private:
    ///ATRIBUTOS
        char _numPatente[8];
        char _marca [20];
        char _modelo [20];
        char _tipoVehiculo ;
        bool _estado;

    public:
    ///CONSTRUCTORES
        clsVehiculo();

    ///SETTERS
        bool setNumeroPatente (const char* numPatente);
        bool setMarca (const char* marca);
        bool setModelo (const char* modelo);
        bool setTipoVehiculo (char tipoVehiculo);
        void setEstado(bool estado);

    ///GETTERS
        const char* getNumeroPatente();
        const char* getMarca();
        const char* getModelo();
        char getTipoVehiculo();
        bool getEstado();
};
