/*
 * tadTablero.cpp
 *
 *  Created on: 20 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */


#include "tadTablero.h"
#include <iostream>
using namespace std;

void iniciarTablero (Tablero &t, int num){
	int fila, col;
	for (fila=0; fila<t.ocupadas; fila++){
		for (col=0; col<t.ocupadas; col++){
			ponerValor(t.matriz[fila][col],rand()%num+1);
		}
	}
}

void iniciarConMatriz(Tablero &t, int tamano, int matriz[MAX][MAX]){
	t.ocupadas=tamano;
	int fila, col;
		for (fila=0; fila<t.ocupadas; fila++){
			for (col=0; col<t.ocupadas; col++){
				ponerValor(t.matriz[fila][col],matriz[fila][col]);

			}
		}
}

int obtenerTamanoTablero(Tablero t){
	return t.ocupadas;
}

void ponerTamanoTablero(Tablero &t, int tamano){
	t.ocupadas=tamano;
}

bool sonCoordenadasValidas(int fila, int col, int tamano){
	bool valida;
	valida=false;
	if (fila<tamano && col<tamano && fila>=0 && col>=0){
		valida=true;
	}
	return valida;
}

void ponerValorTablero(Tablero &t, int fila, int col, int numero){
	if (sonCoordenadasValidas(fila, col, t.ocupadas)){
		ponerValor(t.matriz[fila][col], numero);
	}
}

void vaciarCasillaTablero(Tablero &t, int fila, int col){
	if (sonCoordenadasValidas(fila, col, t.ocupadas)){
	vaciar(t.matriz[fila][col]);
	}
}

bool casillaVacia(Tablero t, int fila, int col){
	bool v;
	if (sonCoordenadasValidas(fila, col, t.ocupadas)){
		v=vacia(t.matriz[fila][col]);
		}
	return v;
}

int obtenerValorCasilla(Tablero t, int fila, int col){
	int valor;
	if (sonCoordenadasValidas(fila, col, t.ocupadas)){
		valor=obtenerValor(t.matriz[fila][col]);
	}
	return valor;
}

/*bool hayBloque(Tablero t, int fila, int col){
	bool bloque;
	bloque=false;
	if (!vacia(t.matriz[fila][col])){
		if (fila==0 && col==0){
			if (obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila+1][col]) ||
				obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col+1])){
					bloque=true;
			}
		} else{
			if (fila==(t.ocupadas-1) && col==0){
				if (obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila-1][col]) ||
				obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col+1])){
				bloque=true;
				}
			} else {
				if (fila==0 && col==(t.ocupadas-1)){
					if (obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col-1]) ||
					obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila+1][col])){
					bloque=true;
					}
				} else {
					if (fila==(t.ocupadas-1) && col==(t.ocupadas-1)){
						if(obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila-1][col]) ||
						obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col-1])){
						bloque=true;
						}
					} else{
						if (fila==0){
							if(obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila+1][col]) ||
							obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col+1]) ||
							obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col-1])){
							bloque=true;
							}
						} else {
							if (col==0){
								if (obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila-1][col]) ||
								obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila+1][col]) ||
								obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col+1])){
								bloque=true;
								}
							} else {
								if (col==(t.ocupadas-1)){
									if (obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila-1][col]) ||
									obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila+1][col]) ||
									obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col-1])){
									bloque=true;
									}
								} else {
									if (fila==(t.ocupadas-1)){
										if (obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila-1][col]) ||
										obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col-1]) ||
										obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col+1])){
										bloque=true;
										}
									} else{
										if (obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila-1][col]) ||
										obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila+1][col]) ||
										obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col-1]) ||
										obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col+1])){
										bloque=true;
										}
								}
							}
						}
					}
				}
			}
		}
	}

	}
	return bloque;
}*/

bool hayBloque(Tablero t, int fila, int col){
	bool bloque;
	bloque=false;
	if (sonCoordenadasValidas(fila+1, col, t.ocupadas)){
		if(obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila+1][col])){
			bloque=true;
		}
	}
	if (sonCoordenadasValidas(fila-1, col, t.ocupadas)){
		if(obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila-1][col])){
			bloque=true;
		}
	}
	if (sonCoordenadasValidas(fila, col+1, t.ocupadas)){
		if(obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col+1])){
			bloque=true;
		}
	}
	if (sonCoordenadasValidas(fila, col-1, t.ocupadas)){
		if(obtenerValor(t.matriz[fila][col])==obtenerValor(t.matriz[fila][col-1])){
			bloque=true;
		}
	}
	return bloque;
}

bool hayBloqueTablero(Tablero t){
	bool enc;
	enc=false;
	int fila, col;
	for (fila=0; fila<t.ocupadas && !enc; fila++){
		for (col=0; col<t.ocupadas && !enc; col++){
			if (hayBloque(t, fila, col)){
				enc=true;
			}
		}
	}
	return enc;
}

int valorMaximo(Tablero t){
	int max, fila, col;
	max=obtenerValor(t.matriz[0][0]);
	for (fila=0; fila<t.ocupadas; fila++){
		for (col=0; col<t.ocupadas; col++){
			if (obtenerValor(t.matriz[fila][col])>max){
				max=obtenerValor(t.matriz[fila][col]);
			}
		}
	}
	return max;
}

void vaciarBloque (Tablero &t, int fila, int col, int valor){
	if (sonCoordenadasValidas(fila, col, t.ocupadas)){
		if (!vacia(t.matriz[fila][col])){
			if (obtenerValor(t.matriz[fila][col])==valor){
				vaciar(t.matriz[fila][col]);
				vaciarBloque(t, fila+1, col, valor);
				vaciarBloque(t, fila-1, col, valor);
				vaciarBloque(t, fila, col+1, valor);
				vaciarBloque(t, fila, col-1, valor);
			}
		}
	}

}


void bajarColumna (Tablero &t, int col){
	int fila,c;
	c=0;
	for (fila=t.ocupadas-1; fila>=0; fila--){
		if (vacia(t.matriz[fila][col])){
			c=c+1;
		} else {
			t.matriz[fila+c][col]=t.matriz[fila][col];
			if (c!=0){
			vaciarCasillaTablero(t, fila, col);
			}
		}
	}
}


void bajarColumnaTablero (Tablero &t){
	int col;
	for (col=0; col<t.ocupadas; col++){
		bajarColumna(t, col);
	}
}


void aleatorioColumna(Tablero &t, int col){
	int fila;
	for (fila=0; fila<t.ocupadas; fila++){
		if (vacia(t.matriz[fila][col])){
			ponerValor(t.matriz[fila][col], rand()%(valorMaximo(t)-1)+1);
		}
	}
}


void aleatorioTablero(Tablero &t){
	int col;
	for (col=0; col<t.ocupadas; col++){
		aleatorioColumna(t, col);
	}
}

