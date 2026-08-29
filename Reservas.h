#ifndef RESERVA_H
#define RESERVA_H
#include <string>
using namespace std;

class Reserva {
private:
	int numero;
	Cliente* cliente;
	Cancha* cancha;
	int franjaInicial;
	int cantFranjas;
	float monto;
	string estado;
public:
	Reserva(int numero, Cliente* cliente, Cancha* cancha, int franjaInicial, int cantFranjas);

	void cancelar();
	void calcularMonto();

	int getNumero();
	Cliente* getCliente();
	Cancha* getCancha();
	int getFranjaInicial();
	int getCantFranjas();
	float getMonto();
	string getEstado();
};

#endif