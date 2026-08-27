#include "cancha.h"
#include <iostream>
using namespace std;


cancha::cancha (string codigo, string deporte, double precioInicial) {

    codCancha = codigo; //guarda el codigo de cancha que se pasa por el main
    precio = precioInicial; //guarda el precio
    for (int i = 0; i < 12; i++) { //le asigna a cada posicion L
        disponibilidad[i] = 'L';
    }
    tipoDeporte = deporte; //Guarda el tipo de deporte
}

string cancha::getDeporte() { //retorna el tipo de deporte
    return tipoDeporte;
}

double cancha::getValor() { //retorna el precio
    return precio;
}

string cancha::getcodigodeCancha() { //retorna el codigo de cancha
    return codCancha;
}

char cancha::getFranja(int posicion) {
    if (posicion > 11 || posicion < 0) { //verifica que el valor ingresado no sea menor a 0 o mayor a 11
        return 'X'; //Uso la X para que se muestre como error
    }

    return disponibilidad[posicion]; //retorno el char que esta en la posicion indicada

}

bool cancha::cambiarPrecio(double NuevoPrecio) { //metodo para cambiar precio, nuevoPrecio es el valor que le paso en el main
    if (NuevoPrecio <= 0) { //Verifica que el valor no sea menor o igual a 0
        cout << "PRECIO INVALIDO" << endl;
        return false;
    }else {
        precio = NuevoPrecio; //caso contrario si no se cumple lo de arriba, le asigna el nuevo precio
        cout << "PRECIO CAMBIADO EXITOSAMENTE" << endl;
        return true;
    }
}

bool cancha::cambiarDisponibilidad(int posicion,char nuevoEstado) { //Cambiar disponibilidad con los parametros que le paso
    if (posicion > 11 || posicion < 0) { //verifica que el valor ingresado no sea menor a 0 o mayor a 11
        return false;
    }

    if (disponibilidad[posicion] == 'O' && nuevoEstado == 'M') { //Verifica que el char ingresado no se pueda cambiar de O a M
        return false;
    }else if (disponibilidad[posicion] == 'L' && nuevoEstado == 'O' || disponibilidad[posicion] == 'L' && nuevoEstado == 'M' || disponibilidad[posicion] == 'O' && nuevoEstado == 'L' || disponibilidad[posicion] == 'M' && nuevoEstado == 'L') {
        disponibilidad[posicion] = nuevoEstado; //Si se cumplen alguna condicion, cambia la disponibilidad de esa posicion en el vector
        return true;
    }else {
        return false; //retorna false las demas condiciones como si las iguales o pasar de M a O y una cancha en M debe quitarse usando L
    }
}

void cancha::mostrarDisponibilidad() { //Muestra la disponibilidad de la cancha en sus horas

    for (int i = 0; i < 12; i++) {
        cout << "Posicion: " << i << " hora: "<< i + 8 << ":00 " << " Disponibilidad: " << disponibilidad[i] << endl;
    }

}



