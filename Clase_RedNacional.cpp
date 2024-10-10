#include "ClaseEstacionDeServicio.h"  // Para la clase EstacionDeServicio
#include <iostream>                   // Para las operaciones de entrada/salida
#include <cstdlib>                    // Para funciones como rand()

using namespace std;

class RedNacional {
private:
    EstacionDeServicio* estaciones;
    int numEstaciones;
    int capacidad;
    double precios[3][3];  // Precios por región (Norte, Centro, Sur) y tipo de combustible (Regular, Premium, EcoExtra)

public:
    RedNacional() : numEstaciones(0), capacidad(2) {
        estaciones = new EstacionDeServicio[capacidad];

        // Inicializar los precios por región y tipo de combustible (Ejemplo)
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

    ~RedNacional() {
        delete[] estaciones;
    }

    void redimensionar(int nuevaCapacidad) {
        EstacionDeServicio* temp = new EstacionDeServicio[nuevaCapacidad];
        for (int i = 0; i < numEstaciones; i++) {
            temp[i] = estaciones[i];
        }
        delete[] estaciones;
        estaciones = temp;
        capacidad = nuevaCapacidad;
    }

    // a. Agregar estación
    void agregarEstacion(const EstacionDeServicio& estacion) {
        if (numEstaciones == capacidad) {
            redimensionar(capacidad * 2);
        }
        estaciones[numEstaciones] = estacion;
        numEstaciones++;
    }

    // b. Eliminar estación
    void eliminarEstacion(int codigo) {
        for (int i = 0; i < numEstaciones; i++) {
            if (estaciones[i].getCodigoIdentificador() == codigo && estaciones[i].getSurtidoresActivos() == 0) {
                for (int j = i; j < numEstaciones - 1; j++) {
                    estaciones[j] = estaciones[j + 1];
                }
                numEstaciones--;
                return;
            }
        }
        cout << "No se puede eliminar la estación: No tiene surtidores activos o no existe." << endl;
    }

    // c. Calcular ventas por estación
    void calcularVentasPorEstacion() const {
        for (int i = 0; i < numEstaciones; i++) {
            cout << "Ventas para la estación: " << estaciones[i].getNombre() << endl;
            double ventas = estaciones[i].calcularVentas();
            cout << "Monto total de ventas: $" << ventas << endl;
        }
    }

    // d. Fijar precios
    void fijarPreciosPorRegion(const string& region, double precioRegular, double precioPremium, double precioEcoExtra) {
        int indiceRegion = getIndiceRegion(region);
        if (indiceRegion != -1) {
            precios[indiceRegion][0] = precioRegular;
            precios[indiceRegion][1] = precioPremium;
            precios[indiceRegion][2] = precioEcoExtra;

            for (int i = 0; i < numEstaciones; i++) {
                if (estaciones[i].getRegion() == region) {
                    // Aquí se pueden actualizar los precios
                }
            }
        } else {
            cout << "Región no válida." << endl;
        }
    }

    // Método para obtener el índice de la región
    int getIndiceRegion(const string& region) const {
        if (region == "Norte") return 0;
        if (region == "Centro") return 1;
        if (region == "Sur") return 2;
        return -1;
    }
};

