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
#define COLUMNANUMEROS 10
#define FILACARTON 3
#define BOLILLAS 90





int main()
{

    Jugador usuario;
    Jugador pc;
    Partida juego;
    Ranking a[10];

    srand(time(0));
    int opcionMenu=0;
    do{
        Color(3,15);
        printf("BIENVENIDO AL BINGO\n1-Jugar.\n2-Ranking.\n3-Salir.\n");
        Color(0,15);
        scanf("%d", &opcionMenu);

        switch(opcionMenu){
            case 1:     usuario= pedirDatosUsuario();

                        pc=cargarPc(getCantidadDeCartones(usuario));

                        ordenarCartonesUsuarios(usuario,pc);

                        mostrarJugador(usuario);

                        juego= generarPartida();

                        menuPartida(juego,usuario,pc);

                        mostrarPuntos(juego,usuario,pc);

                        guardarEnArchivo(usuario,pc);

                        crearRackings(a);

                        leerArchivo(a);

                        guardarEnArchivoRanking(a);

                        mostrarRanking(a);

                        destructorDepartida(juego);

                        destructorDeRankings(a); break;

            case 2:     crearRackings(a);

                        leerArchivo(a);

                        mostrarRanking(a);

                        destructorDeRankings(a); break;

            case 3:     Color(10,0);

                        printf("\n\nGRACIAS POR JUGAR.\n\n");

                        Color(0,15); break;

            default:    Color(4,15);
                        printf("\nEl numero ingresado no corresponde a una opcion valida.\nVolve a intentar.\n");
                        Color(0,15);
        }
    }while(opcionMenu!=3);





    destructorDepartida(juego);

    destructorDeRankings(a);

    return 0;
}
