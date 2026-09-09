#include "Reportes.h"
#include "GestorReservas.h"
#include "Reserva.h"
#include <iostream>
using namespace std;

Reportes::Reportes(GestorReservas* gestorReservas) {
	this->gestorReservas = gestorReservas;
}

// Convierte una posicion de franja (0-11) a su horario, ej: franja 0 -> "08:00-09:00"
string franjaAHorario(int posicion) {
	int horaInicio = 8 + posicion;
	int horaFin = horaInicio + 1;
	return to_string(horaInicio) + ":00-" + to_string(horaFin) + ":00";
}

void Reportes::ingresoTotalReservas() {
	float total = 0;
	int cantidad = gestorReservas->getCantidadReservas();
	bool hayActivas = false;

	cout << "=== Detalle de reservas activas ===" << endl;

	for (int i = 0; i < cantidad; i++) {
		Reserva* r = gestorReservas->getReserva(i);
		if (r != nullptr && r->getEstado() == "activa") {
			cout << "Reserva #" << r->getNumero()
				<< " | Monto: " << r->getMonto() << endl;
			total = total + r->getMonto();
			hayActivas = true;
		}
	}

	if (!hayActivas) {
		cout << "No hay reservas activas." << endl;
	}

	cout << "=== Ingreso total: " << total << " ===" << endl;
}

void Reportes::horasMasYMenosReservadas() {
	int conteo[12] = { 0 };  // una posicion por cada franja horaria
	int cantidad = gestorReservas->getCantidadReservas();

	// Cuenta cuantas reservas activas ocupan cada franja
	for (int i = 0; i < cantidad; i++) {
		Reserva* r = gestorReservas->getReserva(i);
		if (r != nullptr && r->getEstado() == "activa") {
			int inicio = r->getFranjaInicial();
			int cant = r->getCantFranjas();
			for (int j = inicio; j < inicio + cant; j++) {
				conteo[j]++;
			}
		}
	}

	cout << "=== Detalle de reservas por franja horaria ===" << endl;
	for (int i = 0; i < 12; i++) {
		cout << franjaAHorario(i) << " -> " << conteo[i] << " reserva(s)" << endl;
	}

	// Busca la franja con mas y con menos reservas
	int indiceMax = 0;
	int indiceMin = 0;
	for (int i = 1; i < 12; i++) {
		if (conteo[i] > conteo[indiceMax]) {
			indiceMax = i;
		}
		if (conteo[i] < conteo[indiceMin]) {
			indiceMin = i;
		}
	}

	cout << "=== Hora con mas reservas: " << franjaAHorario(indiceMax)
		<< " (" << conteo[indiceMax] << " reservas) ===" << endl;
	cout << "=== Hora con menos reservas: " << franjaAHorario(indiceMin)
		<< " (" << conteo[indiceMin] << " reservas) ===" << endl;
}