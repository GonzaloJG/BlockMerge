/*
 * pruebatadTablero.h
 *
 *  Created on: 25 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#ifndef PRUEBATADTABLERO_H_
#define PRUEBATADTABLERO_H_
#include "tadTablero.h"
#include <iostream>
using namespace std;

//Diseño de pruebas.

/* Establecemos el tablero 3x3, inicializamos el tablero para ver si se generan
 * los numeros aleatorios correctamente, los numeros generados deben ser entre 1 y 8,
 * luego se muestran para comprobar que sea correcto
 */
void pruebaIniciarTablero();

/* Iniciamos el tablero con una matriz enteros introducida a mano y indicando el tamaño del tablero,
 * luego mostramos la matriz del tablero comprobando que se ha introducido correctamente
 * introducimos la matriz:
 * 	1 2 3
 * 	1 2 3
 * 	1 2 3
 */
void pruebainiciarConMatriz();

/* obtenemos el tamaño real del tablero, el numero que tenemos en ocupadas */
void pruebaObtenerTamanoTablero();

/*Comprobamos que la fila y la columna estan dentro de la dimension del tablero
 * probamos con 3 coordenadas (4,3), (2,2), (5,1)
 */
void pruebaSonCoordenadasValidas();

/* ponemos un valor a 3 casillas diferentes y comprobamos que lo introduzca correctamente
 * casillas:    valor:
 * 	(0,0)		3
 * 	(1,2)		6
 * 	(3,2)		1
 */
void pruebaPonerValorTablero();

/* Vaciamos 3 casillas diferentes y comprobamos que las vacie correctamente
 *	casillas: (0,0), (2,2), (3,1)
 */
void pruebaVaciarCasillaTablero();

/* Probamos que una casilla concreta forma parte de bloque en una matriz que introducimos,
 * probamos con la casilla (0,1)
 * introducimos la matriz:
 *  1 1 1
 *  2 1 3
 *  2 2 2
 */
void pruebaHayBloque();

/* Determinar si hay algun bloque en el tablero
 * introducimos la matriz:
 * 1 2 3
 * 2 1 3
 * 2 2 2
 */
void pruebaHayBloqueTablero();

/*Introducimos una matriz y vemos el valor maximo de la matriz
 * introducimos la matriz:
 * 1 2 3
 * 4 5 4
 * 6 8 7
 */
void pruebaValorMaximo();

/* Vaciar todas las casilla del bloque al que pertenece la casilla introducida,
 * en este caso vaciamos el bloque de la casilla (0,1)
 * introducimos la matriz:
 * 3 3 3
 * 1 3 2
 * 2 2 2
 * El resultado debe ser:
 * 0 0 0
 * 1 0 2
 * 2 2 2
 */
void pruebaVaciarBloque();

/* Introducimos una matriz preparada para poder comprobar que se desplaza la comlumna correctamente
 * hacia abajo quedando las casillas libres encima de las casillas no libres
 * Introducimos la matriz:
 * 2 2 3
 * 1 2 2
 * 1 2 2
 * una vez introducida la matriz vaciamos el bloque de la casilla (1,0) con valor 1
 * y comprobamos que la columna 0 se desplace correctamente hacia abajo
 * El resultado debe ser:
 * 0 2 3
 * 0 2 2
 * 2 2 2
 */
void pruebaBajarColumna();

/*Desplazamos hacia abajo todas las columnas de una matriz dada, en este caso
 * borraremos el bloque del numero 2 y bajaremos todas las columnas de la matriz
 *Introducimos la matriz:
 *	1 2 6 7 8
 *	7 6 5 2 2
 *	1 4 2 2 2
 *	8 6 2 5 1
 *	2 2 2 4 3
 *	Borrando la casilla (2,2) con el numero 2
 *	El resultado debe ser:
 *	0 0 0 0 0
 *	1 2 0 0 0
 *	7 6 0 7 8
 *	1 4 6 5 1
 *	8 6 5 4 3
 */
void pruebaBajarColumnaTablero();

/* Rellenamos las celdas vacias de la parte superior de una columna de una matriz
 * con valores aleatorios menores que el mayor valor del tablero
 *Introducimos la matriz:
 *	0 1 2
 *	0 2 2
 *	3 3 3
 */
void pruebaAleatorioColumna();

/* Rellenamos todas las celdas vacias de las columnas del tablero con valores aleatorios
 * Introducimos la matriz:
 * 	0 0 0
 * 	0 8 0
 * 	4 2 1
 */
void pruebaAleatorioTablero();

#endif /* PRUEBATADTABLERO_H_ */
