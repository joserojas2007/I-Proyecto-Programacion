#ifndef REPORTES_H
#define REPORTES_H

class GestorReservas;

class Reportes {
private:
	GestorReservas* gestorReservas;

public:
	Reportes(GestorReservas* gestorReservas);

	void ingresoTotalReservas();
	void horasMasYMenosReservadas();
};

#endif