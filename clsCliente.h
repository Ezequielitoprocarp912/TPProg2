#pragma once
#include "clsPersona.h"

class clsCliente : public clsPersona
{
private:
    ///ATRIBUTOS
    char _numTelefono[21];
    char _mail[51];
    char _tipoCliente;
    bool _estado;

public:
    ///CONSTRUCTORES
    clsCliente();

    ///SETTERS
    bool setMail(const char* mail);
    bool setNumTelefono(const char* telefono);
    bool setTipoCliente(char tipoCliente);
    void setEstado(bool estado);

    ///GETTERS
    const char* getMail();
    const char* getNumTelefono();
    char getTipoCliente();
    bool getEstado();
};
