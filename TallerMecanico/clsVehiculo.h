#ifndef CLSVEHICULO_H_INCLUDED
#define CLSVEHICULO_H_INCLUDED
#include "clsFecha.h"

class clsVehiculo {

private:

///ATRIBUTOS
 char _numPatente[8];
 char _marca [20];
 char _tipoVehiculo ;
 clsFecha _ingreso;

public:

///CONSTRUCTORES
    clsVehiculo();
    clsVehiculo(const char* patente , const char* descFalla , const char* marca , int dia, int mes, int anio, char tipoVehiculo);


///SETTERS
    void setNumeroPatente (const char* numPatente);
    void setFalla (const char* descripcionFalla);
    void setMarca (const char* marca);
    void setIngreso (clsFecha ingreso);
    void setTipoVehiculo (char tipoVehiculo);


///GETTERS
    const char* getNumeroPatente();
    const char* getDescripcion();
    const char* getMarca();
    std::string getIngreso();
    char getTipoVehiculo();
};


#endif // CLSVEHICULO_H_INCLUDED
