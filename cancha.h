#ifndef CANCHA_H
#define CANCHA_H
#include <iostream>
#include <string>
using namespace std;

class cancha {

private:

    string codCancha;
    string tipoDeporte;
    double precio;
    char disponibilidad[12];

public:
    cancha(string codigo, string deporte, double precioInicial);
    string getcodigodeCancha ();
    double getValor();
    string getDeporte();
    char getFranja(int posicion);
    bool cambiarPrecio (double NuevoPrecio);
    bool cambiarDisponibilidad (int posicion, char NuevoEstado);
    void mostrarDisponibilidad();

};

#endif // CANCHA_H
