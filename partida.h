#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED
#include "carton.h"
#include "jugador.h"

struct partidaEstructura;
typedef struct partidaEstructura *Partida;

//PRE: necesita una variable tipo estructura donde retornar
//POST: retorna la estructura cargada con banderas
Partida generarPartida();

//PRE: necesita una variable tipo estructura donde retornar
//POST: retorna una estructura con el array dentro cargado de un numero aleatorios dentro de los rangos establecidos y sin repetir
Partida sacarNumero(Partida p);

//PRE: necesita una array y un entero para revisar
//POST: retorna un entero tipo bandera para marcar si el numero esta repetido o no
int verificarNumeros(int numeros[90], int aux);

//PRE: necesita dos variables del tipo entero
//POST: le da color a lo que muestra por pantalla, ejemplo cartones, cuando se realiza fia, columna, etc
void Color(int Background, int Text);

//PRE: necesita una variable tipo estructura
//POST: libera la memoria utilizada en la estructura
void destructorDepartida(Partida P);

//PRE: necesita tres variables de tipo estructura, dos de jugador y una de partida
//POST: muestra por pantalla los numeros salidos hasta el momento y revisa si el numero que salio esta en los cartones y modifica las banderas
void menuPartida(Partida p,Jugador j,Jugador pcs);

//PRE: necesita tres variables de tipo estructura, dos de jugador y una de partida
//POST: muestra por pantalla el puntaje de la pc y usuario
void mostrarPuntos(Partida p,Jugador j,Jugador pcs);

//PRE: Recibe una partida.
//POST: Retorna la cantidad de numeros cantados.
int getCantNumerosCantados(Partida p);

//PRE: Recibe una partida.
//POST: Retorna un 1 o 0 en caso de haberse hecho bingo o no.
int getBingoPartida(Partida p);

//PRE: Recibe una partida.
//POST: Retorna un 1 o 0 en caso de haberse hecho fila o no.
int getFilaPartida(Partida p);

//PRE: Recibe una partida.
//POST: Retorna un 1 o 0 en caso de haberse hecho columna o no.
int getColumnaPartida(Partida p);

//PRE: Recibe una partida.
//POST: Retorna un entero dependiendo de quien gane.
int getGanadorPartida(Partida p);

//PRE: necesita una variable tipo estructura y un entero
//POST: carga el entero a la variable en este caso de fila que esta dentro de la estructura
void setFilaPartida(Partida j,int nuevafila);

//PRE: necesita una variable tipo estructura y un entero
//POST: carga el entero a la variable en este caso de columna que esta dentro de la estructura
void setColumnaPartida(Partida j,int nuevaColumna);

//PRE: necesita una variable tipo estructura y un entero
//POST: carga el entero a la variable en este caso de bingo que esta dentro de la estructura
void setBingoPartida(Partida j,int nuevoBingo);

#endif // PARTIDA_H_INCLUDED
