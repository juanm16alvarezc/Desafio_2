
#include "ClaseVenta.h"
#include "ClaseSurtidor.h"
using namespace std;

Surtidor::Surtidor(int cod, string mod , bool act , int capVentas )
    : codigo(cod), modelo(mod), activo(act), numVentas(0), capacidadVentas(capVentas) {
    ventas = new Venta[capacidadVentas];  // Inicializar arreglo dinámico de ventas
}

Surtidor::    ~Surtidor() {
    delete[] ventas;  // Liberar memoria
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
void Surtidor::registrarVenta(double litros, double monto, const string& metodoPago, const string& numeroDocumento, const string& categoria) {
    // Si no hay espacio suficiente en el arreglo de ventas, redimensionamos
    if (numVentas == capacidadVentas) {
        redimensionarVentas();
    }

    // Crear un objeto Venta y agregarlo al arreglo
    ventas[numVentas] = Venta(categoria, litros, monto, metodoPago, numeroDocumento);
    numVentas++;

    // Reducir la gasolina en el tanque correspondiente según la categoría de la venta
    tanque.reducirGasolina(litros, categoria);  // Ahora puede modificar el tanque
}



// Redimensionar el arreglo de ventas cuando se llena
void Surtidor:: redimensionarVentas() {
    int nuevaCapacidad = capacidadVentas * 2;  // Duplicar la capacidad
    Venta* tempVentas = new Venta[nuevaCapacidad];

    // Copiar las ventas existentes al nuevo arreglo
    for (int i = 0; i < numVentas; i++) {
        tempVentas[i] = ventas[i];
    }

    // Liberar el arreglo anterior
    delete[] ventas;
    ventas = tempVentas;  // Asignar el nuevo arreglo
    capacidadVentas = nuevaCapacidad;  // Actualizar la capacidad
}

// Mostrar el histórico de ventas del surtidor
void Surtidor:: mostrarHistoricoVentas() const {
    if (numVentas == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    for (int i = 0; i < numVentas; i++) {
        ventas[i].mostrarInfo();  // Mostrar cada venta
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
