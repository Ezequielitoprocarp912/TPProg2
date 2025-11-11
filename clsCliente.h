#pragma once


class clsCliente
{
    private:
    ///ATRIBUTOS
        char _cuit[12];
        char _nombre[21];
        char _apellido[21];
        char _numTelefono[21];
        char _mail[51];
        char _direccion [51];
        char _tipoCliente;
        bool _estado;

    public:
    ///CONSTRUCTORES
        clsCliente();

    ///SETTERS
        bool setCuit(const char* cuit);
        bool setNombre(const char* nombre);
        bool setApellido(const char* apellido);
        bool setMail(const char* mail);
        bool setNumTelefono(const char* telefono);
        bool setDireccion(const char* direccion);
        bool setTipoCliente(char tipoCliente);
        void setEstado(bool estado);

    ///GETTERS
        const char* getCuit();
        const char* getNombre();
        const char* getApellido();
        const char* getMail();
        const char* getNumTelefono();
        const char* getDireccion();
        char getTipoCliente();
        bool getEstado();
};
