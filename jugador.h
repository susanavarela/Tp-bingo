#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "carton.h"
#include "partida.h"

struct jugadorEstructura;
typedef struct jugadorEstructura *Jugador;


//PRE: necesita una variable tipo estructura donde retornar
//POST: retorna una estructura cargada por el usuario, datos personales, cantidad de cartones, banderas y el modo de carga de carton
Jugador pedirDatosUsuario();

//PRE: necesita una variable tipo estructura donde retornar y una variable del tipo entero
//POST: retorna una estructura cargada con banderas para la pc
Jugador cargarPc(int c );

//PRE: necesita una variable tipo estructura
//POST: muestra por pantalla los datos del jugador y el/los carton/es
void mostrarJugador(Jugador j);

//PRE: necesita una variable tipo entero donde retornar
//POST: retorna un entero ingresado por el usuario, en este caso cantidad de cartones
int  pedirCantidadDeCartones();

//PRE: necesita una variable tipo estructura
//POST: libera la memoria utilizada en la estructura
void destructorDeJugador(Jugador j);

//PRE: necesita una variable tipo estructura y una variable del tipo float, tambien una variable float donde retornar
//POST: retorna un float, en este caso es el puntaje calculado dependiendo de la bolilla y lo que se hizo: fila,columna,bingo
float calcularPuntaje(Jugador j, int b);

//PRE: necesita dos variables de tipo estructura y tres variables del tipo entero
//POST: verifica quien hizo fila, columna o bingo y los muestra por pantalla informando quien lo realizo. tambien pausa el juego
void JuegoDeJugadores(Jugador j,Jugador pcs,int e1,int e2,int e3);

//PRE:  necesita dos variables de tipo estructura
//POST: manda a oredenar los numeros dentro de la matriz de las estructuras
void ordenarCartonesUsuarios(Jugador j,Jugador pcs);

//PRE:  necesita dos variables de tipo estructura y una variable del tipo entero
//POST: muestra por pantalla los datos del jugador y pc con sus puntajes
void semiMostrarPuntos(Jugador e1,Jugador e2 ,int cantidad);

//PRE: necesita dos variables de tipo estructura y dos variables del tipo entero
//POST: revisa el carton indicado si tiene ese numero lo pasa a negativo
void revisarSupremo(Jugador e1,Jugador e2,int aux,int k);

//PRE: necesita dos variables de tipo estructura
//POST: guarda en un archivo los datos del jugador con su puntaje
void guardarEnArchivo(Jugador j,Jugador pc);

//PRE: Recibe un Jugador.
//POST: Retorna su nombre.
char* getNombreJugador(Jugador j);

//PRE: Recibe un Jugador.
//POST: Retorna su apellido.
char* getApellidoJugador(Jugador j);

//PRE: Recibe un Jugador.
//POST: Retorna su dni.
char* getDniJugador(Jugador j);

//PRE: Recibe un Jugador.
//POST: Retorna su puntaje.
float getPuntajeJugador(Jugador j);

//PRE: necesita una variable tipo estructura y necesita una variable tipo entero donde retornar
//POST: retorna un entero que es el valor en este caso de fila
int getl1(Jugador c);

//PRE: necesita una variable tipo estructura y necesita una variable tipo entero donde retornar
//POST: retorna un entero que es el valor en este caso de columna
int getl2(Jugador c);

//PRE: necesita una variable tipo estructura y necesita una variable tipo entero donde retornar
//POST: retorna un entero que es el valor en este caso de bingo
int getl3(Jugador c);

//PRE: Recibe un Jugador y array de caracteres.
//POST: Copia el array en la variable nombre de jugador.
void setNombre(Jugador j, char c[]);

//PRE: Recibe un Jugador y array de caracteres.
//POST: Copia el array en la variable apellido de jugador.
void setApellido(Jugador j, char c[]);

//PRE: Recibe un Jugador y array de caracteres.
//POST: Copia el array en la variable dni de jugador.
void setDni(Jugador j, char c[]);

//PRE: Recibe un Jugador y un flotante.
//POST: Copia el flotante en la variable puntaje de jugador.
void setPuntaje(Jugador j, float f);

//PRE: necesita una variable tipo estructura
//POST: carga el entero a la variable en este caso de cantidad de cartones que esta dentro de la estructura
void setCantidadDeCartones(Jugador j, int c);

#endif // JUGADOR_H_INCLUDED
