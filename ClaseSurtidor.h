#ifndef CLASESURTIDOR_H
#define CLASESURTIDOR_H

#include <string>
#include "ClaseVenta.h"

using namespace std;

class Surtidor {
private:
    int codigo;               // Codigo del surtidor
    string modelo;            // Modelo del surtidor
    bool activo;              // Estado del surtidor (activo o inactivo)
    Venta* ventas;            // Arreglo dinamico de ventas
    int numVentas;            // #de ventas registradas
    int capacidadVentas;      // Capacidad max de ventas en el arreglo

public:
    // Constructor
    Surtidor(int cod = 0, string mod = "", bool act = true, int capVentas = 2);

    // Destructor
    ~Surtidor();

    // Activar o desactivar el surtidor
    void activarDesactivar(bool activar);

    // Verificar si el surtidor está activo
    bool isActivo() const;

    // Registrar una venta de combustible
    void registrarVenta(int litros, double monto, const string& metodoPago, const string& numeroDocumento, const string& categoria);

    // Redimensionar el arreglo de ventas cuando se llena
    void redimensionarVentas();

    // Mostrar el histórico de ventas del surtidor
    void mostrarHistoricoVentas() const;

    // gettes ventas y cantidad de ventas
    int getNumVentas() const;
    Venta* getVentas() const;

    // geters  atributos
    int getCodigo() const;
    string getModelo() const;
};

#endif // CLASESURTIDOR_H
