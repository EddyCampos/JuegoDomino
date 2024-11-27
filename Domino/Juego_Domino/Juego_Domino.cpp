// Eddy Campos Jimenez
// Creado: 30 Noviembre 2022
// Actualizado: 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "funciones_Domino.h"

using namespace std;

int main()
{
    //DECLARACION E INICIALIZACION DE VARIABLES Y VECTORES
    int opcion = 0;
    piezas piezasDomino[28] = {}; //VECTOR CON LA ESTRUCTURA QUE TIENE TODAS LAS FICHAS Y SUS ELEMENTOS
    vector <string> jugadores(4); //VECTOR DONDE SE GUARDAN LOS NOMBRES DE LOS JUGADORES
    vector <int> piezasJugadas; //VECTOR DONDE SE ALMACENAN LAS FICHAS QUE YA FUERON JUGADAS (DE LA MESA)

    //VECTORES DONDE SE GUARDAN LOS INDICES CON LAS FICHAS DE CADA JUGADOR
    vector <int> jugador1(7);
    vector <int> jugador2(7);
    vector <int> jugador3(7);
    vector <int> jugador4(7);

    //CICLO QUE EJECUTA TODO EL PROGRAMA MIENTRAS LA OPCION SEA MENOR A 4
    do {
        opcion = menu(); //LLAMADO FUNCION CON EL MENU, RETORNA LA OPCION QUE SE SELECCIONO

        switch (opcion){ //SWICTH SEGUN LA OPCION

        case 1: {
            instrucciones(); //LLAMADO FUNCION MUESTRA LAS INSTRUCCIONES Y REGLAS
            break;
        }
        case 2: {
            solicitaNombres(jugadores); //LLAMADO A LA FUNCION QUE SOLICITA LOS NOMBRES Y LOS GUARDA EN EL VECTOR

            generaPiezas(piezasDomino); //LLAMADO FUNCION QUE GENERA LAS 28 PIEZAS Y LAS ALMACENA EN EL VECTOR

            repartePiezas(jugador1, piezasDomino); //LLAMADO FUNCION REPARTE FICHAS PARA EL JUGADOR 1
            repartePiezas(jugador2, piezasDomino); //LLAMADO FUNCION REPARTE FICHAS PARA EL JUGADOR 2
            repartePiezas(jugador3, piezasDomino); //LLAMADO FUNCION REPARTE FICHAS PARA EL JUGADOR 3
            repartePiezas(jugador4, piezasDomino); //LLAMADO FUNCION REPARTE FICHAS PARA EL JUGADOR 4

            muestraPiezasIniciales(piezasDomino, jugadores, jugador1, jugador2, jugador3, jugador4); //LLAMADO FUNCION MUESTRA LAS FICHAS DE CADA UNO ANTES DE EMPEZAR

            cout << endl;
            ejecutarJuego(piezasDomino, jugador1, jugador2, jugador3, jugador4, jugadores, piezasJugadas); //LLAMADO FUNCION EJECUTA TODAS LAS FUNCIONES DEL JUEGO

            break;
        }
        case 3: { //SE SALE Y FINALIZA LA EJECUCION TOTAL DEL PROGRAMA
            cout << endl << "\t GRACIAS!" << endl;
            opcion = 4;
            break;
        }
        default: //SI SE INGRESA UNA TECLA INVALIDA EN EL MENU MUESTRA MENSAJE
            cout << endl << "\t OPCION INVALIDA" << endl << "\t ";
            system("pause");
            break;
        }
    } while (opcion < 4);
}

