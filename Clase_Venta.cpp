#include <iostream>
#include <ctime>
#include "ClaseVenta.h"
using namespace std;


Venta::Venta(string cat, int litros, int monto, string pago, string doc) {
    categoria = cat;
    litrosVendidos = litros;
    montoTotal = monto;
    metodoPago = pago;
    numeroDocumento = doc;

    // Obtener la fecha y hora del sistema
    time_t t = time(nullptr);  // Obtiene el tiempo actual
    tm* now = localtime(&t);   // Convierte el tiempo a la hora local

    // Asignar la fecha y hora al arreglo respectivo
    fecha[0] = now->tm_mday;   // Día
    fecha[1] = now->tm_mon + 1; // Mes (tm_mon comienza en 0)
    fecha[2] = now->tm_year + 1900; // Año (tm_year es el número de años desde 1900)

    hora[0] = now->tm_hour;    // Hora
    hora[1] = now->tm_min;     // Minuto
    hora[2] = now->tm_sec;     // Segundo
}

// Mostrar la informacion de la venta
void Venta:: mostrarInfo() const {
    cout << "Fecha: " << fecha[0] << "/" << fecha[1] << "/" << fecha[2]
         << " Hora: " << hora[0] << ":" << hora[1] << ":" << hora[2]
         << ", Categoria: " << categoria
         << ", Litros: " << litrosVendidos
         << ", Monto: " << montoTotal
         << ", Pago: " << metodoPago
         << ", Documento: " << numeroDocumento << endl;
}

// Getters
string Venta::getCategoria() const { return categoria; }
double Venta::getLitrosVendidos() const { return litrosVendidos; }
double Venta:: getMontoTotal() const { return montoTotal; }
int* Venta::getFecha() { return fecha; }
int* Venta::getHora() { return hora; }
string Venta::getMetodoPago() const { return metodoPago; }
string Venta::getNumeroDocumento() const { return numeroDocumento; }

