/*
 * tadCasilla.h
 *
 *  Created on: 20 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#ifndef TADCASILLA_H_
#define TADCASILLA_H_

struct Casilla {
	int numero;
};

/*
 * PRE:  { }
 * POST: { Inicializa la casilla como vacia, cuando el numero sea 0 }
 * COMPLEJIDAD: O(1)
 */
void iniciar (Casilla &c);

/*
 * PRE:  { }
 * POST: { Pone un valor en la casilla }
 * COMPLEJIDAD: O(1)
 */
void ponerValor (Casilla &c, int numero);

/*
 * PRE:  { }
 * POST: { Obtiene el valor de la casilla }
 * COMPLEJIDAD: O(1)
 */
int obtenerValor (Casilla c);

/*
 * PRE:  { }
 * POST: { Vacia una casilla poniendole el numero 0 }
 * COMPLEJIDAD: O(1)
 */
void vaciar (Casilla &c);

/*
 * PRE:  { }
 * POST: { Ver si una casilla esta vacia o no}
 * COMPLEJIDAD: O(1)
 */
bool vacia (Casilla c);

#endif /* TADCASILLA_H_ */
