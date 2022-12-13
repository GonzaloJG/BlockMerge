/*
 * tadTablero.h
 *
 *  Created on: 20 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_

#include "tadCasilla.h"

const int MAX=8;
typedef Casilla TMatriz[MAX][MAX];

struct Tablero{
	TMatriz matriz;
	int ocupadas;
};

/*
 * PRE:  { num >0}
 * POST: { Iniciar el tablero aleatoriamente con valores inferiores o iguales
 * al valor dado }
 * COMPLEJIDAD: O(n²)
 */
void iniciarTablero (Tablero &t, int num);

/*
 * PRE:  { tamano=tamaño matriz dada }
 * POST: { iniciar tablero con un tamaño dado y con los valores de una matriz de
 *  enteros dada}
 * COMPLEJIDAD: O(n²)
 */
void iniciarConMatriz (Tablero &t, int tamano, int matriz[MAX][MAX]);

/*
 * PRE:  { }
 * POST: { Obtener tamaño real del tablero }
 * COMPLEJIDAD: O(1)
 */
int obtenerTamanoTablero(Tablero t);

/*
 * PRE:  { }
 * POST: { Poner tamaño al tablero }
 * COMPLEJIDAD: O(1)
 */
void ponerTamanoTablero(Tablero &t, int tamano);

/*
 * PRE:  { fila>=0, col>=0}
 * POST: { Comprueba que la fila y la columna son mayores o iguales que 0 y menores que tamano}
 * COMPLEJIDAD: O(1)
 */
bool sonCoordenadasValidas(int fila, int col, int tamano);

/*
 * PRE:  { 0<=fila,col<tamaño real tablero   0<=numero<=8}
 * POST: { Poner un valor en una casilla concreta del tablero }
 * COMPLEJIDAD: O(1)
 */
void ponerValorTablero(Tablero &t, int fila, int col, int numero);

/*
 * PRE:  {  0<=fila,col<tamaño real tablero }
 * POST: { Vaciar una casilla concreta del tablero}
 * COMPLEJIDAD: O(1)
 */
void vaciarCasillaTablero(Tablero &t, int fila, int col);

/*
 * PRE:  { 0<=fila,col<tamaño real tablero }
 * POST: { Determinar si una casilla concreta del tablero esta vacía o no }
 * COMPLEJIDAD: O(1)
 */
bool casillaVacia(Tablero t, int fila, int col);

/*
 * PRE:  { 0<=fila,col<tamaño real tablero }
 * POST: { Obtener el valor de una casilla concreta del tablero }
 * COMPLEJIDAD: O(1)
 */
int obtenerValorCasilla(Tablero t, int fila, int col);

/*
 * PRE:  { 0<=fila,col<tamaño real tablero }
 * POST: { Determinar si una casilla concreta del tablero forma parte de un bloque o no }
 * COMPLEJIDAD: O(1)
 */
bool hayBloque(Tablero t, int fila, int col);

/*
 * PRE:  { }
 * POST: { Determinar si hay algun bloque en el tablero }
 * COMPLEJIDAD: O(n²)
 */
bool hayBloqueTablero(Tablero t);

/*
 * PRE:  { }
 * POST: { Obtener el valor maximo que hay en las casillas del tablero }
 * COMPLEJIDAD: O(n²)
 */
int valorMaximo(Tablero t);

/*
 * PRE:  { 0<=fila,col<tamaño real tablero  0<=valor<=8}
 * POST: { Dada una casilla concreta, vaciar todas las casillas del bloque al que
 * pertenece esa casilla }
 * COMPLEJIDAD: O()
 */
void vaciarBloque (Tablero &t, int fila, int col, int valor);

/*
 * PRE:  { 0<=col<tamaño real tablero}
 * POST: { Dada una columna del tablero, desplazar hacia abajo las casillas con numeros
 * que tengan casillas vacias debajo }
 * COMPLEJIDAD: O(n)
 */
void bajarColumna (Tablero &t, int col);

/*
 * PRE:  { }
 * POST: { Desplazar hacia abajo todas las casillas, en todas las columnas del tablero }
 * COMPLEJIDAD: O(n)
 */
void bajarColumnaTablero (Tablero &t);

/*
 * PRE:  { 0<=col<tamaño real tablero }
 * POST: { Dada una columna del tablero, rellenar con valores aleatorios las casillas
 * vacias en la parte superior }
 * COMPLEJIDAD: O(n)
 */
void aleatorioColumna(Tablero &t, int col);

/*
 * PRE:  { }
 * POST: { Rellenar todas las columnas del tablero con valores aleatorios }
 * COMPLEJIDAD: O(n)
 */
void aleatorioTablero(Tablero &t);


#endif /* TADTABLERO_H_ */
