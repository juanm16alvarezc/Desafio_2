#include <iostream>
#include <cstdlib>
#include "ClaseTanque.h"
using namespace std;

Tanque:: Tanque() {
}

// Metodo para asignar la capacidad de un tanque y cambios de gasola
void Tanque::asignarCapacidad(int nuevaCapacidad, const string& categoria) {
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
int Tanque::getCapacidadTotalRegular() const { return capacidadTotalRegular; }
int Tanque:: getCapacidadTotalPremium() const { return capacidadTotalPremium; }
int Tanque::getCapacidadTotalEcoExtra() const { return capacidadTotalEcoExtra; }

int Tanque::getGasolinaDisponibleRegular() const { return gasolinaDisponibleRegular; }
int Tanque::getGasolinaDisponiblePremium() const { return gasolinaDisponiblePremium; }
int Tanque::getGasolinaDisponibleEcoExtra() const { return gasolinaDisponibleEcoExtra; }

// Método para reducir la cantidad de gasolina en el tanque después de una venta
unsigned int Tanque::reducirGasolina(unsigned int litrosVendidos, const string& categoria) {
    if (categoria == "Regular") {
        if (gasolinaDisponibleRegular >= litrosVendidos) {
            gasolinaDisponibleRegular -= litrosVendidos;
        }
        else {
            cout << "No hay suficiente gasolina en el tanque Regular, se procedera con la venta, solo con la gasolina disponible." << endl;
            litrosVendidos=gasolinaDisponibleRegular;
            gasolinaDisponibleRegular -= litrosVendidos;
        }
    }
    else if (categoria == "Premium") {
        if (gasolinaDisponiblePremium >= litrosVendidos) {
            gasolinaDisponiblePremium -= litrosVendidos;
        }
        else {
            cout << "No hay suficiente gasolina en el tanque Premium, se procedera con la venta, solo con la gasolina disponible." << endl;
            litrosVendidos=gasolinaDisponiblePremium;
            gasolinaDisponiblePremium -= litrosVendidos;
        }
    }
    else if (categoria == "EcoExtra") {
        if (gasolinaDisponibleEcoExtra >= litrosVendidos) {
            gasolinaDisponibleEcoExtra -= litrosVendidos;
        }
        else {
            cout << "No hay suficiente gasolina en el tanque EcoExtra, se procedera con la venta, solo con la gasolina disponible." << endl;
            litrosVendidos=gasolinaDisponibleEcoExtra;
            gasolinaDisponibleEcoExtra -= litrosVendidos;
        }
    }
    return litrosVendidos;
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
