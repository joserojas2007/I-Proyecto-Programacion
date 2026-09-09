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

int GestorReservas::getCantidadReservas() {
	return cantidadReservas;
}

Reserva* GestorReservas::getReserva(int indice) {
	if (indice >= 0 && indice < cantidadReservas) {
		return reservas[indice];
	}
	return nullptr;
}

Reserva* GestorReservas::registrar(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantFranjas) {
	if (cliente == nullptr || cancha == nullptr) {
		cout << "No existe el cliente o la cancha." << endl;
		return nullptr;
	}

	if (franjaInicial < 0 || cantFranjas <= 0 || franjaInicial + cantFranjas > 12) {
		cout << "La franja inicial y la cantidad de franjas deben estar dentro del rango permitido (0-11)" << endl;
		return nullptr;

	}

	for (int i = franjaInicial; i < franjaInicial + cantFranjas; i++) {
		char estado = cancha->getFranja(i);
		if (estado != 'L' && estado != 'l') {
			cout << "Alguna franja solicitada no esta libre." << endl;
			return nullptr;
		}
	}

	if (cantidadReservas >= capacidadReservas) {
		cout << "No hay espacio para registrar mas reservas." << endl;
		return nullptr;
	}

	Reserva* nuevaReserva = new Reserva(siguienteNumeroReserva, cliente, cancha, franjaInicial, cantFranjas);
	siguienteNumeroReserva++;

	

	for (int i = franjaInicial; i < franjaInicial + cantFranjas; i++) {
		if (!cancha->cambiarDisponibilidad(i, 'O')) {
			cout << "Error inesperado al ocupar la franja " << i << endl;
		}
	}



	reservas[cantidadReservas] = nuevaReserva;
	cantidadReservas++;

	return nuevaReserva;

}

Reserva* GestorReservas::buscarReserva(int numeroReserva) {
	for (int i = 0; i < cantidadReservas; i++) {
		if (reservas[i] != nullptr && reservas[i]->getNumero() == numeroReserva) {
			return reservas[i];
		}
	}
	return nullptr;
}

bool GestorReservas::cancelarReserva(int numeroReserva) {
	Reserva* reserva = buscarReserva(numeroReserva);

	if (reserva == nullptr) {
		cout << "No existe una reserva con ese numero." << endl;
		return false;
	}

	if (reserva->getEstado() == "cancelada") {
		cout << "La reserva ya se encuentra cancelada." << endl;
		return false;
	}

	Cancha* cancha = reserva->getCancha();
	int franjaInicial = reserva->getFranjaInicial();
	int cantFranjas = reserva->getCantFranjas();

	for (int j = franjaInicial; j < franjaInicial + cantFranjas; j++) {
		if (!cancha->cambiarDisponibilidad(j, 'L')) {
			cout << "La franja ya esta libre." << j << endl;
		}
	}

	reserva->cancelar();
	return true;
}

void GestorReservas::mostrarReservas() {
	if (cantidadReservas == 0) {
		cout << "No hay reservas registradas." << endl;
		return;
	}

	for (int i = 0; i < cantidadReservas; i++) {
		if (reservas[i] != nullptr) {
			cout << "Reserva #" << reservas[i]->getNumero()
				<< " | Cliente: " << reservas[i]->getCliente()->getIdentificacion()
				<< " | Cancha: " << reservas[i]->getCancha()->getcodigodeCancha()
				<< " | Estado: " << reservas[i]->getEstado()
				<< " | Franja inicial: " << reservas[i]->getFranjaInicial()
				<< " | Cantidad de franjas: " << reservas[i]->getCantFranjas()
				<< " | Monto: " << reservas[i]->getMonto()
				<< endl;
		}
	}
}

void GestorReservas::mostrarPorCancha(string codigo) {
	bool encontrada = false;

	for (int i = 0; i < cantidadReservas; i++) {
		if (reservas[i] != nullptr && reservas[i]->getCancha()->getcodigodeCancha() == codigo) {
			cout << "Reserva #" << reservas[i]->getNumero()
				<< " | Estado: " << reservas[i]->getEstado()
				<< " | Monto: " << reservas[i]->getMonto()
				<< endl;
			encontrada = true;
		}
	}

	if (!encontrada) {
		cout << "No hay reservas para esa cancha." << endl;
	}
}

void GestorReservas::mostrarPorCliente(string id) {
	bool encontrada = false;

	for (int i = 0; i < cantidadReservas; i++) {
		if (reservas[i] != nullptr && reservas[i]->getCliente()->getIdentificacion() == id) {
			cout << "Reserva #" << reservas[i]->getNumero()
				<< " | Estado: " << reservas[i]->getEstado()
				<< " | Monto: " << reservas[i]->getMonto()
				<< endl;
			encontrada = true;
		}
	}

	if (!encontrada) {
		cout << "No hay reservas para ese cliente." << endl;
	}
}

}
	