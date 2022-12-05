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

struct jugadorEstructura{

        char nombre[20], apellido[20],dni[10];
        float puntaje;
        int cantidadDeCartones;
        int l1,l2,l3;
        Carton cartones[3];
};



Jugador pedirDatosUsuario(){

Jugador j= malloc(sizeof(struct jugadorEstructura));

char auxNombre[20]=" ";
char auxApellido[20]=" ";
char auxDni[10]=" ";
int opcionCarga, control=-1;

    printf("Ingrese sus datos.\n");
    printf("\nNombre: ");
    fflush(stdin);
    gets(auxNombre);
    strcpy(j->nombre, auxNombre);

    printf("\nApellido: ");
    fflush(stdin);
    gets(auxApellido);
    strcpy(j->apellido,auxApellido);

    printf("\nD.N.I: ");
    fflush(stdin);
    gets(auxDni);
    strcpy(j->dni, auxDni);

    j->puntaje=0;

    j->cantidadDeCartones=pedirCantidadDeCartones();



    j->l1=0;
    j->l2=0;
    j->l3=0;

do{
       printf("\nCarga de cartones");
       printf("\n1-Cargarlos aleatoriamente.");
       printf("\n2-Cargarlos Manualmente.\n");
       printf("Como desea cargar sus cartones? ");
       scanf("%d", &opcionCarga);

    switch(opcionCarga){

         case 1: for(int i=0;i<j->cantidadDeCartones;i++){
                     j->cartones[i]=cargarCartonAleatorio();
                   } control=1;break;

         case 2: for(int i=0;i<j->cantidadDeCartones;i++){
                     printf("\nCARTON N%c %d",167,i+1);
                     j->cartones[i]=cargarCartonManual();
                  } control=1;break;

        default: Color(RED,WHITE);
                printf("\nLa opcion ingresada no es correcta.\nVuelva a intentar.\n");
                Color(BLACK,WHITE);
    }
}while(control==-1);
return j;
}

Jugador cargarPc(int c ){

Jugador t= malloc(sizeof(struct jugadorEstructura));

strcpy(t->nombre,"Pc");
strcpy(t->apellido,"gamer");
strcpy(t->dni,"10101010");
t->cantidadDeCartones=c;
t->puntaje=0;

    for(int i=0;i<c;i++){

        t->cartones[i]=cargarCartonAleatorio();
        setFila(t->cartones[i],0);
        setColumna(t->cartones[i],0);
        setBingo(t->cartones[i],0);
    }
return t;
}

void mostrarJugador(Jugador j){

Color(WHITE,BLACK);printf("\nDATOS DEL JUGADOR\n");
Color(BLACK,WHITE);printf("\nNombre: %s\nApellido: %s\nD.N.I: %s\nCantidad de cartones: %d\n", j->nombre,j->apellido,j->dni,j->cantidadDeCartones);

 for(int i=0;i<j->cantidadDeCartones;i++){
    Color(BLUE,WHITE);
    printf("\nCARTON N%c %d\n",167,i+1);
    mostrarCarton(j->cartones[i]);
    printf("\n");
  }
}

int  pedirCantidadDeCartones(){

int contador=0;
int cantidadDeC=0;
int aux=0;

  do{
     printf("\nCon cuantos cartones desea jugar?(1,2 o 3): ");
     scanf("%d",&aux);

     switch(aux){
                case 1:cantidadDeC=1;contador=1;break;
                case 2:cantidadDeC=2;contador=1;break;
                case 3:cantidadDeC=3;contador=1;break;
                default:Color(RED,WHITE);
                printf("\nLA CANTIDAD INGRESADA ES INCORRECTA.\nPor favor vuelva a intentar.\n\n");
                Color(BLACK,WHITE);
     }

  }while(contador==0);


 return cantidadDeC;}

void destructorDeJugador(Jugador j){

 free(j);
}

