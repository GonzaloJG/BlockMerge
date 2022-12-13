/*
 * pruebatadTablero.cpp
 *
 *  Created on: 25 dic. 2019
 *      Author: Gonzalo Jiménez Gómez
 */

#include "pruebatadTablero.h"

void pruebaIniciarTablero(){
	cout<<"INICIO: prueba iniciarTablero"<<endl;
	Tablero t;
	t.ocupadas=3;
	iniciarTablero(t,8);

	int fila, col;
	for (fila=0; fila<t.ocupadas; fila++){
		for (col=0; col<t.ocupadas; col++){
			cout<< obtenerValor(t.matriz[fila][col])<<endl;
		}
	}
cout<<"FIN: prueba iniciarTablero"<<endl;
}

void pruebainiciarConMatriz(){
	cout<<"INICIO: prueba iniciarConMatriz"<<endl;
	Tablero t;
	int matriz[MAX][MAX];
	int fila, col, num;
		for (fila=0; fila<3; fila++){
			for (col=0; col<3; col++){
				cin >> num;
					matriz[fila][col]=num;
			}
		}

	iniciarConMatriz(t,3,matriz);


		for (fila=0; fila<t.ocupadas; fila++){
			for (col=0; col<t.ocupadas; col++){
				cout<< obtenerValor(t.matriz[fila][col])<<endl;
			}
		}
	cout<<"FIN: prueba iniciarConMatriz"<<endl;
}

void pruebaObtenerTamanoTablero(){
	cout<<"INICIO: prueba obtenerTamanoTablero"<<endl;
	Tablero t;
	t.ocupadas=4;
	if (obtenerTamanoTablero(t)!=4){
		cout<<"Error en la prueba obtenerTamanoTablero"<<endl;
	}
	cout<<"FIN: prueba obtenerTamanoTablero"<<endl;
}

void pruebaSonCoordenadasValidas(){
	cout<<"INICIO: prueba sonCoordenadasValidas"<<endl;
	Tablero t;
	t.ocupadas=6;
	if (sonCoordenadasValidas(4,3, t.ocupadas)!=true){
		cout<<"Error en la prueba 1 sonCoordenadasValidas"<<endl;
	}
	if (sonCoordenadasValidas(2,2, t.ocupadas)!=true){
		cout<<"Error en la prueba 2 sonCoordenadasValidas"<<endl;
	}
	if (sonCoordenadasValidas(5,1, t.ocupadas)!=true){
		cout<<"Error en la prueba 3 sonCoordenadasValidas"<<endl;
	}
	cout<<"FIN: prueba sonCoordenadasValidas"<<endl;
}

void pruebaPonerValorTablero(){
	cout<<"INICIO: prueba ponerValorTablero"<<endl;
	Tablero t;

	ponerValorTablero(t, 0, 0, 3);
	ponerValorTablero(t, 1, 2, 6);
	ponerValorTablero(t, 3, 2, 1);

	if (obtenerValorCasilla(t,0,0)!=3){
		cout<<"Error en la prueba 1 ponerValorTablero o obtenerValorCasilla"<<endl;
	}

	if (obtenerValorCasilla(t,1,2)!=6){
			cout<<"Error en la prueba 2 ponerValorTablero o obtenerValorCasilla"<<endl;
		}

	if (obtenerValorCasilla(t,3,2)!=1){
			cout<<"Error en la prueba 3 ponerValorTablero o obtenerValorCasilla"<<endl;
		}

	cout<<"FIN: prueba ponerValorTablero"<<endl;
}

void pruebaVaciarCasillaTablero(){
	cout<<"INICIO: prueba vaciarCasillaTablero"<<endl;
	Tablero t;
	//vaciamos las casillas:
	vaciarCasillaTablero(t,0,0);
	vaciarCasillaTablero(t,2,2);
	vaciarCasillaTablero(t,3,1);

	if (casillaVacia(t,0,0)!=true){
		cout<<"Error en la prueba 1 vaciarCasillaTablero o casillaVacia"<<endl;
	}
	if (casillaVacia(t,2,2)!=true){
			cout<<"Error en la prueba 2 vaciarCasillaTablero o casillaVacia"<<endl;
		}
	if (casillaVacia(t,3,1)!=true){
			cout<<"Error en la prueba 3 vaciarCasillaTablero o casillaVacia"<<endl;
		}
	cout<<"FIN: prueba vaciarCasillaTablero"<<endl;
}

void pruebaHayBloque(){
	cout<<"INICIO: prueba hayBloque"<<endl;
	Tablero t;
	int fila, col, num;
			for (fila=0; fila<3; fila++){
				for (col=0; col<3; col++){
					cin >> num;
					ponerValorTablero(t, fila, col, num);
				}
			}

	if (hayBloque(t, 0, 1)!=true){
		cout<<"Error en la prueba hayBloque"<<endl;
	}
	cout<<"FIN: prueba hayBloque"<<endl;
}

