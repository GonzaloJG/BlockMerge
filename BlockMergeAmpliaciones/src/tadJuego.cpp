/*
 * tadJuego.cpp
 *
 *  Created on: 28 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#include "tadJuego.h"

bool iniciarJuego(Juego &j){
	bool inicioCorrecto;

	int tamano, obj, d, m[MAX_TAMANO][MAX_TAMANO];

	inicioCorrecto=entornoCargarConfiguracion(tamano, obj, d, m);

	if (inicioCorrecto){
		ponerTamanoTablero(j.tablero, tamano);
		j.objetivo=obj;
		if (d==0){
			iniciarConMatriz(j.tablero, tamano, m);
		} else{
			if (d>0){
				iniciarTablero(j.tablero, d);
			}
		}

	}
	return inicioCorrecto;
}

void gestionDelJuego(Juego &j){
	int tam;
	tam=obtenerTamanoTablero(j.tablero);
if (tam>=4 && tam<=8){
	if (iniciarJuego(j)){
		entornoIniciar(tam); //se inicia el entorno gráfico

		//se visualizan en el entorno gráfico los valores extraídos del
		//fichero de conf. y almacenados en la matriz m
		int fila, col, aux, max, cuantos;
		int puntuacion;
		puntuacion=0;
				for ( fila = 0; fila < tam; fila++) {
					for ( col = 0; col < tam; col++) {
						entornoPonerNumero(fila, col, obtenerValorCasilla(j.tablero, fila, col));
					}
				}

				entornoPonerObjetivo(j.objetivo);
				entornoPonerPuntuacion(puntuacion);
				//Las casilla con valor mas alto aparece resaltada cuando inicializamos el tablero
				max=valorMaximo(j.tablero);
				for ( fila = 0; fila < tam; fila++) {
					for ( col = 0; col < tam; col++) {
						if (obtenerValorCasilla(j.tablero, fila, col)==max){
							entornoPonerNumeroResaltado(fila, col);
						}
					}
				}

						bool salir = false; //bandera utilizada para finalizar el bucle
						int s; //identificador de salida
						TipoTecla tecla;    //almacena la tecla pulsada por el usuario

						fila = 0;
						col  = 0;
						entornoMarcarPosicion(fila,col);
						entornoMostrarMensaje("Pulsa ESC para salir",1.5);

						//el bucle permite al jugador desplazarse por el tablero de juego
						while (!salir) {
							tecla = entornoLeerTecla();
							switch (tecla) {
							case TEnter:
								//Comprobamos que esa casilla tiene bloque
								if (hayBloque(j.tablero, fila, col)){

									//Guardamos el valor original
									aux=obtenerValorCasilla(j.tablero, fila, col);
									//vaciamos el bloque en el tablero
									vaciarBloque(j.tablero, fila, col, obtenerValorCasilla(j.tablero, fila, col));

									cuantos=0;
									//Vaciar celdas borradas del bloque en el entorno y contamos las celdas que tiene el bloque
									int f, c;
									for (f=0; f<tam; f++){
										for (c=0; c<tam; c++){
											if(obtenerValorCasilla( j.tablero, f, c)==0){
												entornoPonerVacio(f, c);
												cuantos=cuantos+1;
											}
										}
									}

									//En la casilla seleccionada ponemos el valor original +1
									ponerValorTablero(j.tablero, fila, col, aux+1);
									entornoPonerNumero(fila,col, obtenerValorCasilla(j.tablero, fila, col));

									//Las casillas caen poniendo los huecos vacios encima
									bajarColumnaTablero(j.tablero);

									//Las casillas vacias se rellenan con valores aleatorios
									aleatorioTablero(j.tablero);

									//Mostramos de nuevo el tablero ya que ha sido modificado
									for ( f = 0; f < tam; f++) {
										for ( c = 0; c < tam; c++) {
											entornoPonerNumero(f, c, obtenerValorCasilla(j.tablero, f, c));
										}
									}
								}

								//Actualizamos la casilla con valor mas alto y si hay mas de una tambien se resalta
								int fil, co;
								max=valorMaximo(j.tablero);
								for ( fil = 0; fil < tam; fil++) {
									for ( co = 0; co < tam; co++) {
										if (obtenerValorCasilla(j.tablero, fil, co)==max){
												entornoPonerNumeroResaltado(fil, co);
										}
									}
								}

								//Actualizar la puntuacion
								puntuacion=puntuacion+(aux*cuantos);
								entornoPonerPuntuacion(puntuacion);

								//Para terminar cuando no hay mas bloques en el tablero
								if (!hayBloqueTablero(j.tablero)){
									salir=true;
									s=1;
								}
								//Para terminar cuando se ha conseguido el objetivo
								if (valorMaximo(j.tablero)==j.objetivo){
									salir=true;
									s=2;
								}

								break;
							case TDerecha:
								entornoDesmarcarPosicion(fila, col);
								if (col < tam - 1)
										col++;
								else
										col = 0;
								entornoMarcarPosicion(fila, col);
								break;
							case TIzquierda:
								entornoDesmarcarPosicion(fila, col);
								if (col > 0)
									col--;
								else
									col = tam - 1;
								entornoMarcarPosicion(fila, col);
								break;
							case TArriba:
								entornoDesmarcarPosicion(fila, col);
								if (fila > 0)
									fila--;
								else
									fila = tam - 1;
								entornoMarcarPosicion(fila, col);
								break;
							case TAbajo:
								entornoDesmarcarPosicion(fila, col);
								if (fila < tam - 1)
									fila++;
								else
									fila = 0;
								entornoMarcarPosicion(fila, col);
								break;

							case TSalir:
								salir = true;
								s=0;
								break;

							case TNada:
								break;
							} //Fin de switch
						}//Fin de while

					switch(s){
					case 0:
						entornoMostrarMensajeFin("Has abandonado");
						break;
					case 1:
						entornoMostrarMensajeFin("Sin movimientos");
						break;
					case 2:
						entornoMostrarMensajeFin("Enhorabuena");
						break;
					}
					entornoTerminar();
					}//Fin de if
	}
}
