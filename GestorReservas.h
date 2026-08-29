#ifndef GESTORRESERVAS_H
#define GESTORRESERVAS_H

#include <string>
using namespace std;

class Cliente;
class Reserva;
class cancha;

class GestorReservas {
private:
	Reserva** reservas;
	int cantidadReservas;
	int capacidadReservas;
	int siguenteNumeroReserva;

public:
	GestorReservas();
	~GestorReservas();

	Reserva* registrar(Cliente* cliente, cancha* cancha, int franjaInicial, int cantFranjas);
	Reserva* buscarReserva(int numeroReserva);
	bool cancelarReserva(int numeroReserva);

	void mostrarReservas();
	void mostrarPorCancha(string codigo);
	void mostrarPorCliente(string id);


};


#endif