void pruebaHayBloqueTablero(){
	cout<<"INICIO: prueba hayBloqueTablero"<<endl;
	Tablero t;
	ponerTamanoTablero(t, 3);
	int fila, col, num;
				for (fila=0; fila<3; fila++){
					for (col=0; col<3; col++){
						cin >> num;
						ponerValorTablero(t, fila, col, num);
					}
				}

		if (hayBloqueTablero(t)!=true){
			cout<<"Error en la prueba hayBloqueTablero"<<endl;
		}

	cout<<"FIN: prueba hayBloqueTablero"<<endl;
}

void pruebaValorMaximo(){
	cout<<"INICIO: prueba valorMaximo"<<endl;
	Tablero t;
		ponerTamanoTablero(t, 3);
		int fila, col, num;
		for (fila=0; fila<3; fila++){
			for (col=0; col<3; col++){
				cin >> num;
				ponerValorTablero(t, fila, col, num);
			}
		}

		cout<<"El valor Maximo es:"<<endl;
		cout<<valorMaximo(t)<<endl;

		cout<<"FIN: prueba valorMaximo"<<endl;
}

void pruebaVaciarBloque(){
	cout<<"INICIO: prueba vaciarBloque"<<endl;
		Tablero t;
			ponerTamanoTablero(t, 3);
			int fila, col, num;
			for (fila=0; fila<3; fila++){
				for (col=0; col<3; col++){
					cin >> num;
					ponerValorTablero(t, fila, col, num);
				}
			}

			vaciarBloque(t, 0, 1, 3);

			for (fila=0; fila<3; fila++){
				for (col=0; col<3; col++){
					cout<<obtenerValorCasilla(t, fila, col)<<endl;;
				}
			}

			cout<<"FIN: prueba vaciarBloque"<<endl;
}

void pruebaBajarColumna(){
	cout<<"INICIO: prueba bajarColumna"<<endl;
		Tablero t;
		ponerTamanoTablero(t, 3);
		int fila, col, num;
			for (fila=0; fila<3; fila++){
				for (col=0; col<3; col++){
						cin >> num;
						ponerValorTablero(t, fila, col, num);
					}
				}

				vaciarBloque(t, 1, 0, 1);
				bajarColumna(t, 0);

				for (fila=0; fila<3; fila++){
					for (col=0; col<3; col++){
						cout<<obtenerValorCasilla(t, fila, col)<<endl;;
					}
				}

	cout<<"FIN: prueba bajarColumna"<<endl;

}

void pruebaBajarColumnaTablero(){
	cout<<"INICIO: prueba bajarColumnaTablero"<<endl;
		Tablero t;
		ponerTamanoTablero(t, 5);
		int fila, col, num;
			for (fila=0; fila<5; fila++){
				for (col=0; col<5; col++){
						cin >> num;
						ponerValorTablero(t, fila, col, num);
					}
				}

				vaciarBloque(t, 2, 2, 2);
				bajarColumnaTablero(t);

				for (fila=0; fila<5; fila++){
					for (col=0; col<5; col++){
						cout<<obtenerValorCasilla(t, fila, col)<<endl;;
					}
				}

	cout<<"FIN: prueba bajarColumnaTablero"<<endl;
}

void pruebaAleatorioColumna(){
	cout<<"INICIO: prueba aleatorioColumna"<<endl;
			Tablero t;
			ponerTamanoTablero(t, 3);
			int fila, col, num;
				for (fila=0; fila<3; fila++){
					for (col=0; col<3; col++){
							cin >> num;
							ponerValorTablero(t, fila, col, num);
						}
					}

				aleatorioColumna(t,0);

					for (fila=0; fila<3; fila++){
						for (col=0; col<3; col++){
							cout<<obtenerValorCasilla(t, fila, col)<<endl;;
						}
					}

		cout<<"FIN: prueba aleatorioColumna"<<endl;
}

void pruebaAleatorioTablero(){
	cout<<"INICIO: prueba aleatorioTablero"<<endl;
				Tablero t;
				ponerTamanoTablero(t, 3);
				int fila, col, num;
					for (fila=0; fila<3; fila++){
						for (col=0; col<3; col++){
								cin >> num;
								ponerValorTablero(t, fila, col, num);
							}
						}

					aleatorioTablero(t);

						for (fila=0; fila<3; fila++){
							for (col=0; col<3; col++){
								cout<<obtenerValorCasilla(t, fila, col)<<endl;;
							}
						}

			cout<<"FIN: prueba aleatorioTablero"<<endl;
}
