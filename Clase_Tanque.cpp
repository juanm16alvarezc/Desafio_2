#include <iostream>
#include <cstdlib>
#include "ClaseTanque.h"
using namespace std;

Tanque:: Tanque() {
}

// Metodo para asignar la capacidad de un tanque y cambios de gasola
void Tanque::asignarCapacidad(double nuevaCapacidad, const string& categoria) {
    if (categoria == "Regular") {
        capacidadTotalRegular = nuevaCapacidad;
        gasolinaDisponibleRegular = nuevaCapacidad;
    }
    else if (categoria == "Premium") {
        capacidadTotalPremium = nuevaCapacidad;
        gasolinaDisponiblePremium = nuevaCapacidad;
    }
    else if (categoria == "EcoExtra") {
        capacidadTotalEcoExtra = nuevaCapacidad;
        gasolinaDisponibleEcoExtra = nuevaCapacidad;
    }
}

//getters
double Tanque::getCapacidadTotalRegular() const { return capacidadTotalRegular; }
double Tanque:: getCapacidadTotalPremium() const { return capacidadTotalPremium; }
double Tanque::getCapacidadTotalEcoExtra() const { return capacidadTotalEcoExtra; }

double Tanque::getGasolinaDisponibleRegular() const { return gasolinaDisponibleRegular; }
double Tanque::getGasolinaDisponiblePremium() const { return gasolinaDisponiblePremium; }
double Tanque::getGasolinaDisponibleEcoExtra() const { return gasolinaDisponibleEcoExtra; }

// Método para reducir la cantidad de gasolina en el tanque después de una venta
void Tanque::reducirGasolina(double litrosVendidos, const string& categoria) {
    if (categoria == "Regular") {
        if (gasolinaDisponibleRegular >= litrosVendidos) {
            gasolinaDisponibleRegular -= litrosVendidos;
        } else {
            cout << "No hay suficiente gasolina en el tanque Regular." << endl;
        }
    } else if (categoria == "Premium") {
        if (gasolinaDisponiblePremium >= litrosVendidos) {
            gasolinaDisponiblePremium -= litrosVendidos;
        } else {
            cout << "No hay suficiente gasolina en el tanque Premium." << endl;
        }
    } else if (categoria == "EcoExtra") {
        if (gasolinaDisponibleEcoExtra >= litrosVendidos) {
            gasolinaDisponibleEcoExtra -= litrosVendidos;
        } else {
            cout << "No hay suficiente gasolina en el tanque EcoExtra." << endl;
        }
    }
}

// Metodo despliegue tanque
void Tanque::mostrarInfo() const {
    cout << "Capacidad total Regular: " << capacidadTotalRegular << " litros\n"
         << "Capacidad total Premium: " << capacidadTotalPremium << " litros\n"
         << "Capacidad total EcoExtra: " << capacidadTotalEcoExtra << " litros\n"
         << "Gasolina disponible Regular: " << gasolinaDisponibleRegular << " litros\n"
         << "Gasolina disponible Premium: " << gasolinaDisponiblePremium << " litros\n"
         << "Gasolina disponible EcoExtra: " << gasolinaDisponibleEcoExtra << " litros\n";
}
