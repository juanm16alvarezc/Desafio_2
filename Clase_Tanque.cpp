class Tanque {
private:
    const int capacidadRegular;
    const int capacidadPremium;
    const int capacidadEcoExtra;
    int disponibilidadRegular;
    int disponibilidadPremium;
    int disponibilidadEcoExtra;

public:
    Tanque(int capReg, int capPrem, int capEco, int dispReg = 0, int dispPrem = 0, int dispEco = 0)
        : capacidadRegular(capReg), capacidadPremium(capPrem), capacidadEcoExtra(capEco),
        disponibilidadRegular(dispReg), disponibilidadPremium(dispPrem), disponibilidadEcoExtra(dispEco) {}

    // Getters para capacidades (const, porque no se pueden modificar)
    int getCapacidadRegular() const { return capacidadRegular; }
    int getCapacidadPremium() const { return capacidadPremium; }
    int getCapacidadEcoExtra() const { return capacidadEcoExtra; }

    // Getters para disponibilidades
    int getDisponibilidadRegular() const { return disponibilidadRegular; }
    int getDisponibilidadPremium() const { return disponibilidadPremium; }
    int getDisponibilidadEcoExtra() const { return disponibilidadEcoExtra; }

    // Setters para disponibilidades
    void setDisponibilidadRegular(int dispReg) {
        disponibilidadRegular = dispReg;
    }
    void setDisponibilidadPremium(int dispPrem) {
        disponibilidadPremium = dispPrem;
    }
    void setDisponibilidadEcoExtra(int dispEco) {
        disponibilidadEcoExtra = dispEco;
    }

    // Método para mostrar la información del tanque
    void mostrarInfo() const {
        cout << "Capacidades -> Regular: " << capacidadRegular
             << ", Premium: " << capacidadPremium
             << ", EcoExtra: " << capacidadEcoExtra << endl;
        cout << "Disponibilidades -> Regular: " << disponibilidadRegular
             << ", Premium: " << disponibilidadPremium
             << ", EcoExtra: " << disponibilidadEcoExtra << endl;
    }
};
