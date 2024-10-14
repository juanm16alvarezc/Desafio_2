#ifndef CLASETANQUE_H
#define CLASETANQUE_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Tanque {
private:
    int capacidadTotalRegular;   // Capacidad total del tanque para Regular
    int capacidadTotalPremium;   // Capacidad total del tanque para Premium
    int capacidadTotalEcoExtra;  // Capacidad total del tanque para EcoExtra

    int gasolinaDisponibleRegular;  // Cantidad actual de gasolina en el tanque para Regular
    int gasolinaDisponiblePremium;  // Cantidad actual de gasolina en el tanque para Premium
    int gasolinaDisponibleEcoExtra; // Cantidad actual de gasolina en el tanque para EcoExtra

public:
    // Constructor por defecto: Inicializa con valores aleatorios entre 100 y 200
    Tanque();

    // Getter para las capacidades de cada categoría de combustible
    int getCapacidadTotalRegular() const;
    int getCapacidadTotalPremium() const;
    int getCapacidadTotalEcoExtra() const;

    // Métodos para obtener la cantidad disponible actual de gasolina
    int getGasolinaDisponibleRegular() const;
    int getGasolinaDisponiblePremium() const;
    int getGasolinaDisponibleEcoExtra() const;

    // Método para reducir la cantidad de gasolina en el tanque después de una venta
    unsigned int reducirGasolina(unsigned int litrosVendidos, const string& categoria);

    // Método para restablecer las capacidades de los tanques a valores aleatorios
    void restablecerTanque();

    // Método para mostrar información del tanque
    void mostrarInfo() const;
    //Para inicializar capacidad inicial del tanque
    void asignarCapacidad(int nuevaCapacidad, const string& categoria);
};

#endif // CLASETANQUE_H
