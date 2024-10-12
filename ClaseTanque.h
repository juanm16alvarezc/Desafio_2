#ifndef CLASETANQUE_H
#define CLASETANQUE_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Tanque {
private:
    double capacidadTotalRegular;   // Capacidad total del tanque para Regular
    double capacidadTotalPremium;   // Capacidad total del tanque para Premium
    double capacidadTotalEcoExtra;  // Capacidad total del tanque para EcoExtra

    double gasolinaDisponibleRegular;  // Cantidad actual de gasolina en el tanque para Regular
    double gasolinaDisponiblePremium;  // Cantidad actual de gasolina en el tanque para Premium
    double gasolinaDisponibleEcoExtra; // Cantidad actual de gasolina en el tanque para EcoExtra

public:
    // Constructor por defecto: Inicializa con valores aleatorios entre 100 y 200
    Tanque();

    // Getter para las capacidades de cada categoría de combustible
    double getCapacidadTotalRegular() const;
    double getCapacidadTotalPremium() const;
    double getCapacidadTotalEcoExtra() const;

    // Métodos para obtener la cantidad disponible actual de gasolina
    double getGasolinaDisponibleRegular() const;
    double getGasolinaDisponiblePremium() const;
    double getGasolinaDisponibleEcoExtra() const;

    // Método para reducir la cantidad de gasolina en el tanque después de una venta
    void reducirGasolina(double litrosVendidos, const string& categoria);

    // Método para restablecer las capacidades de los tanques a valores aleatorios
    void restablecerTanque();

    // Método para mostrar información del tanque
    void mostrarInfo() const;
    //Para inicializar capacidad inicial del tanque
    void asignarCapacidad(double nuevaCapacidad, const string& categoria);
};

#endif // CLASETANQUE_H
