#ifndef CANCHA_H
#define CANCHA_H
#include <iostream>
using namespace std;

#ifndef PROYECTO_CANCHA_H
#define PROYECTO_CANCHA_H


class Cancha {

private:

    string CodCancha;
    string TipoDeporte;
    double Precio;
    char Disponibilidad[12];

public:
    string CodigoDeCancha ();
    double getValor();
    string getDeporte();
    char CanchasDispo(int posicion);
    void CambiarPrecio (double NuevoPrecio);
    void CambiarDisponibilidad (int posicion, char NuevoEstado);
    void MostrarDisponibilidad();

};


#endif //PROYECTO_CANCHA_H
#endif // CANCHA_H
