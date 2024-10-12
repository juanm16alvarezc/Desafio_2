#include <iostream>
#include "Funciones_.h"
#include "ClaseRedNacional.h"
#include <cstdlib> // Para rand y srand
using namespace std;

// Declare the global RedNacional object
RedNacional redNacional;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    bool repetir=true;
    while(repetir){
        unsigned short int n;
        cout << "Bienvenido al mejor sistema que va a encontrar en su vida" << endl;
        cout << "Ingrese un #1 si desea acceder a los servicios de gestion de red." << endl;
        cout << "Ingrese un #2 si desea acceder a los servicios de gestion de estaciones de servicio." << endl;
        cout << "Ingrese un #3 si desea acceder a la opcion de sistema nacional de verificacion de fugas." << endl;
        cout << "Ingrese #4 si desea acceder a la opcion de simulacion de ventas." << endl;
        cout << ": ";
        cin >> n;

        while (n <= 0 || n > 4) {
            cout << "Ingrese valor valido:" << endl;
            cin >> n;
        }

        if (n == 1) {
            serviciosDeGestionDeRed(redNacional);
        }
        else if (n == 2) {
            serviciosDeGestionDeEstacionesDeServicio(redNacional);
        }
        else if (n == 3) {
            //     sistemaDeVerificacionDeFugas(redNacional);
        }
        else if (n == 4) {
            //     simulacionDeVentas(redNacional);
        }
        cout << "desea realizar mas operaciones, ingrese #1 para si o #2 para no" << endl;
        cin >> n;
        while (n <= 0 || n > 2) {
            cout << "Ingrese valor valido:" << endl;
            cin >> n;
        }
        if (n==2){
            repetir=false;
        }
    }
}
