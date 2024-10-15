
#include "ClaseSurtidor.h"
using namespace std;
#include "iostream"
Surtidor::Surtidor(int cod, string mod , bool act , int capVentas ): codigo(cod), modelo(mod), activo(act), numVentas(0), capacidadVentas(capVentas) {
    ventas = new Venta[capacidadVentas]{};
}

Surtidor::    ~Surtidor() {
    delete[] ventas;
}


// Activar o desactivar el surtidor
void Surtidor::activarDesactivar(bool activar) {
    activo = activar;
}


// Verificar si el surtidor está activo
bool Surtidor::isActivo() const {
    return activo;
}


// Registrar una venta de combustible
void Surtidor::registrarVenta(int litros, double monto, const string& metodoPago, const string& numeroDocumento, const string& categoria) {
    if (numVentas == capacidadVentas) {
        redimensionarVentas();
    }
    ventas[numVentas] = Venta(categoria, litros, monto, metodoPago, numeroDocumento);
    numVentas++;
}



// Redimensionar el arreglo de ventas cuando se llena
void Surtidor:: redimensionarVentas() {
    int nuevaCapacidad = capacidadVentas * 2;
    Venta* tempVentas = new Venta[nuevaCapacidad];

    // Copiar las ventas existentes al nuevo arreglo
    for (int i = 0; i < numVentas; i++) {
        tempVentas[i] = ventas[i];
    }
    ventas = tempVentas;  // Asignar el nuevo arreglo
    capacidadVentas = nuevaCapacidad;  // Actualizar la capacidad
}

void Surtidor:: mostrarHistoricoVentas() const {
    if (numVentas == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    for (int i = 0; i < numVentas; i++) {
        ventas[i].mostrarInfo();
    }
}



// Métodos para obtener ventas y cantidad de ventas
int Surtidor:: getNumVentas() const {
    return numVentas;
}

Venta* Surtidor::getVentas() const {
    return ventas;
}

// Métodos para acceder a los atributos
int Surtidor:: getCodigo() const { return codigo; }
string Surtidor:: getModelo() const { return modelo; }
