#include <iostream>
#include <string>
using namespace std;


class EstacionDeServicio {
private:
    string nombre;
    int codigoIdentificador;
    string gerente;
    string region;
    double coordenadas[2];  // Coordenadas GPS

    Tanque tanque;  // Un único tanque para la estación
    Surtidor* surtidores;  // Arreglo dinámico de surtidores
    int numSurtidores;
    int capacidadSurtidores;

    // Método para redimensionar el arreglo de surtidores cuando sea necesario
    void redimensionarSurtidores(int nuevaCapacidad) {
        Surtidor* temp = new Surtidor[nuevaCapacidad];
        for (int i = 0; i < numSurtidores; i++) {
            temp[i] = surtidores[i];
        }
        delete[] surtidores;
        surtidores = temp;
        capacidadSurtidores = nuevaCapacidad;
    }

public:
    EstacionDeServicio(const string& nombre, int codigo, const string& gerente, const string& region, const double* coords, const Tanque& tanque)
        : nombre(nombre), codigoIdentificador(codigo), gerente(gerente), region(region), tanque(tanque), numSurtidores(0), capacidadSurtidores(2) {
        coordenadas[0] = coords[0];
        coordenadas[1] = coords[1];
        surtidores = new Surtidor[capacidadSurtidores];
    }

    ~EstacionDeServicio() {
        delete[] surtidores;
    }

    // Getters
    string getNombre() const { return nombre; }
    int getCodigoIdentificador() const { return codigoIdentificador; }
    string getGerente() const { return gerente; }
    string getRegion() const { return region; }
    const double* getCoordenadas() const { return coordenadas; }
    const Tanque& getTanque() const { return tanque; }
    Surtidor* getSurtidores() const { return surtidores; }

    // Setters
    void setNombre(const string& nombre) { this->nombre = nombre; }
    void setCodigoIdentificador(int codigo) { this->codigoIdentificador = codigo; }
    void setGerente(const string& gerente) { this->gerente = gerente; }
    void setRegion(const string& region) { this->region = region; }
    void setCoordenadas(const double* coords) {
        coordenadas[0] = coords[0];
        coordenadas[1] = coords[1];
    }
    void setTanque(const Tanque& nuevoTanque) { tanque = nuevoTanque; }

    // Agregar surtidor
    void agregarSurtidor(const Surtidor& surtidor) {
        if (numSurtidores == capacidadSurtidores) {
            redimensionarSurtidores(capacidadSurtidores * 2);  // Redimensionar el arreglo cuando se alcanza la capacidad
        }
        surtidores[numSurtidores] = surtidor;
        numSurtidores++;
    }

    // Mostrar información de la estación
    void mostrarInfo() const {
        cout << "Estación: " << nombre << ", Código: " << codigoIdentificador
             << ", Gerente: " << gerente << ", Región: " << region
             << ", Coordenadas: [" << coordenadas[0] << ", " << coordenadas[1] << "]" << endl;
        cout << "Tanque: ";
        tanque.mostrarInfo();
        cout << "Surtidores: " << endl;
        for (int i = 0; i < numSurtidores; i++) {
            surtidores[i].mostrarInfo();
        }
    }
};
