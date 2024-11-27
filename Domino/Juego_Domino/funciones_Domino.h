#pragma once
#include "definicionTipos_Domino.h"
using namespace std;

//************************************************************************************
//1. FUNCION DEL MENU, MUESTRA EL MENU CON LAS OPCIONES Y RETORNA LA OPCION SELECCIONADA AL MAIN
int menu() {
	//DECLARACION E INICIALIZACION DE VARIABLES 
	int opcion = 0;

	cout << endl << "\t -------------------- DOMINO --------------------" << endl;
	cout << "\t ---------------------------------------------------" << endl;
	cout << "\t SELECCIONE UNA DE LAS SIGUIENTES OPCIONES" << endl;
	cout << "\t 1. INSTRUCCIONES" << endl;
	cout << "\t 2. JUGAR" << endl;
	cout << "\t 3. SALIR" << endl;
	cout << "\t ---------------------------------------------------" << endl;
	cout << "\t Esperando opcion ... ";
	cin >> opcion;
	return opcion;
}

//************************************************************************************
//2. FUNCION QUE MUESTRA INSTRUCCIONES Y REGLAS DEL JUEGO
void instrucciones() {
	system("cls");

	cout << endl << " \t ----- INSTRUCCIONES -----" << endl;
	cout << endl << "\t El DOMINO consiste en un juego de fichas, en donde cada jugador debera colocar en la mesa" << endl;
	cout << "\t una ficha que contenga un numero en comun con las que ya fueron colocadas, el primero en jugar todas" << endl;
	cout << "\t las 7 fichas gana el juego" << endl;

	cout << endl << "\t COMO JUGAR..." << endl;
	cout << endl << "\t * El sistema le solicitara los nombres de los jugadores" << endl;
	cout << endl << "\t * A cada jugador le serán repartidas 7 fichas al azar" << endl;
	cout << endl << "\t * Cada jugador tendra la oportunidad de jugar por rondas" << endl;
	cout << endl << "\t * Para colocar las fichas debe ingresar el numero asignado para cada una de ellas" << endl;
	cout << endl << "\t * Gana el jugador que primero coloque todas sus fichas en la mesa" << endl << endl << "\t ";

	system("pause");  //ESPERAR TECLA Y LIMPIAR PANTALLA

	system("cls");
}

//************************************************************************************
//3. FUNCION QUE SOLICITA LOS NOMBRES DE LOS 4 JUGADORES Y LOS ALMACENA RESPECTIVAMENTE EN EL VECTOR
void solicitaNombres(vector <string>& nombres) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int contador = 1;
	system("cls");

	cin.ignore();

	for (int i = 0; i < 4; i++) {
		cout << endl << "\t INGRESE EL NOMBRE DEL JUGADOR " << contador << " : "; //SOLICITA
		getline(cin, nombres[i]); //GUARDA
		contador++;
	}
	cout << endl<< "\t "; 
	system("pause"); //ESPERAR TECLA Y LIMPIAR PANTALLA
	system("cls");
}

//************************************************************************************
//4. FUNCION GENERA TODAS LAS PIEZAS
void generaPiezas(struct piezas arreglo[]) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int contador = 0;

	//CICLO GENERA LAS COMBINACIONES DE LAS FICHAS
	for (int i = 0; i <= 6; i++) { //ESTE CICLO GENERA NUMEROS DEL 0 AL 6
		for (int j = 0; j <= i; j++) { //ESTE CICLO RECORRE DEL 0 AL I (0 AL 6) (1 AL 6 ) (2 AL 6) ....
			arreglo[contador].valor1 = i; //ALMACENA I EN EL VALOR 1
			arreglo[contador].valor2 = j; //Y J EN EL 2
			contador++;
		}
	}

	//CICLO AGREGA LA MARCA EN 0 A TODAS LAS FICHAS (CUANDO LA FICHA YA SALIO SE CAMBIA A 1)
	for (int i = 0; i < 28; i++) {
		arreglo[i].marca = 0;
	}
}