float calcularPuntaje(Jugador j, int b){

int auxfila=0;
int auxcolumna=0;
int auxbingo=0;
float puntaje=0;
int auxx=0;
auxx=j->cantidadDeCartones;

for(int i=0; i<auxx; i++){

    auxfila=getFila(j->cartones[i]);
    auxcolumna=getColumna(j->cartones[i]);
    auxbingo=getBingo(j->cartones[i]);

   if(auxfila==1){
      puntaje=puntaje+20;
    }

   if(auxcolumna==1){
      puntaje=puntaje+10;
    }

   if(auxbingo==1){
      puntaje=puntaje+70;
    }
}

if(b<30){

  printf("%f",puntaje);
  puntaje=puntaje*2;
  printf("puntaje*2");

}else{

    if(b<50){
        puntaje=puntaje*1.7;
     }else{
           if(b<70){
              puntaje=puntaje*1.5;
            }
      }
 }

return puntaje;
}


 void JuegoDeJugadores(Jugador j,Jugador pcs,int e1,int e2,int e3){

Color(BLACK,LGREEN);
printf("\nCARTON/ES USUARIO\t\t\t\t\tCARTON/ES PC\t\t\t\t");

 for(int i=0;i<j->cantidadDeCartones;i++){

    Color(BLUE,WHITE);
    printf("\nCARTON N%c %d\t\t\t\t\t\tCARTON N%c %d\t\t\t\t",167,i+1,167,i+1);
    Color(BLACK,WHITE);
    printf("\n");
    mostrarCartones(j->cartones[i],pcs->cartones[i]);
    printf("\n");
 }

if(j->l1==0){

  for(int i=0;i<j->cantidadDeCartones;i++){

    int aux1=0;
    aux1=fila(j->cartones[i]);
    int aux2=fila(pcs->cartones[i]);
    setFila(j->cartones[i],aux1);
    setFila(pcs->cartones[i],aux2);

      if((getFila(j->cartones[i])==1) | (getFila(pcs->cartones[i])==1)){

            j->l1=1;

         if(getFila(j->cartones[i])==1){

                    Color(YELLOW,BLACK);
                    printf("\n\n¡Felicidades, hiciste fila!\n\n");
                    setFila(pcs->cartones[i],0);

          }else{
                    Color(MAGENTA,WHITE);
                    printf("\n\n¡LA PC ACABA DE HACER FILA!\n\n");
                    setFila(j->cartones[i],0);
            }
           i=j->cantidadDeCartones;
    }

    }
}

if(j->l2==0){

  for(int i=0;i<j->cantidadDeCartones;i++){

      setColumna(j->cartones[i],columna(j->cartones[i]));
      setColumna(pcs->cartones[i],columna(pcs->cartones[i]));

       if((getColumna(j->cartones[i])==1) | (getColumna(pcs->cartones[i])==1)){

          j->l2=1;

            if(getColumna(j->cartones[i])==1){

                Color(YELLOW,BLACK);
                printf("\n\n¡Felicidades, hiciste columna!\n\n");
                setColumna(pcs->cartones[i],0);

                }else{

                    Color(MAGENTA,WHITE);
                    printf("\n\n¡LA PC ACABA DE HACER COLUMNA!\n\n");
                    setColumna(j->cartones[i],0);

                 }
          i=j->cantidadDeCartones;
        }

  }
}
if(j->l3==0){

    for(int i=0;i<j->cantidadDeCartones;i++){

        setBingo(j->cartones[i],bingo(j->cartones[i]));   setBingo(pcs->cartones[i],bingo(pcs->cartones[i]));
        setBingo(pcs->cartones[i],bingo(pcs->cartones[i]));;

         if((getBingo(j->cartones[i])==1) | (getBingo(pcs->cartones[i])==1)){

             j->l3=1;

              if(getBingo(j->cartones[i])==1){

                Color(YELLOW,BLACK);
                printf("\n\n¡Felicidades, hiciste bingo!\n\n¡¡GANASTE!!");
                setBingo( pcs->cartones[i],0);

                }else{

                    Color(MAGENTA,WHITE);
                    printf("\n\n¡LA PC ACABA DE HACER BINGO!\n\n¡¡PERDISTE!!");
                    setBingo( j->cartones[i],0);
                }
            i=j->cantidadDeCartones;
          }

    }
    Color(BLACK,WHITE);
}


system("pause");
}

 void ordenarCartonesUsuarios(Jugador j,Jugador pcs){

    for(int i=0;i<j->cantidadDeCartones;i++){

        j->cartones[i]=ordenarCarton(j->cartones[i]);
        pcs->cartones[i]=ordenarCarton(pcs->cartones[i]);
    }

}

void semiMostrarPuntos(Jugador e1,Jugador e2 ,int cantidad){

float auxx=0;
float auxxx=0;

auxxx=calcularPuntaje(e2,cantidad);
auxx=calcularPuntaje(e1,cantidad);
e1->puntaje=auxx;
e2->puntaje=auxxx;
Color(YELLOW,BLACK);
printf("%s %s\n",e1->nombre, e1->apellido);
printf("%.2f\n",e1->puntaje);
Color(MAGENTA,WHITE);
printf("\nPC\n");
printf("%.2f\n",e2->puntaje);
Color(BLACK,WHITE);
printf("\n------------------------------------------------------------------------------------------------\n");


}

void revisarSupremo(Jugador e1,Jugador e2,int aux,int k){

            e1->cartones[k]=revisarCarton(e1->cartones[k],aux);
            e2->cartones[k]=revisarCarton(e2->cartones[k],aux);


}

char* getNombreJugador(Jugador j){
    return j->nombre;
}

char* getApellidoJugador(Jugador j){
    return j->apellido;
}

char* getDniJugador(Jugador j){
    return j->dni;
}

float getPuntajeJugador(Jugador j){
    return j->puntaje;
}

int getCantidadDeCartones(Jugador c){
return c->cantidadDeCartones;
}

int getl1(Jugador c){

 return c->l1;
}

int getl2(Jugador c){

return c->l2;
}

int getl3(Jugador c){

return c->l3;

}


void setNombre(Jugador j, char c[]){
    strcpy(j->nombre,c);
}

void setApellido(Jugador j, char c[]){
    strcpy(j->apellido,c);
}

void setDni(Jugador j, char c[]){
    strcpy(j->dni,c);
}

void setPuntaje(Jugador j, float f){
    j->puntaje=f;
}

void setCantidadDeCartones(Jugador j, int c){

j->cantidadDeCartones=c;
}


void guardarEnArchivo(Jugador j,Jugador pc){

FILE *puntero;
puntero=fopen("archivoRanking.txt","a");

if(j->puntaje > pc->puntaje){

    fprintf(puntero,"%s;%s;%s;%.2f\n",j->nombre,j->apellido,j->dni,j->puntaje);

}else{

    fprintf(puntero,"%s;%s;%s;%.2f\n",pc->nombre,pc->apellido,pc->dni,pc->puntaje);
 }

  fclose(puntero);

 }
