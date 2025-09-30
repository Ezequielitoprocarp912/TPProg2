#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class clsCliente
{

private:
///ATRIBUTOS
    char _cuit[12];
    char _nombre[20];
    char _apellido[20];
    char _numTelefono[20];
    char _mail[50];
    char _direccion [50];
    char _tipoCliente; /// 1 particular - 2 empresa
    bool _estado;


public:
///CONSTRUCTORES

/// Constructor DEFAULT
    clsCliente();

/// Constructor PARAMETROS
    clsCliente(const char* cuit, const char* nombre, const char* apellido, const char* mail, const char* direccion, char tipoCliente);


///SETTERS
    void setCuit (const char* cuit);
    void setNombre (const char* nombre);
    void setApellido (const char* apellido);
    void setMail (const char* mail);
    void setNumTelefono (const char* telefono);
    void setDireccion (const char* direccion);
    void setTipoCliente (char tipoCliente);
    void setEstado(bool estado);


///GETTERS
    const char* getCuit();
    const char* getNombre();
    const char* getApellido();
    const char* getMail();
    const char* getNumTelefono();
    const char* getDireccion();
    char getTipoCliente();
    bool getEstado ();

};



#endif // CLIENTES_H_INCLUDED