//************************************************************************************
//5. FUNCION RECIBE EL NUMERO AL AZAR Y VERIFICA QUE EL INDICE EN ESA POSICION TENGA UNA MARCA 0 O 1
int verificaNum(vector <int>& mazo, struct piezas arreglo[], int num) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int respuesta = 0;

	//SI EL ARREGLO EN EL NUM GENERADO ALEAOTORIO TIENE UN 1 EN LA MARCA (YA SALIO) Y RETORNA EL 1, SINO RETORNA EL 0 (ESTA DISPONIBLE)
	if (arreglo[num].marca == 1) {
		respuesta = 1;
	}

	return respuesta;
}
//************************************************************************************
//6. FUNCION ESCOGE LAS CARTAS DE CADA PARTICIPANTE Y LAS MARCA EN LA BARAJA

void repartePiezas(vector <int> &mazo, struct piezas arreglo[]) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int temp = 0;

	srand(time(NULL)); //SEMILLA PARA GENERAR ALEATORIOS
	
	//CICLO GENERA LA CANTIDAD DE NUMEROS SEGUN EL TAMAÑO DEL VECTOR
	for (int i = 0; i < mazo.size(); i++) {
		while (verificaNum(mazo, arreglo, temp = rand() % (29 - 1))); //GENERA NUMEROS PARA EL INDICE, MIENTRAS LA FUNCION QUE VERIFICA LA MARCA DEL NUMERO 
		mazo[i] = temp;	//GUARDA EL INDICE EN EL VECTOR	   			  // SI RETORNE UN 0 (NO HA SALIDO), SI RETORNA UN 1 GENERA OTRO Y VERIFICA OTRA VEZ
		arreglo[temp].marca = 1; //MARCA EN LA POSICION GENERADO UN 1 PARA QUE NO VUELVA A SALIR
	}
}

//************************************************************************************
//7. FUNCION QUE MUESTRA LAS PIEZAS DE CADA JUGADOR, EN EL MAZO

void muestraPiezas(struct piezas arreglo[], vector <int>& mazo) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int cont = 0;

	//CICLO QUE EJECUTA MIENTRAS CONT SEA MENOR AL TAMAÑO DEL MAZO (ES DECIR SOLO LO EJECUTA UNA VEZ CON TODAAS LA FICHAS
	do {
		for (int i = 0; i < mazo.size(); i++) { //GENERA LA LINEA DE ARRIBA DE LA FICHA
			if (i == 0) {
				printf("\t %c", 201); //SIMBOLO ESQUINA ARRIBA CON TABULACION
			}
			else {
				printf("%c", 201); //SIMBOLO ESQUINA ARRIBA SIN TABULACION
			}
			for (int i = 0; i < 7; i++) { //LINEAS DE ARRIBA HORIZONTALES
				printf("%c", 205);	
			}
			printf("%c", 187); //SIMBOLO ESQUINA ABAJO 
		}
		cout << endl;

		for (int i = 0; i < mazo.size(); i++){ //MUESTRA EL VALOR 1 Y 2 DE CADA FICHA
			if (i == 0) {
				printf("\t %c %d %c %d %c", 186, arreglo[mazo[cont]].valor1, 179, arreglo[mazo[cont]].valor2, 186); //MUESTRA VALOR 1 Y 2 ENCERRADOS EN DOS LINEAS VERTICALES CON TABULACION 
			}
			else {
				printf("%c %d %c %d %c", 186, arreglo[mazo[cont]].valor1, 179, arreglo[mazo[cont]].valor2, 186); //MUESTRA VALOR 1 Y 2 ENCERRADOS EN DOS LINEAS VERTICALES SIN TABULAR 
			}
			cont++;
		}
		cout << endl;

		for (int i = 0; i < mazo.size(); i++) { //GENERA LA LINEA DE ABAJO DE LA FICHA
			if (i == 0) {
				printf("\t %c", 200); //SIMBOLO ESQUINA ARRIBA CON TABULACION
			}
			else {
				printf("%c", 200); //SIMBOLO ESQUINA ARRIBA SIN TABULACION
			}
			for (int i = 0; i < 7; i++) { //LINEAS DE ARRIBA HORIZONTALES
				printf("%c", 205);
			}
			printf("%c", 188);  //SIMBOLO ESQUINA ABAJO CON TABULACION
		}
		cout << endl;
	
	} while (cont > mazo.size());
}

