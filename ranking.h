#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED
#include "carton.h"
#include "jugador.h"
#include "partida.h"

struct RankingEstructura;
typedef struct RankingEstructura *Ranking;

//PRE: necesita una variable tipo estructura donde retornar
//POST: retorna una estructura con banderas
Ranking crearRacking();

//PRE: necesita una variable array de estructura
//POST: retorna un array de estructuras cargado con banderas
void crearRackings(Ranking r[]);

//PRE: necesita una variable array de estructura
//POST: lee el archivo y carga las estructuras del array con el
void leerArchivo(Ranking r[]);

//PRE: necesita una variable array de estructura
//POST: carga los datos indicados en un archivo
void guardarEnArchivoRanking(Ranking r[]);

//PRE: necesita una variable array de estructura
//POST: ordena el array de estructura dependiendo de la variable puntaje
void ordenar(Ranking r[]);

//PRE: necesita una variable del tipo char (cadena) y una variable tipo estructura donde retornar
//POST: retorna una estructura con los datos del char recibido
Ranking CargarDatosDeArchivos(char r[]);

//PRE: necesita una variable array de estructura
//POST: retorna un entero como bandera avisando si el array tiene una posicion disponible o no
int buscarPosDisponible(Ranking r[]);

//PRE: necesita una variable de estructura y un array del mismo tipo
//POST: carga la estructura en el array de estructuras si encuentra una posicion
void agregarRacking(Ranking r[],Ranking j);

//PRE: Recibe un "Ranking".
//POST: Libera la memoria utilizada.
void destructorDeRanking(Ranking r);

//PRE: Recibe un array de "Ranking".
//POST: Libera la memoria utilizada.
void destructorDeRankings(Ranking r[]);

//PRE: Recibe un "ranking".
//POST: retorna su nombre.
char* getNombreRanking(Ranking r);

//PRE: Recibe un "ranking".
//POST: retorna su apellido.
char* getApellidoRanking(Ranking r);

//PRE: Recibe un "ranking".
//POST: retorna su dni.
char* getDniRanking(Ranking r);

//PRE: Recibe un "ranking".
//POST: retorna su puntaje.
float getPuntajeRanking(Ranking r);

//PRE: Recibe un "ranking" y un array de caracteres.
//POST: Carga el array en la variable nombre de la estructura.
void setNombreRanking(Ranking r, char c[]);

//PRE: Recibe un "ranking" y un array de caracteres.
//POST: Carga el array en la variable apellido de la estructura.
void setApellidoRanking(Ranking r, char c[]);

//PRE: Recibe un "ranking" y un array de caracteres.
//POST: Carga el array en la variable dni de la estructura.
void setDniRanking(Ranking r, char c[]);

//PRE: Recibe un "ranking" y un flotante.
//POST: Carga el array en la variable puntaje de la estructura.
void setPuntajeRanking(Ranking r, float f);

#endif // RANKING_H_INCLUDED
