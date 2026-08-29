#include "GestorReservas.h"
#include "Reserva.h"
#include "Cliente.h"
#include "Cancha.h"
#include <iostream>
using namespace std;

GestorReservas::GestorReservas() {
	cantidadReservas = 0;
	capacidadReservas = 120;
	reservas = new Reserva * [capacidadReservas];
	siguenteNumeroReserva = 1;
}

GestorReservas::~GestorReservas() {
	for (int i = 0; i < cantidadReservas; i++) {
		delete reservas[i];
	}
	delete[] reservas;
}

GestorReservas::Reserva* registrar(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantFranjas) {
	if (cliente == nullptr || cancha == nullptr) {
		cout << "No existe el cliente o la cancha." << endl;
		return nullptr;
	}

	if (franjaInicial < 0 || cantFranjas <= 0 || franjaInicial + cantFranjas > 12) {
		cout << "La franja inicial y la cantidad de franjas deben estar dentro del rango permitido (0-11)" << endl;
		return nullptr;

	}

	char estado = cancha->getFranja(i);
	if (estado != 'L' && estado != 'l') {
		cout << "Alguna franja solicitada no esta libre." << endl;
		return nullptr;
	}

	if (cantidadReservas >= capacidadReservas) {
		cout << "No hay espacio para registrar mas reservas." << endl;
		return nullptr;
	}

	Reserva* nuevaReserva = new Reserva(siguienteNumeroReserva, cliente, cancha, franjaInicial, cantFranjas);
	siguienteNumero++;

	for (int i = franjaInicial; i < franjaInicial + cantFranjas; i++) {
		if (!cancha->cambiarDisponibilidad(i, 'O')) {
			cout << "Error inesperado al ocupar la franja " << i << endl;
		}
	}

	reservas[cantidad] = nueva;
	cantidad++;

	return nueva;

}