//************************************************************************************
//8. FUNCION QUE BUSCA EL JUGADOR QUE TENGA LA PIEZA CON EL DOBLE SEIS
int jugadorInicia(struct piezas arreglo[], vector <int>& mazo1, vector <int>& mazo2, vector <int>& mazo3, vector <int>& mazo4, vector <int>& piezasJugadas) {

	//DECLARACION E INICIALIZACION DE VARIABLES Y VECTORES
	int respuesta = 0;
	vector <int> temporal(7);

	//CICLO RECORRE TODO EL VECTOR CON EL MAZO
	for (int i = 0; i < mazo1.size(); i++) {
		if (arreglo[mazo1[i]].valor1 == 6 && arreglo[mazo1[i]].valor2 == 6) { //SI EL VALOR 1 Y EL 2 EN EL MAZO 1 SON 6, EL VECTOR ES EL O
			//piezasJugadas = arreglo->valor1; //SE INSERTA LA FICHA AL INCIO

			respuesta = 0;
		}
		else {
			if (arreglo[mazo2[i]].valor1 == 6 && arreglo[mazo2[i]].valor2 == 6) { //SI EL VALOR 1 Y EL 2 EN EL MAZO 2 SON 6, EL VECTOR ES EL 1
				respuesta = 1;
				temporal = mazo1; //REALIZA UN INTERCAMBIO EN EL ORDEN DE LOS VECTORES PARA ASI SER EL PRIMERO EN JUGAR
				mazo1 = mazo2;
				mazo2 = temporal;
			}
			else {
				if (arreglo[mazo3[i]].valor1 == 6 && arreglo[mazo3[i]].valor2 == 6) { //SI EL VALOR 1 Y EL 2 EN EL MAZO 3 SON 6, EL VECTOR ES EL 2
					respuesta = 2;
					temporal = mazo1; //REALIZA UN INTERCAMBIO EN EL ORDEN DE LOS VECTORES PARA ASI SER EL PRIMERO EN JUGAR
					mazo1 = mazo3;
					mazo3 = temporal;
				}
				else {
					if (arreglo[mazo4[i]].valor1 == 6 && arreglo[mazo4[i]].valor2 == 6) { //SI EL VALOR 1 Y EL 2 EN EL MAZO 3 SON 6, EL VECTOR ES EL 2
						respuesta = 3;
						temporal = mazo1; //REALIZA UN INTERCAMBIO EN EL ORDEN DE LOS VECTORES PARA ASI SER EL PRIMERO EN JUGAR
						mazo1 = mazo4;
						mazo4 = temporal;
					}
				}
			}
		}
	}

	return respuesta;
}

//************************************************************************************
//9. FUNCION QUE EVALUA SI LA PIEZA PUEDE O NO SER COLOCADA

