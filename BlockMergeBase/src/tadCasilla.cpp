/*
 * tadCasilla.cpp
 *
 *  Created on: 20 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#include "tadCasilla.h"


void iniciar (Casilla &c){
	c.numero=0;
}

void ponerValor (Casilla &c, int numero){
	c.numero=numero;
}

int obtenerValor (Casilla c){
	return c.numero;
}

void vaciar (Casilla &c){
	c.numero=0;
}

bool vacia (Casilla c){
	bool vacia;
	if (c.numero==0){
		vacia=true;
	} else {
		vacia=false;
	}
return vacia;
}
