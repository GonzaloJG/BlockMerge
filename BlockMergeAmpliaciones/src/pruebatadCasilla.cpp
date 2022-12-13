/*
 * pruebatadCasilla.cpp
 *
 *  Created on: 22 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#include "pruebatadCasilla.h"


void pruebatadCasilla(){
	Casilla c;
	cout<<"INICIO: pruebas del TAD Casilla"<<endl;

	iniciar(c);
	if (vacia(c)!=true){
		cout<<"Error al iniciar la estructura"<<endl;
	}

	ponerValor(c, 3);
	if (obtenerValor(c)!=3){
		cout<<"Error al poner un valor"<<endl;
	}

	vaciar(c);
	if (vacia(c)!=true){
		cout<<"Error al vaciar una casilla"<<endl;
	}

	cout<<"FIN: pruebas del TAD Casilla"<<endl;
}


