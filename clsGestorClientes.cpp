#include "clsGestorClientes.h"

/// CONSTRUCTOR           /// /// Guarda la ruta del archivo donde se guardan los registros
clsGestorClientes::clsGestorClientes() {
    _rutaDireccion = "Cliente.dat";
}

/// MÉTODOS DE MANIPULACIÓN /// este metodo pide al usuario un cliente y utiliza los setters para validar y guardar
void clsGestorClientes::cargarUnCliente(clsCliente &cliente) {
    char cuit[20], nombre[20], apellido[20], telefono[20], mail[50], direccion[50];
    char tipoCliente;
    bool entradaValida = false;

    std::cin.ignore();

    std::cout << "=== CARGA DE NUEVO CLIENTE ===";

    while (!entradaValida) {
        std::cout << "CUIT: ";
        std::cin.getline(cuit, 20);
        entradaValida = cliente.setCuit(cuit);
    }

    entradaValida = false;
    while (!entradaValida) {
        std::cout << "NOMBRE: ";
        std::cin.getline(nombre, 20);
        entradaValida = cliente.setNombre(nombre);
    }

    entradaValida = false;
    while (!entradaValida) {
        std::cout << "APELLIDO: ";
        std::cin.getline(apellido, 20);
        entradaValida = cliente.setApellido(apellido);
    }

    entradaValida = false;
    while (!entradaValida) {
        std::cout << "TELÉFONO: ";
        std::cin.getline(telefono, 20);
        entradaValida = cliente.setNumTelefono(telefono);
    }

    entradaValida = false;
    while (!entradaValida) {
        std::cout << "MAIL: ";
        std::cin.getline(mail, 50);
        entradaValida = cliente.setMail(mail);
    }

    entradaValida = false;
    while (!entradaValida) {
        std::cout << "DIRECCIÓN: ";
        std::cin.getline(direccion, 50);
        entradaValida = cliente.setDireccion(direccion);
    }

    entradaValida = false;
    while (!entradaValida) {
        std::cout << "Seleccione tipo: (1 Particular --- 2 Empresa) ";
        std::cin >> tipoCliente;
        entradaValida = cliente.setTipoCliente(tipoCliente);
    }

    cliente.setEstado(true);
    std::cin.ignore();
}

/// ESTE METODO MUESTRA LOS DATOS DE LOS CLIENTES
void clsGestorClientes::mostrarUnCliente(clsCliente cliente) {
    std::cout << "CUIT: " << cliente.getCuit() << std::endl;
    std::cout << "NOMBRE: " << cliente.getNombre() << std::endl;
    std::cout << "APELLIDO: " << cliente.getApellido() << std::endl;
    std::cout << "TELÉFONO: " << cliente.getNumTelefono() << std::endl;
    std::cout << "MAIL: " << cliente.getMail() << std::endl;
    std::cout << "DIRECCIÓN: " << cliente.getDireccion() << std::endl;
    std::cout << "TIPO DE CLIENTE: " << (cliente.getTipoCliente() == '1' ? "Particular" : "Empresa") << std::endl; /// operador ternario
    std::cout << "ESTADO: " << (cliente.getEstado() ? "Activo" : "Inactivo") << std::endl;
    std::cout << "-----------------------------------";
}

/// abre el archivo utilizando ab+ escribe registro final
bool clsGestorClientes::guardarEnDiscoCliente(clsCliente cliente) {
    FILE *p = fopen(_rutaDireccion.c_str(), "ab+");
    if (p == NULL) return false;
    bool ok = fwrite(&cliente, sizeof(clsCliente), 1, p);
    fclose(p);
    return ok;
}
/// sobrescribe un registro existente en una pos especifica seek
bool clsGestorClientes::guardarEnDiscoCliente(clsCliente cliente, int pos) {
    FILE *p = fopen(_rutaDireccion.c_str(), "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(clsCliente) * pos, SEEK_SET);
    bool ok = fwrite(&cliente, sizeof(clsCliente), 1, p);
    fclose(p);
    return ok;
}
/// recorre el archivo buscando un cliente
int clsGestorClientes::buscarClientePorCuit(const char *cuit) {
    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL) return -1;

    int i = 0;
    while (fread(&cliente, sizeof(clsCliente), 1, p)) {
        if (strcmp(cliente.getCuit(), cuit) == 0) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
/// lee un cliente en una pos especifica
clsCliente clsGestorClientes::leerCliente(int pos) {
    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL) exit(1);
    fseek(p, sizeof(clsCliente) * pos, SEEK_SET);
    fread(&cliente, sizeof(clsCliente), 1, p);
    fclose(p);
    return cliente;
}

/// EJECUCIÓN DE OPCIONES DE MENU
void clsGestorClientes::cargarCliente() {
    clsCliente nuevo;
    cargarUnCliente(nuevo);

    if (buscarClientePorCuit(nuevo.getCuit()) != -1) {
        std::cout << "ERROR: El Cliente ya existe";
        return;
    }

    if (guardarEnDiscoCliente(nuevo))
        std::cout << "Cliente guardado exitosamente";
    else
        std::cout << "ERROR: No se pudo guardar el cliente";
}

void clsGestorClientes::modificarCliente() {
    char cuit[20];
    std::cout << "CUIT del cliente a modificar: ";
    std::cin >> cuit;

    int pos = buscarClientePorCuit(cuit);
    if (pos == -1) {
        std::cout << "ERROR: Cliente no encontrado";
        return;
    }

    clsCliente cliente = leerCliente(pos);
    std::cout << "DATOS ACTUALES:\n";
    mostrarUnCliente(cliente);

    std::cout << "INGRESE NUEVOS DATOS:\n";
    cargarUnCliente(cliente);

    if (guardarEnDiscoCliente(cliente, pos))
        std::cout << "Cliente modificado correctamente.";
    else
        std::cout << "ERROR al modificar cliente.";
}

void clsGestorClientes::mostrarTodos() {
    clsCliente cliente;
    FILE *p = fopen(_rutaDireccion.c_str(), "rb");
    if (p == NULL) {
        std::cout << "No hay clientes cargados actualmente.";
        return;
    }

    while (fread(&cliente, sizeof(clsCliente), 1, p)) {
        if (cliente.getEstado())
            mostrarUnCliente(cliente);
    }
    fclose(p);
}

void clsGestorClientes::bajaCliente() {
    char cuit[20];
    std::cout << "Ingrese el CUIT del cliente a eliminar: ";
    std::cin >> cuit;

    int pos = buscarClientePorCuit(cuit);
    if (pos == -1) {
        std::cout << "ERROR: Cliente no encontrado.";
        return;
    }

    clsCliente cliente = leerCliente(pos);
    cliente.setEstado(false);
    guardarEnDiscoCliente(cliente, pos);

    std::cout << "Cliente dado de baja correctamente.";
}

void clsGestorClientes::buscarCliente() {
    char cuit[20];
    std::cout << "Ingrese el CUIT del cliente a buscar: ";
    std::cin >> cuit;

    int pos = buscarClientePorCuit(cuit);
    if (pos == -1) {
        std::cout << "Cliente inexistente.";
        return;
    }

    clsCliente cliente = leerCliente(pos);
    if (cliente.getEstado())
        mostrarUnCliente(cliente);
    else
        std::cout << "El cliente está dado de baja o inactivo";
}
