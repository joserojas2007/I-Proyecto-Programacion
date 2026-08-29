#include "Reserva.h"

Reserva::Reserva(int numero, Cliente* cliente, Cancha* cancha, int franjaInicial, int cantFranjas) {
	this->numero = numero;
	this->cliente = cliente;
	this->cancha = cancha;
	this->franjaInicial = franjaInicial;
	this->cantFranjas = cantFranjas;
}

void Reserva::cancelar() {
	this->estado = "cancelada";
}

void Reserva::calcularMonto() {
	monto = cancha->getValor() * cantFranjas;
}

int Reserva::getNumero() {
	return numero;
}

Cliente* Reserva::getCliente() {
	return cliente;
}

Cancha* Reserva::getCancha() {
	return cancha;
}

int Reserva::getFranjaInicial() {
	return franjaInicial;
}

int Reserva::getCantFranjas() {
	return cantFranjas;
}

float Reserva::getMonto() {
	return monto;
}

string Reserva::getEstado() {
	return estado;
}