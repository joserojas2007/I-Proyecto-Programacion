#ifndef GESTORRESERVAS_H
#define GESTORRESERVAS_H

#include <string>
using namespace std;

class Cliente;
class Reserva;
class Cancha;

class GestorReservas {
private:
	Reserva** reservas;
	int cantidadReservas;
	int capacidadReservas;
	int siguenteNumeroReserva;

public:
	GestorReservas();
	~GestorReservas();

	int getCantidadReservas();
	Reserva* getReserva(int indice);

	Reserva* registrar(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantFranjas);
	Reserva* buscarReserva(int numeroReserva);
	bool cancelarReserva(int numeroReserva);

	void mostrarReservas();
	void mostrarPorCancha(string codigo);
	void mostrarPorCliente(string id);


};


#endif