void evaluaPieza(struct piezas arreglo[], vector <int>& mazo, vector <int>& piezasJugadas, int posicion, int &combinacionFichas) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	bool fichaValida = false,
		valido = false;

	//SI EL VECTOR ESTA VACIO, PERMITE COLOCAR CUALQUIER FICHA Y NO EVALUA
	if (piezasJugadas.size() == 0) {
		valido = true;
		
	}
	else{
		combinacionFichas = 0;
		for (int i = 0; i < piezasJugadas.size(); i++) { //CICLO RECORRE TODO EL VECTOR SIN IMPORTAR EL TAMAÑO
			if (arreglo[piezasJugadas[i]].valor1 == arreglo[mazo[posicion]].valor1) { //SI EL VALOR 1 EN LAS PIEZAS YA JUGADAS, ES IGUAL AL VALOR 1 DE LA POSIBLE FICHA
				fichaValida = true; //ES UN MOV VALIDO
				combinacionFichas = 1; //COMBINACION DE FICHAS ES VALOR 1 == VALOR 1
			}
			else {
				if (arreglo[piezasJugadas[i]].valor1 == arreglo[mazo[posicion]].valor2) { //SI EL VALOR 1 EN LAS PIEZAS YA JUGADAS, ES IGUAL AL VALOR 2 DE LA POSIBLE FICHA
					fichaValida = true; //ES UN MOV VALIDO
					combinacionFichas = 2; //COMBINACION DE FICHAS ES VALOR 1 == VALOR 2
				}
				else {
					if (arreglo[piezasJugadas[i]].valor2 == arreglo[mazo[posicion]].valor1) { //SI EL VALOR 2 EN LAS PIEZAS YA JUGADAS, ES IGUAL AL VALOR 1 DE LA POSIBLE FICHA
						fichaValida = true; //ES UN MOV VALIDO
						combinacionFichas = 3; //COMBINACION DE FICHAS ES VALOR 2 == VALOR 1
					}
					else {
						if (arreglo[piezasJugadas[i]].valor2 == arreglo[mazo[posicion]].valor2) { //SI EL VALOR 2 EN LAS PIEZAS YA JUGADAS, ES IGUAL AL VALOR 2 DE LA POSIBLE FICHA
							fichaValida = true; //ES UN MOV VALIDO
							combinacionFichas = 4; //COMBINACION DE FICHAS ES VALOR 2 == VALOR 2

						}
					}
				}
			}
		}
	}

}

//************************************************************************************
//10. FUNCION QUE MUESTRA LOS MENSAJES DEL JUGADOR QUE ESTA JUGANDO
int turno(vector <string>& nombres, int i, vector <int>& mazo, struct piezas arreglo[], vector <int>& piezasJugadas, char &inicioFin, int &combinacionFichas) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int posicion = 1,
		continuar = 0;
	char salir = 'J';

	//MUESTRA EL NUMERO PARA SELECCIONAR LA PIEZA
	for (int i = 0; i < mazo.size(); i++) {
		cout << "\t      "  << posicion;
		posicion++;
	}

	//CICLO DO QUE MUESTRA EL NOMBRE DEL PARTICIPANTE QUE ESTA JUGANDO, MIENTRAS EL USUARIO DEIGITE 'J' (DESEA JUGAR)
	do{
		cout << endl << "\t TURNO DE " << nombres[i] << endl << endl;
		
		cout << endl << "\t DIGITE EL NUMERO DE LA CARTA QUE DESEA COLOCAR "; 
		cout << "\t ESPERANDO RESPUESTA... ";
		cin >> continuar; //GUARDA EL NUMERO DE LA PIEZA
		evaluaPieza(arreglo, mazo, piezasJugadas, continuar - 1, combinacionFichas); //Y LO ENVIA A LA FUNCION QUE EVALUA PIEZAS E INDICA SI ES VALIDA O NO

		cout << endl << "\t DESEA COLOCAR LA CARTA AL INICIO O AL FINAL (I/F) "; //PREGUNTA SI DESEA COLOCAR LA FICHA AL INICIO O AL FINAL
		cout << "\t ESPERANDO RESPUESTA... ";
		cin >> inicioFin; //LO GUARDA POR PARAMETRO EN ESTA VARIABLE
		inicioFin = toupper(inicioFin); //CONVIERTE A MUYUSCULAS
	
		salir = 'J';
	} while (salir == 'P');

	return continuar - 1; //ENVIA LA POSICION (EN -1 ) PARA QUE CUMPLA CON EN RANGO DEL VECTOR
}

