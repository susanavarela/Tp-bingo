#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include "partida.h"
#include "jugador.h"
#include "carton.h"
#include "ranking.h"
#define COLUMNACARTON 5
#define FILACARTON 3
#define BOLILLAS 90

struct RankingEstructura{
        char nombre[20];
        char apellido[20];
        char dni[10];
        float puntaje;

};



Ranking crearRacking(){

Ranking r = malloc(sizeof(struct RankingEstructura));

char aux[40]="xxx";
strcpy(r->dni,aux);
char aux1[40]="xxx";
strcpy(r->nombre,aux1);
char auxApellido[20]="xxx";
strcpy(r->apellido,auxApellido);
r->puntaje=-1;


return r;
}

void crearRackings(Ranking r[]){

for(int i=0;i<10;i++){

   r[i]=crearRacking();

}

}

void leerArchivo(Ranking r[]){


FILE *puntero;
puntero = fopen("archivoRanking.txt","r");

while(!feof(puntero)){

     char aux[60] =" ";
     fgets(aux,60,puntero);

     Ranking ejemplo=CargarDatosDeArchivos(aux);

     agregarRacking(r,ejemplo);

}

fclose(puntero);
}

void agregarRacking(Ranking r[],Ranking j){

 int i=buscarPosDisponible(r);

 if(i!=-9){
    r[i]=j;

 }else{printf("no hay pos disponible \n");
           }

}

int buscarPosDisponible(Ranking r[]){

int posicion = -9;
int i = 0;

while(posicion==-9&&i<10){

     if(r[i]->puntaje ==-1){

            posicion = i;
      }

    i++;
}

return posicion;
}

Ranking CargarDatosDeArchivos(char r[]){

Ranking p=malloc(sizeof(struct RankingEstructura));

int pos=0;
int pos2=0;
int pos3=0;
char auxdni[60] = " ";
char auxnombre[60] = " ";
char auxApellido[60]= " ";
char auxpuntaje[60] = " ";


for(int i=0; i<60; i++){
    if(r[i]==';'){
      pos=i;
      i=60;
    }
}

for(int i=pos+1;i<60;i++){
    if(r[i]==';'){
      pos2=i;
      i=60;
    }
}

for(int i=pos2+1;i<60;i++){
    if(r[i]==';'){
      pos3=i;
      i=60;
    }
}


for(int i=0;i<pos;i++){

    auxnombre[i]=r[i];

}

for(int i=pos+1;i<pos2;i++){

    auxApellido[i-pos-1]=r[i];
}

for(int i=pos2+1;i<pos3;i++){

    auxdni[i-pos2-1]=r[i];
}

for(int i=pos3+1;i<60;i++){

    auxpuntaje[i-pos3-1]=r[i];
}

strcpy(p->nombre,auxnombre);
strcpy(p->apellido,auxApellido);
strcpy(p->dni,auxdni);
p->puntaje = atof(auxpuntaje);

return p;
};

void ordenar(Ranking r[]){

Ranking aux;

for ( int i = 0; i<10; i++){

    for(int j =0; j<10-1;j++){

        if(r[j]->puntaje  <  r[j+1]->puntaje){

            aux = r[j];
            r[j]=r[j+1];
            r[j+1]=aux;
          }
       }
}
}

void guardarEnArchivoRanking(Ranking r[]){

FILE *puntero;
puntero=fopen("archivoRanking.txt","w");

ordenar(r);

for(int i=0;i<10;i++){

  if((r[i]->puntaje!=-1)&(r[i]->puntaje!=0)){

     fprintf(puntero,"%s;%s;%s;%.2f\n",r[i]->nombre,r[i]->apellido,r[i]->dni,r[i]->puntaje);
   }
}
 fclose(puntero);
}

void mostrarRanking(Ranking r[]){

Color(3,15);
printf("\n\n------------------------BIENVENIDO AL RANKING-------------------------------------\n\n");
Color(5,15);
printf("\nPUESTO\t\tNOMBRE\t\tAPELLIDO\t\tDNI\t\tPUNTAJE\n");
Color(0,15);
for(int i=0;i<10;i++){

  if((r[i]->puntaje!=-1)&(r[i]->puntaje!=0)){
        if(i==0){
            Color(14,0);
            printf("\n%d\t\t%s\t\t%s\t\t\t%s\t%.2f",i+1,r[i]->nombre,r[i]->apellido,r[i]->dni,r[i]->puntaje);
            Color(0,15);
            printf("\n");
        }else{
            if(i==1){
                Color(8,0);
                printf("\n%d\t\t%s\t\t%s\t\t\t%s\t%.2f",i+1,r[i]->nombre,r[i]->apellido,r[i]->dni,r[i]->puntaje);
                Color(0,15);
                printf("\n");
            }else{
                if(i==2){
                    Color(6,0);
                    printf("\n%d\t\t%s\t\t%s\t\t\t%s\t%.2f",i+1,r[i]->nombre,r[i]->apellido,r[i]->dni,r[i]->puntaje);
                    Color(0,15);
                    printf("\n");
                }else{
                    Color(15,0);
                printf("\n%d\t\t%s\t\t%s\t\t\t%s\t%.2f",i+1,r[i]->nombre,r[i]->apellido,r[i]->dni,r[i]->puntaje);
                Color(0,15);
                printf("\n");
                }
            }
        }

    }
}
}

void destructorDeRanking(Ranking r){
    free(r);
}

void destructorDeRankings(Ranking r[]){
    for(int i=0; i<10;i++){
        destructorDeRanking(r[i]);
    }
}

char* getNombreRanking(Ranking r){
    return r->nombre;
}

char* getApellidoRanking(Ranking r){
    return r->apellido;
}

char* getDniRanking(Ranking r){
    return r->dni;
}

float getPuntajeRanking(Ranking r){
    return r->puntaje;
}

void setNombreRanking(Ranking r, char c[]){
    strcpy(r->nombre, c);
}

void setApellidoRanking(Ranking r, char c[]){
    strcpy(r->apellido, c);
}

void setDniRanking(Ranking r, char c[]){
    strcpy(r->dni, c);
}

void setPuntajeRanking(Ranking r, float f){
    r->puntaje= f;
}
