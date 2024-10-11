#include <iostream>  // Para uso de cout
#include <cstdlib>   // Para uso de rand()
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

// Métodos para obtener la capacidad de cada tanque
double Tanque::getCapacidadTotalRegular() const { return capacidadTotalRegular; }
double Tanque:: getCapacidadTotalPremium() const { return capacidadTotalPremium; }
double Tanque::getCapacidadTotalEcoExtra() const { return capacidadTotalEcoExtra; }

// Métodos para obtener la cantidad disponible actual de gasolina
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

// Método para mostrar información del tanque
void Tanque::mostrarInfo() const {
    cout << "Capacidad total Regular: " << capacidadTotalRegular << " litros\n"
         << "Capacidad total Premium: " << capacidadTotalPremium << " litros\n"
         << "Capacidad total EcoExtra: " << capacidadTotalEcoExtra << " litros\n"
         << "Gasolina disponible Regular: " << gasolinaDisponibleRegular << " litros\n"
         << "Gasolina disponible Premium: " << gasolinaDisponiblePremium << " litros\n"
         << "Gasolina disponible EcoExtra: " << gasolinaDisponibleEcoExtra << " litros\n";
}