//************************************************************************************
//11. FUNCION QUE COLOCA LA CARTA AL FINAL O AL INICIO Y LA ELIMINA DEL MAZO
void juegaCarta(vector <int>& mazo, int posicion, vector <int>& piezasJugadas, char& inicioFin, int combinacionFichas, struct piezas arreglo[], int &contador) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int temp = 0;

	//CICLO QUE EVALUA SI SE DA LA COMBINACION 1 (VALOR 1 == VALOR 1) O LA COMBINACION 4 (VALOR 2 == VALOR 2)
	if (combinacionFichas == 1 || combinacionFichas == 4) { // SI ESO SE DA HAY QUE INVERTIR LOS VALORES DE LAS FICHAS
		temp = arreglo[mazo[posicion]].valor1; //EL VALOR 1 LO GUARDA EN UNA VARIABLE TEMPORAL
		arreglo[mazo[posicion]].valor1 = arreglo[mazo[posicion]].valor2; //REALIZA EL INTERCAMBIO DE VALOR 1 POR VALOR 2
		arreglo[mazo[posicion]].valor2 = temp; //Y ASIGNA EL ANTIGUO VALOR 1 AL 2
	}

	if (inicioFin == 'I') {//SI LA RESPUESTA DE LA POSICION EN DONDE COLOCAR LA PIEZA ES 'I'
		piezasJugadas.insert(piezasJugadas.begin(), mazo[posicion]); //SE INSERTA LA FICHA AL INCIO
	}
	else { //SI LA RESPUSTA ES 'F'
		piezasJugadas.insert(piezasJugadas.end(), mazo[posicion]); //INSERTA LA FICHA AL FINAL
	}
	
	mazo.erase(mazo.begin() + posicion); //Y BORRA LA FICHA DEL VECTOR DEL JUGADOR
	contador++;

}

//************************************************************************************
//12. FUNCION MUESTRA LAS CARTAS EN EL TABLERO CUANDO YA FUERON JUGADAS
void piezasEnMesa(struct piezas arreglo[], vector <int>& mazo, vector <int>& piezasJugadas) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	vector <int> piezasYaJugadas;
	int cont = 0;

	//CICLO DO QUE EJECUTA MIENTRAS EL CONT SEA MENOR AL TAMAÑO DEL VECTOR(ES DECIR SOLO UNA VEZ)
	do {

		muestraPiezas(arreglo, piezasJugadas); //LLAMADO FUCNION QUE MUESTRA LAS FICHAS QUE HAN SIDO JUGADAS

	} while (cont < piezasYaJugadas.size());
	cout << endl << endl << endl << endl << endl;
}

//************************************************************************************
//13. FUNCION QUE DETERMINA EL JUGADOR QUE GANÓ EL JUEGO
void ganadorJuego(int contJugador1, int contJugador2, int contJugador3, int contJugador4, bool& ganador, vector <string>& nombres) {
	
	if ( contJugador1 == 7) { //CICLO EVALUA SI EL CONTADOR DEL JUGADOR 1 ES 7 (COLOCO TODAS LAS FICHAS), GANO
		ganador = true;
		cout << "\t " << nombres[0] << " ha ganado el juego" << "\t ";
		system("pause");
		system("cls");
	}

	if (contJugador2 == 7) { //CICLO EVALUA SI EL CONTADOR DEL JUGADOR 2 ES 7 (COLOCO TODAS LAS FICHAS), GANO
		ganador = true;
		cout << "\t " << nombres[1] << " ha ganado el juego" << "\t ";
		system("pause");
		system("cls");
	}

	if (contJugador3 == 7) { //CICLO EVALUA SI EL CONTADOR DEL JUGADOR 3 ES 7 (COLOCO TODAS LAS FICHAS), GANO
		ganador = true;
		cout << "\t " << nombres[2] << " ha ganado el juego" << "\t ";
		system("pause");
		system("cls");
	}

	if (contJugador4 == 7) { //CICLO EVALUA SI EL CONTADOR DEL JUGADOR 4 ES 7 (COLOCO TODAS LAS FICHAS), GANO
		ganador = true;
		cout << "\t " << nombres[3] << " ha ganado el juego" << "\t ";
		system("pause");
		system("cls");

	}
}

