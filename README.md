# BlockMerge
## Proyecto realizado para la asignautura IP
Block Merge es un juego para un sólo jugador donde se juega una única partida.
Hay un fichero de configuración donde se determinarán las características del juego. Se juega en tableros cuadrados, tienen el mismo número de filas y de columnas, donde  puede variar entre 4 y 8. Las casillas que forman el tablero tienen, cada una, un número.  El objetivo del juego es conseguir el valor objetivo indicado en el fichero de configuración mediante la fusión de bloques.
El tablero inicial se generará aleatoriamente o se cargará a partir del fichero de configuración.
El jugador utilizará las teclas de los cursores del teclado para desplazarse por el tablero. Al pulsar la tecla Enter se fusionará el bloque al que pertenece la casilla actualmente marcada (si es que forma parte de un bloque), se sustituirá la casilla actual por una con el siguiente valor, caerán las fichas que tengan huecos debajo y se generarán nuevas casillas aleatorias en la parte superior para sustituir a las casillas caídas.
El juego terminará cuando no haya ningún bloque en el tablero, cuando una casilla  alcance el valor objetivo del fichero configuración o cuando el usuario pulse la tecla Escape.
