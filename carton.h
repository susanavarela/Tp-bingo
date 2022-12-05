#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#include "partida.h"
#include "jugador.h"

struct cartonEstructura;
typedef struct cartonEstructura *Carton;


//PRE: necesita una variable tipo estructura donde retornar
//POST: retorna la estructura cargada con numeros aleatorios de tipo entero sin estar repetidos
Carton cargarCartonAleatorio();

//PRE: necesita una estructura tipo carton y un entero, que es el numero a verificar
//POST: retorna un entero tipo bandera para marcar si el entero esta repetido o no
int verificarAleatorio(Carton c, int aux);

//PRE: necesita una variable tipo estructura donde retornar
//POST: retorna la estructura cargada con numeros ingresados por el usuario, de tipo entero sin estar repetidos y dentro del rango
Carton cargarCartonManual();

//PRE: necesita un entero
//POST: retorna un entero tipo bandera que indica si el entero recibido esta o no dentro del rango
int verificarRango(int n);

//PRE: necesita una estructura tipo carton y un entero, que es el numero a verificar
//POST: retorna un entero tipo bandera para marcar si el entero esta repetido o no
int verificarManual(Carton c, int aux);

//PRE:  necesita una estructura tipo carton
//POST: muestra el carton y si estos son menores a cero imprime una x en el lugar
void mostrarCarton(Carton c);

//PRE: necesita una estructura tipo carton y un entero, para verificar si se encuentra en la matriz
//POST: retorna la matriz, si el entero estaba en la matriz este lo pasa a negativo
Carton revisarCarton(Carton c, int ultimoNumero);

//PRE: necesita una variable tipo estructura
//POST: muestra por pantalla las dos etructuras, marcando con una x los numeros negativos (que ya salieron)
void mostrarCartones(Carton c,Carton c2);

//PRE: necesita una variable tipo estructura
//POST: pasa la matriz a un array lo ordena y lo pasa nuevamente a la matriz retornandola ordenada
Carton ordenarCarton(Carton c);

//PRE: necesita una variable tipo estructura
//POST: libera la memoria utilizada en la estructura
void destructorDeCarton(Carton P);

//PRE: necesita una variable tipo estructura
//POST: retorna un entero indicando si todos los numeros de la matriz son negativos o no
int bingo(Carton c );

//PRE: necesita una variable tipo estructura
//POST: retorna un entero indicando si alguna fila de la matriz tiene todos sus numeros negativos o no
int fila(Carton c);

//PRE: necesita una variable tipo estructura
//POST: retorna un entero indicando si alguna columna de la matriz tiene todos sus numeros negativos o no
int columna(Carton c);

//PRE: necesita una variable tipo estructura y necesita una variable tipo entero donde retornar
//POST: retorna un entero que es el valor en este caso de fila
int getFila(Carton c);

//PRE: necesita una variable tipo estructura y necesita una variable tipo entero donde retornar
//POST: retorna un entero que es el valor en este caso de columna
int getColumna(Carton c);

//PRE: necesita una variable tipo estructura y necesita una variable tipo entero donde retornar
//POST: retorna un entero que es el valor en este caso de bingo
int getBingo(Carton c);

//PRE: necesita una variable tipo estructura y un entero
//POST: carga el entero a la variable en este caso de fila que esta dentro de la estructura
void setFila(Carton c ,int nuevafila);

//PRE: necesita una variable tipo estructura y un entero
//POST: carga el entero a la variable en este caso de columna que esta dentro de la estructura
void setColumna(Carton c ,int nuevaColumna);

//PRE: necesita una variable tipo estructura y un entero
//POST: carga el entero a la variable en este caso de bingo que esta dentro de la estructura
void setBingo(Carton c ,int nuevoBingo);


#endif // CARTON_H_INCLUDED
