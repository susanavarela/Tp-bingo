#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include "partida.h"
#include "jugador.h"
#include "carton.h"
#define COLUMNACARTON 5
#define FILACARTON 3
#define BOLILLAS 90

enum Colors {
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};

struct partidaEstructura{
       int numerosCantados[BOLILLAS];
       int cantNumerosCantados;
       int bingo;
       int fila;
       int columna;
       int ganador;
};



void Color(int Background, int Text){

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
int New_Color= Text + (Background * 16);

SetConsoleTextAttribute(Console, New_Color);

}

Partida generarPartida(){

Partida p= malloc(sizeof(struct partidaEstructura));

p->cantNumerosCantados=0;
p->bingo=0;
p->fila=0;
p->columna=0;


return p;
};

Partida sacarNumero(Partida p){

Partida nuevoNro= malloc(sizeof(struct partidaEstructura));
nuevoNro= p;

int numeroAux,mini=1, maxi=BOLILLAS;

    do{
        numeroAux=mini+rand()%maxi;

      }while(verificarNumeros(nuevoNro->numerosCantados,numeroAux)==0);

nuevoNro->numerosCantados[nuevoNro->cantNumerosCantados]=numeroAux;
nuevoNro->cantNumerosCantados++;

return nuevoNro;
}

int verificarNumeros(int numeros[BOLILLAS], int aux){

int disponible=1;

  for(int i=0; i<BOLILLAS; i++){

     if(numeros[i]==aux){

        disponible=0;
        return disponible;
     }
  }
return disponible;
}

void destructorDepartida(Partida p){

free(p);
}

void menuPartida(Partida p,Jugador j,Jugador pcs){

do{
    printf("------------------------------------------------------------------------------------------------");

    p=sacarNumero(p);

    Color(WHITE,BLACK);
    printf("\nSalio el %d.",p->numerosCantados[p->cantNumerosCantados-1]);
    Color(BLACK,WHITE);

    if(p->cantNumerosCantados<90){

        printf("\n\nQuedan %d numeros en la bolsa.\n",BOLILLAS-p->cantNumerosCantados);

    }else{
        printf("\nYa no quedan mas numeros en la bolsa!\n");
         }


    for(int i=0;i<getCantidadDeCartones(j);i++){

        int aux12= p->numerosCantados[p->cantNumerosCantados-1];
        revisarSupremo( j, pcs, aux12,i);
        p->numerosCantados[p->cantNumerosCantados-1]=aux12;

    }



int auxl=0;
int auxll=0;
int auxlll=0;
JuegoDeJugadores(j,pcs,auxl,auxll,auxlll);
p->fila= getl1(j);
p->columna=getl2(j);
p->bingo=getl3(j);

}while((p->bingo)==0);
}

void mostrarPuntos(Partida p,Jugador j,Jugador pcs){

Color(CYAN,RED);
printf("\n\nPUNTOS\nColumna=10pts.\nFila=20pts.\nBinco=70pts.");
Color(BLACK,WHITE);
printf("\n------------------------------------------------------------------------------------------------\n");
Color(BLUE,WHITE);
printf("PUNTAJE FINAL.\n");

int cantidad=0;
cantidad=p->cantNumerosCantados;
semiMostrarPuntos( j, pcs , cantidad);

}

int getCantNumerosCantados(Partida p){
    return p->cantNumerosCantados;
}

int getBingoPartida(Partida p){
    return p->bingo;
}

int getFilaPartida(Partida p){
    return p->fila;
}

int getColumnaPartida(Partida p){
    return p->columna;
}

int getGanador(Partida p){
    return p->ganador;
}

void setFilaPartida(Partida j,int nuevafila){

j->fila=nuevafila;
}

void setColumnaPartida(Partida j,int nuevaColumna){

j->columna=nuevaColumna;
}

void setBingoPartida(Partida j,int nuevoBingo){

j->bingo=nuevoBingo;
}
