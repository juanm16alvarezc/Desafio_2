#include "ClaseEstacionDeServicio.h"
#include <iostream>
#include <cstdlib>
#include "ClaseRedNacional.h"

using namespace std;
RedNacional::RedNacional() : numEstaciones(0), capacidad(2),contCodigoES(1) {
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
EstacionDeServicio* RedNacional::buscarEstacionPorCodigo(int codigo) const {
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getCodigoIdentificador() == codigo) {
            return estaciones[i];
        }
    }
    return nullptr;
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
            cout << "Codigo: " << estaciones[i]->getCodigoIdentificador()
            << " - Nombre: " << estaciones[i]->getNombre()
            << " - Region: " << estaciones[i]->getRegion() << endl;
        }
    }
}

// Agregar estacion
void RedNacional:: agregarEstacion(const string& nombre, const string& gerente, const string& region, const double* coords){

    if (numEstaciones == capacidad) {
        redimensionar(capacidad * 2);
    }
    estaciones[numEstaciones] = new EstacionDeServicio(nombre,contCodigoES,gerente,region,coords);
    numEstaciones++;
    contCodigoES++;
}

// Eliminar estacin
void RedNacional::eliminarEstacion(int codigo) {
    for (int i = 0; i < numEstaciones; i++) {
        if (estaciones[i]->getCodigoIdentificador() == codigo) {
            if (estaciones[i]->getSurtidoresActivos() == 0) {
                delete estaciones[i];
                for (int j = i; j < numEstaciones - 1; j++) {
                    estaciones[j] = estaciones[j + 1];
                }

                numEstaciones--;
                cout << "Estacion eliminada correctamente." << endl;
                return;  // Terminar la función
            } else {
                cout << "No se puede eliminar la estacion porque tiene surtidores activos." << endl;
                return;
            }
        }
    }
    cout << "No se encontro la estacion con el codigo proporcionado." << endl;
}


void RedNacional::calcularVentasPorEstacion() const {
    for (int i = 0; i < numEstaciones; i++) {
        cout << "Ventas para la estacion: " << estaciones[i]->getNombre() << endl;
        estaciones[i]->calcularVentas();
    }
}


//Fijar precios
void RedNacional:: fijarPreciosPorRegion(const string& region, double precioRegular, double precioPremium, double precioEcoExtra) {
    int indiceRegion = getIndiceRegion(region);
    if (indiceRegion != -1) {
        precios[indiceRegion][0] = precioRegular;
        precios[indiceRegion][1] = precioPremium;
        precios[indiceRegion][2] = precioEcoExtra;

        for (int i = 0; i < numEstaciones; i++) {
            if (estaciones[i]->getRegion() == region) {
                // Aqui se pueden actualizar los precios
            }
        }
    } else {
        cout << "Region no valida." << endl;
    }
}
int RedNacional::getIndiceRegion(const string& region) const {
    if (region == "Norte") return 0;
    if (region == "Centro") return 1;
    if (region == "Sur") return 2;
    return -1;
}
int RedNacional::getNumEstaciones() const {
    return numEstaciones;}
EstacionDeServicio** RedNacional::getEstaciones() const {
    return estaciones;
}
double RedNacional::getPrecio(int indiceRegion, int indiceCategoria) const {
    if (indiceRegion >= 0 && indiceRegion < 3 && indiceCategoria >= 0 && indiceCategoria < 3) {
        return precios[indiceRegion][indiceCategoria];
    } else {
        cout << "Indice de region o categoria fuera de rango" <<endl;
        return 0.0;  // Valor por defecto en caso de error
    }
}
