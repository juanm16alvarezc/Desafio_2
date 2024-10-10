#include <iostream>  // Para uso de cout
#include <ctime>     // Para uso de time() y localtime()

using namespace std;

class Venta {
private:
    string categoria;    // Regular, Premium, EcoExtra
    double litrosVendidos;
    double montoTotal;
    string metodoPago;   // Efectivo, TDebito, TCredito
    string numeroDocumento;  // Número de documento del cliente
    int fecha[3];        // [día, mes, año]
    int hora[3];         // [hora, minuto, segundo]

public:
    // Constructor con obtención automática de fecha y hora
    Venta(string cat, double litros, double monto, string pago, string doc) {
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

    // Mostrar la información de la venta
    void mostrarInfo() const {
        cout << "Fecha: " << fecha[0] << "/" << fecha[1] << "/" << fecha[2]
             << " Hora: " << hora[0] << ":" << hora[1] << ":" << hora[2]
             << ", Categoria: " << categoria
             << ", Litros: " << litrosVendidos
             << ", Monto: " << montoTotal
             << ", Pago: " << metodoPago
             << ", Documento: " << numeroDocumento << endl;
    }

    // Getters
    string getCategoria() const { return categoria; }
    double getLitrosVendidos() const { return litrosVendidos; }
    double getMontoTotal() const { return montoTotal; }
    int* getFecha() { return fecha; }
    int* getHora() { return hora; }
    string getMetodoPago() const { return metodoPago; }
    string getNumeroDocumento() const { return numeroDocumento; }
};
