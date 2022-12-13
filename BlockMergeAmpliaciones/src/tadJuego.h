/*
 * tadJuego.h
 *
 *  Created on: 28 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_

#include "tadTablero.h"
#include "entorno.h"

using namespace std;


struct Juego{
	Tablero tablero;
	int objetivo;
};

/*
 * PRE: Existe juego
 * POST: Inicia el juego con los valores de el archivo de configuracion,
 * si d==0 coge la matriz del archivo, si es d>0 genera la matriz con valores aleatorios
 * de 1 hasta el numero d incluidos.
 */
bool iniciarJuego(Juego &J);

/*
 * PRE: Existe juego
 * POST: Realiza la gestion general del juego (gestiona las teclas que se pulsan,
 * actualiza el tablero, actualiza la pantalla, que termine el juego mostrando los
 * mensajes de despedida cerrando el entorno grafico, etc)
 */

void gestionDelJuego(Juego &j);

#endif /* TADJUEGO_H_ */
