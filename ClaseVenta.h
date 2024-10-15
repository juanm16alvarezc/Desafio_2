#ifndef CLASEVENTA_H
#define CLASEVENTA_H

#include <string>
#include <ctime>

using namespace std;

class Venta {
private:
    string categoria;
    int litrosVendidos;
    int montoTotal;
    string metodoPago;
    string numeroDocumento;
    int fecha[3];
    int hora[3];

public:
    // Constructor
    Venta(string cat = "", int litros = 0.0, int monto = 0.0, string pago = "", string doc = "");

    // Mostrar venta
    void mostrarInfo() const;

    // Getters
    string getCategoria() const;
    double getLitrosVendidos() const;
    double getMontoTotal() const;
    int* getFecha();
    int* getHora();
    string getMetodoPago() const;
    string getNumeroDocumento() const;
};

#endif // CLASEVENTA_H