//************************************************************************************
//14. FUNCION QUE EJECUTA TODAS LAS FUNCIONES DEL JUEGO
void ejecutarJuego(struct piezas arreglo[], vector <int>& mazo1, vector <int>& mazo2, vector <int>& mazo3, vector <int>& mazo4, vector <string>& nombres, vector <int>& piezasJugadas) {

	//DECLARACION E INICIALIZACION DE VARIABLES 
	int primero = 0,
		cont = 0,
		cartaSeleccionada = 0,
		combinacionFichas = 0,
		contJugador1 = 0,
		contJugador2 = 0,
		contJugador3 = 0,
		contJugador4 = 0,
		continuar = 0;

	bool ganador = false,
		saltarRonda = false,
		avanza = false;
	char inicioFin = 'I';
	
	primero = jugadorInicia(arreglo, mazo1, mazo2, mazo3, mazo4, piezasJugadas); //LLAMADO FUNCION QUE BUSCA EL MAZO CON EL DOBLE 6 PARA INICIAR JUGANDO

	cout << "\t " << nombres[primero] << " debe iniciar colocando porque tiene la pieza mayor" << endl;

	nombres.insert(nombres.begin(), nombres[primero]); //LO INSERTA DE PRIMERO

	//CICLO DO QUE EJECUTA (JUEGA FICHAS) HASTA QUE EXISTA UN GANADOR
	do{

		//CICLO FOR QUE PERMITE RECORRER EL VECTOR CON LOS NOMBRES Y QUE LOS PARTICIPANTES PUEDAN JUGAR
		for (int i = 0; i < nombres.size(); i++){
			cont = 0;		

			piezasEnMesa(arreglo, mazo1, piezasJugadas); //LLAMADO FUNCION MUESTRA LA MESA CON CADA UNO DE LAS FICHAS JUGADAS
			muestraPiezas(arreglo, mazo1); //LLAMADO FUNCION MUESTRA EL MAZO DEL JUGADOR UNO
			cartaSeleccionada = turno(nombres, cont, mazo1, arreglo, piezasJugadas, inicioFin, combinacionFichas); //MUESTRA EL MENSAJE Y RETORNA EL NUMERO DE LA PIEZA A COLOCAR
			juegaCarta(mazo1, cartaSeleccionada, piezasJugadas, inicioFin, combinacionFichas, arreglo, contJugador1); //LLAMADO FUNCION QUE JUEGA LA CARTA LA COLOCA EN LA MESA Y LA BORRA DEL MAZO		
			ganadorJuego(contJugador1, contJugador2, contJugador3, contJugador4, ganador, nombres); //LLAMADO FUNCION MUESTRA SI HUBO UN GANADO


			system("cls");
			cont++;
			cartaSeleccionada = 0;

			//---------------------------------------------------------
			//JUGADOR 2

			piezasEnMesa(arreglo, mazo2, piezasJugadas); //MUESTRA LA MESA CON CADA UNO DE LAS FICHAS JUGADAS
			muestraPiezas(arreglo, mazo2); //MUESTRA EL MAZO DEL JUGADRO
			cartaSeleccionada = turno(nombres, cont, mazo2, arreglo, piezasJugadas, inicioFin, combinacionFichas); //MUESTRA EL MENSAJE Y EL NUMERO DE LA PIEZA A COLOCAR
			juegaCarta(mazo2, cartaSeleccionada, piezasJugadas, inicioFin, combinacionFichas, arreglo, contJugador2); //LLAMADO FUNCION QUE JUEGA LA CARTA LA COLOCA EN LA MESA Y LA BORRA DEL MAZO
			ganadorJuego(contJugador1, contJugador2, contJugador3, contJugador4, ganador, nombres); //LLAMADO FUNCION MUESTRA SI HUBO UN GANADOR

			system("cls");
			cont++;
			cartaSeleccionada = 0;	

			//--------------------------------------------------------
			//JUGADOR 3
			
			piezasEnMesa(arreglo, mazo3, piezasJugadas); //MUESTRA LA MESA CON CADA UNO DE LAS FICHAS JUGADAS
			muestraPiezas(arreglo, mazo3); //MUESTRA EL MAZO DEL JUGADRO
			cartaSeleccionada = turno(nombres, cont, mazo3, arreglo, piezasJugadas, inicioFin, combinacionFichas); //MUESTRA EL MENSAJE Y EL NUMERO DE LA PIEZA A COLOCAR				
			juegaCarta(mazo3, cartaSeleccionada, piezasJugadas, inicioFin, combinacionFichas, arreglo, contJugador3); //LLAMADO FUNCION QUE JUEGA LA CARTA LA COLOCA EN LA MESA Y LA BORRA DEL MAZO
			ganadorJuego(contJugador1, contJugador2, contJugador3, contJugador4, ganador, nombres); //LLAMADO FUNCION MUESTRA SI HUBO UN GANADOR
			
			system("cls");
			cont++;
			cartaSeleccionada = 0;


			//---------------------------------------------------------
			//JUGADOR 4

			
			piezasEnMesa(arreglo, mazo4, piezasJugadas); //muestra la mesa
			muestraPiezas(arreglo, mazo4); //muestra el mazo del jugadro
			cartaSeleccionada = turno(nombres, cont, mazo4, arreglo, piezasJugadas, inicioFin, combinacionFichas); //muestra el mensaje y el numero de la pieza a colocar
			juegaCarta(mazo4, cartaSeleccionada, piezasJugadas, inicioFin, combinacionFichas, arreglo, contJugador4); //LLAMADO FUNCION QUE JUEGA LA CARTA LA COLOCA EN LA MESA Y LA BORRA DEL MAZO
			ganadorJuego(contJugador1, contJugador2, contJugador3, contJugador4, ganador, nombres); //LLAMADO FUNCION MUESTRA SI HUBO UN GANADOR


			system("cls");

		}

	} while (ganador = false);
}

