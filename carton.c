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

struct cartonEstructura{

        int matriz[3][5];
        int bingo, fila, columna;

};



Carton cargarCartonAleatorio (){

Carton cargado= malloc(sizeof(struct cartonEstructura));
int numeroAux;

  for(int i=0;i<FILACARTON;i++){

    for(int j=0;j<COLUMNACARTON;j++){

        do{
            numeroAux=1+rand()%90;

          }while(verificarAleatorio(cargado,numeroAux)==0);

            cargado->matriz[i][j]=numeroAux;
     }
   }
return cargado;
}

int verificarAleatorio(Carton c, int aux){

int disponible=1;

  for(int i=0;i<FILACARTON;i++){

     for(int j=0;j<COLUMNACARTON;j++){

         if(aux==c->matriz[i][j]){

            disponible=0;
            return disponible;
            }
        }
    }

return disponible;

}

Carton cargarCartonManual(){

Carton cargado= malloc(sizeof(struct cartonEstructura));
int numeroAux = 0, pos = 1 ;

 for(int i=0;i<FILACARTON;i++){

        for(int j=0;j<COLUMNACARTON;j++){

            cargado->matriz[i][j]=-1;
        }
 }

 for(int i=0;i<FILACARTON;i++){

        for(int j=0;j<COLUMNACARTON;j++){

            do{

            printf("\nIngrese el %d%c numero del carton: ",pos,167);//167 para que imprima °.
            scanf("%d",&numeroAux);

            }while(verificarRango(numeroAux)==0 ||verificarManual(cargado,numeroAux)==0);




    cargado->matriz[i][j]=numeroAux;
    pos++;

         }
 }
pos=1;
return cargado;
}

int verificarRango(int n){
int disponible=1;

  if((n>90)|(n<1)){

    Color(RED,WHITE);
    printf("\nSu numero(%d) se encuentra fuera del rango(1-90).\nVuelva a intentar por favor.", n);
    Color(BLACK,WHITE);
    disponible=0;
    return disponible;
 }


return disponible;
}

int verificarManual(Carton c, int aux){

int disponible=1;

  for(int i=0;i<FILACARTON;i++){

    for(int j=0;j<COLUMNACARTON;j++){

       if(aux==c->matriz[i][j]){

          Color(RED,WHITE);
          printf("\nEl numero ingresado(%d) ya fue ingresado anteriormente.",aux);
          Color(BLACK,WHITE);
          disponible=0;

        return disponible;
        }

    }
  }

return disponible;

}

void mostrarCarton(Carton c){

    for(int i=0; i<FILACARTON;i++){

        for(int j=0; j<COLUMNACARTON;j++){

            if(c->matriz[i][j]<0){

                Color(RED,WHITE);
                printf("[X]\t");
                Color(BLACK,WHITE);

            }else{

                Color(CYAN,WHITE);
                printf("[%d]\t",c->matriz[i][j]);
                Color(BLACK,WHITE);
            }
        }
        printf("\n");
    }
}

Carton revisarCarton(Carton c, int ultimoNumero){

Carton revisado= malloc(sizeof(struct cartonEstructura));
revisado=c;

    for(int i=0; i<FILACARTON;i++){

        for(int j=0;j<COLUMNACARTON;j++){

            if(revisado->matriz[i][j]==ultimoNumero){

                revisado->matriz[i][j]=ultimoNumero*-1;
            }
        }
    }
    return revisado;
}

void mostrarCartones(Carton c,Carton c2){

int matrizMostrar[3][10];

  for(int i=0; i<FILACARTON;i++){

    for(int j=0; j<COLUMNACARTON;j++){

        matrizMostrar[i][j]=c->matriz[i][j];
        matrizMostrar[i][j+5]=c2->matriz[i][j];
    }
  }

  for(int i=0; i<FILACARTON;i++){

     for(int j=0; j<COLUMNACARTON*2;j++){

        if(j==5){

                printf("\t|\t");
            }
            if(matrizMostrar[i][j]<0){

                    Color(RED,WHITE);
                    printf("[X]\t");
                    Color(BLACK,WHITE);

            }else{

                    Color(CYAN,WHITE);
                    printf("[%d]\t",matrizMostrar[i][j]);
                    Color(BLACK,WHITE);
                }
     }
        printf("\n");
  }

}

Carton ordenarCarton(Carton c){

Carton ordenado= malloc(sizeof(struct cartonEstructura));
ordenado=c;

int tamanio=FILACARTON*COLUMNACARTON;
int contenido[tamanio];
int contadorArreglo=0;
int aux;



 for(int i=0;i<FILACARTON;i++){

    for(int j=0;j<COLUMNACARTON;j++){

            contenido[contadorArreglo]=c->matriz[i][j];
            contadorArreglo++;
    }
 }



  for(int i=0;i<tamanio;i++){

    for(int j=0;j<tamanio-1;j++){

       if(contenido[j]>=contenido[j+1]){

                aux=contenido[j];
                contenido[j]=contenido[j+1];
                contenido[j+1]=aux;
        }
    }
  }


    contadorArreglo=0;

  for(int i=0;i<FILACARTON;i++){

    for(int j=0;j<COLUMNACARTON;j++){

            ordenado->matriz[i][j]=contenido[contadorArreglo];
            contadorArreglo++;
        }
    }
    return ordenado;
}

int bingo(Carton c ){

int bingo=0;
int contadorBingo=0;

   for(int i=0 ;i<FILACARTON;i++){

     for(int j=0 ;j<COLUMNACARTON;j++){

           if(c->matriz[i][j]<0){

            contadorBingo++;
           }
     }
   }

    if (contadorBingo==15){

        bingo=1;
    }

return bingo;
}

int fila(Carton c){

int fila=0;
int contadorFila=0;

  for(int i=0 ;i<FILACARTON;i++){

    for(int j=0 ;j<COLUMNACARTON;j++){

        if(c->matriz[i][j]<0){
                contadorFila++;
            }
    }

    if(contadorFila==5){

        fila=1;

        return fila;
    }
        contadorFila=0;
  }

   return fila;
}

int columna(Carton c){

int columna=0;
int contadorColumna;

  for(int j=0 ;j<COLUMNACARTON;j++){

    for(int i=0 ;i<FILACARTON;i++){

        if(c->matriz[i][j]<0){

                contadorColumna++;
         }
    }

    if(contadorColumna==3){

        columna=1;
        return columna;
    }
    contadorColumna=0;

  }
return columna;
}

int getFila(Carton c){

 return c->fila;
}

int getColumna(Carton c){

return c->columna;
}

int getBingo(Carton c){

return c->bingo;
}

void setFila(Carton c ,int nuevafila){

 c->fila=nuevafila;
}

void setColumna(Carton c ,int nuevaColumna){

 c->columna=nuevaColumna;
}

void setBingo(Carton c ,int nuevoBingo){

 c->bingo=nuevoBingo;
}

void destructorDeCarton(Carton P){

free(P);
}
