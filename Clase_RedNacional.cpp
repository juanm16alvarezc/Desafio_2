#include "ClaseEstacionDeServicio.h"  // Para la clase EstacionDeServicio
#include <iostream>                   // Para las operaciones de entrada/salida
#include <cstdlib>      // Para funciones como rand()
#include "ClaseRedNacional.h"

using namespace std;
RedNacional::RedNacional() : numEstaciones(0), capacidad(2) {
    estaciones = new EstacionDeServicio*[capacidad];

    // Inicializar los precios (Ejemplo)
    precios[0][0] = 1.10;  // Norte, Regular
    precios[0][1] = 1.50;  // Norte, Premium
    precios[0][2] = 1.30;  // Norte, EcoExtra

    precios[1][0] = 1.00;  // Centro, Regular
    precios[1][1] = 1.40;  // Centro, Premium
    precios[1][2] = 1.25;  // Centro, EcoExtra

    precios[2][0] = 1.20;  // Sur, Regular
    precios[2][1] = 1.60;  // Sur, Premium
    precios[2][2] = 1.35;  // Sur, EcoExtra
}

RedNacional::~RedNacional() {
    delete[] estaciones;
}

void RedNacional::redimensionar(int nuevaCapacidad) {
    EstacionDeServicio** temp = new EstacionDeServicio*[nuevaCapacidad];
    for (int i = 0; i < numEstaciones; i++) {
        temp[i] = estaciones[i];
    }
    delete[] estaciones;
    estaciones = temp;
    capacidad = nuevaCapacidad;
}

void RedNacional::listarEstaciones() const {
    if (numEstaciones == 0) {
        cout << "No hay estaciones en la red." << endl;
    } else {
        cout << "Listado de estaciones:" << endl;
        for (int i = 0; i < numEstaciones; i++) {
            cout << "Código: " << estaciones[i]->getCodigoIdentificador()
                 << " - Nombre: " << estaciones[i]->getNombre()
                 << " - Región: " << estaciones[i]->getRegion() << endl;
        }
    }
}

// a. Agregar estación
void RedNacional:: agregarEstacion(const string& nombre, int codigo, const string& gerente, const string& region, const double* coords){

    if (numEstaciones == capacidad) {
        redimensionar(capacidad * 2);
    }
    estaciones[numEstaciones] = new EstacionDeServicio(nombre,codigo,gerente,region,coords);
    numEstaciones++;
}

// b. Eliminar estación
void RedNacional::eliminarEstacion(int codigo) {
    for (int i = 0; i < numEstaciones; i++) {
        // Buscar la estación por código
        if (estaciones[i]->getCodigoIdentificador() == codigo) {
            // Verificar si no tiene surtidores activos
            if (estaciones[i]->getSurtidoresActivos() == 0) {
                // Liberar la memoria de la estación
                delete estaciones[i];

                // Mover las estaciones para llenar el hueco
                for (int j = i; j < numEstaciones - 1; j++) {
                    estaciones[j] = estaciones[j + 1];
                }

                numEstaciones--; // Reducir el número de estaciones
                cout << "Estación eliminada correctamente." << endl;
                return;  // Terminar la función
            } else {
                cout << "No se puede eliminar la estación porque tiene surtidores activos." << endl;
                return;
            }
        }
    }
    cout << "No se encontró la estación con el código proporcionado." << endl;
}


void RedNacional::calcularVentasPorEstacion() const {
    for (int i = 0; i < numEstaciones; i++) {
        std::cout << "Ventas para la estación: " << estaciones[i]->getNombre() << std::endl;
        estaciones[i]->calcularVentas();
    }
}


// d. Fijar precios
void RedNacional:: fijarPreciosPorRegion(const string& region, double precioRegular, double precioPremium, double precioEcoExtra) {
    int indiceRegion = getIndiceRegion(region);
    if (indiceRegion != -1) {
        precios[indiceRegion][0] = precioRegular;
        precios[indiceRegion][1] = precioPremium;
        precios[indiceRegion][2] = precioEcoExtra;

        for (int i = 0; i < numEstaciones; i++) {
            if (estaciones[i]->getRegion() == region) {
                // Aquí se pueden actualizar los precios
            }
        }
    } else {
        cout << "Región no valida." << endl;
    }
}


// Método para obtener el índice de la región
int RedNacional::getIndiceRegion(const string& region) const {
    if (region == "Norte") return 0;
    if (region == "Centro") return 1;
    if (region == "Sur") return 2;
    return -1;
}



