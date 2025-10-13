#pragma once

class clsVehiculo
{
    private:
    ///ATRIBUTOS
        char _numPatente[8];
        char _marca [21];
        char _modelo [21];
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