//************************************************************************************
//15. FUNCION MUESTRA PIEZAS QUE SALIERON AL ALZAR EN EL PRINCIPIO (EL MAZO DE CADA JUGADOR CON EL NOMBRE DE CADA UNO)
void muestraPiezasIniciales(struct piezas arreglo[], vector <string>& nombres, vector <int>& mazo1, vector <int>& mazo2, vector <int>& mazo3, vector <int>& mazo4) {
	cout << endl << "\t PIEZAS DE " << nombres[0] << endl;
	muestraPiezas(arreglo, mazo1); //LAMADO FUNCION MUESTRA EL MAZO 1

	cout << endl << "\t PIEZAS DE " << nombres[1] << endl;
	muestraPiezas(arreglo, mazo2); //LLAMADO FUNCION MUESTRA EL MAZO 2

	cout << endl << "\t PIEZAS DE " << nombres[2] << endl;
	muestraPiezas(arreglo, mazo3); //LLAMADO FUNCION MUESTRA EL MAZO 3

	cout << endl << "\t PIEZAS DE " << nombres[3] << endl;
	muestraPiezas(arreglo, mazo4); //LLAMADO FUNCION MUESTRA EL MAZO 4

	cout << endl << "\t INICIAR EL JUEGO... " << endl << "\t ";
	system("pause");
	system("cls");
}
