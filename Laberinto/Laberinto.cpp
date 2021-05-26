//  Laberinto.cpp
//
//  Creado por: Paulina Ugalde Carreño 19141209
//  Fecha: 04/10/2020
//  Programa recursivo que dado un laberinto implementado en una matriz de 30 x 30, 
//  resuelva el camino para la solución, proporcionando únicamente la posición de entrada
//  y la de salida (coordenada: renglón, columna).

#include<iostream>
#include<stdio.h>
#include<chrono>    //Libreria que nos mide el tiempo de ejecucion

#define DIM 30      //Definimos la dimension de la matriz

using namespace std;
char laberinto[30][30]; //Definimos la matriz de tipo caracter

//Método que se encarga de llenar el laberinto
void llenarLaberinto(){
	int i, j;
	//Ponemos las casillas blancas
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++)
			laberinto[i][j]=219;
	}
	
	//Ponemos las casillas vacías
	if(i=1){
		for(j=0; j<13; j++)
			laberinto[i][j]=' ';
			for(j=23; j<26; j++)
				laberinto[i][j]=' ';
	}
	if(i=2){
		laberinto[i][3]=' ';
		for(j=12; j<27; j++)
			laberinto[i][j]=' ';
	}
	if(i=3)
	   laberinto[i][3]=' '; laberinto[i][4]=' '; laberinto[i][12]=' '; laberinto[i][13]=' '; laberinto[i][23]=' '; laberinto[i][24]=' '; laberinto[i][26]=' ';
	if(i=4){
	    for(j=3; j<6; j++)
		   laberinto[i][j]=' ';
        laberinto[i][12]=' '; laberinto[i][13]=' '; laberinto[i][4]=' '; laberinto[i][5]=' '; 
	    for(j=26; j<29; j++)
		   laberinto[i][j]=' ';
	}
	if(i=5){
	   for(j=1; j<26; j++)
		   laberinto[i][j]=' ';
    }
	if(i=6){
        for(j=2; j<6; j++)
            laberinto[i][j]=' ';
	    for(j=1; j<9; j++)
            laberinto[i][j]=' ';
		for(j=18; j<21; j++)
		    laberinto[i][j]=' ';
	    for(j=23; j<26; j++)
		    laberinto[i][j]=' ';
    }
	if(i=7){
	   for(j=6; j<21; j++)
		   laberinto[i][j]=' ';
		for(j=23; j<27; j++)
		   laberinto[i][j]=' ';
    }
	if(i=8)
		laberinto[i][6]=' '; laberinto[i][20]=' ';
	if(i=9)
		laberinto[i][6]=' '; laberinto[i][20]=' ';
	if(i=10){
		laberinto[i][6]=' '; laberinto[i][7]=' ';
		for(j=9; j<27; j++)
		   laberinto[i][j]=' ';
	}
	if(i=11)
		laberinto[i][6]=' '; laberinto[i][15]=' '; laberinto[i][25]=' '; laberinto[i][26]=' ';  
	if(i=12){
	    for(j=1; j<8; j++)
		   laberinto[i][j]=' ';
	    for(j=9; j<13; j++)
		   laberinto[i][j]=' ';
	    for(j=15; j<20; j++)
		   laberinto[i][j]=' ';
	}
	if(i=13){
	   laberinto[i][15]=' ';
	    for(j=3; j<8; j++)
		   laberinto[i][j]=' ';
	    for(j=9; j<13; j++)
		    laberinto[i][j]=' ';
	    for(j=25; j<29; j++)
			laberinto[i][j]=' ';
	}
	if(i=14)
	   laberinto[i][15]=' ';laberinto[i][21]=' ';laberinto[i][22]=' '; laberinto[i][25]=' ';laberinto[i][26]=' ';
	if(i=15)
	   laberinto[i][15]=' ';laberinto[i][21]=' ';laberinto[i][22]=' ';laberinto[i][26]=' ';
	if(i=16){
	   for(j=3; j<8; j++)
		   laberinto[i][j]=' ';
		for(j=10; j<29; j++)
			laberinto[i][j]=' ';
    }
    if(i=17){
	   for(j=1; j<8; j++)
		   laberinto[i][j]=' ';
		laberinto[i][15]=' ';
    }
	if(i=18)
	   laberinto[i][15]=' ';
	if(i=19){
	   for(j=3; j<16; j++)
		   laberinto[i][j]=' ';   
    }
	if(i=20){
	    for(j=13; j<16; j++)
		   laberinto[i][j]=' ';
		for(j=18; j<22; j++)
		   laberinto[i][j]=' ';   
	}
	if(i=21){
	   for(j=13; j<16; j++)
		   laberinto[i][j]=' ';
		laberinto[i][18]=' ';   
	}
	if(i=22){
	   for(j=15; j<24; j++)
		   laberinto[i][j]=' ';   
		laberinto[i][28]=' ';laberinto[i][29]=' ';
	}
	if(i=23)
	   laberinto[i][15]=' '; laberinto[i][19]=' ';laberinto[i][23]=' ';laberinto[i][28]=' ';
	if(i=24){
	    for(j=11; j<7; j++)
		   laberinto[i][j]=' ';
	    laberinto[i][15]=' ';laberinto[i][19]=' '; 
		for(j=23; j<29; j++)
			laberinto[i][j]=' ';
	}
	if(i=25){
	   for(j=1; j<7; j++)
		   laberinto[i][j]=' ';
		laberinto[i][15]=' ';laberinto[i][19]=' '; laberinto[i][20]=' '; laberinto[i][23]=' '; 
	}
	if(i=26){
	   laberinto[i][1]=' ';laberinto[i][2]=' '; laberinto[i][15]=' ';laberinto[i][19]=' '; 
	   laberinto[i][20]=' '; laberinto[i][23]=' '; laberinto[i][24]=' '; 
	}
	if(i=27){
	   laberinto[i][1]=' '; laberinto[i][2]=' ';
	   for(j=10; j<16; j++)
		   laberinto[i][j]=' ';
		laberinto[i][23]=' ';
	}
	if(i=28)
	   laberinto[i][23]=' ';
}

//Checamos si nuestras posiciones están dentro del arreglo y si la casilla esta vacia
bool validarCasilla(char lab[30][30], int R, int C, int x, int y){
    if (x >= 0 && x < R && y >= 0 && y < C && *(*(lab + x) + y) == ' ') {
        return true;
    }
    return false;
}

//Buscamos la solucion (salida) del laberinto
bool encontrarSalida(char lab[30][30], int R, int C, int x, int y, int salidaX, int salidaY){
    //Caso base, en el caso de que la posicion x/y contenga el mismo valor que la poscision salida
    if (x == salidaX && y == salidaY) { 
         *(*(lab + x) + y) = 158;   //Ponemos una tachesita en codico ascii
        return true;
    }
    //Caso recursivo:
    if (validarCasilla(lab, R, C, x, y) == true) { 
        *(*(lab + x) + y) = 158;
    if (encontrarSalida(lab, R, C, x + 1, y, salidaX, salidaY) == true) //Nos movemos hacia la derecha
        return true;
    if (encontrarSalida(lab, R, C, x - 1, y, salidaX, salidaY) == true) //Nos movemos hacia la izquierda
        return true;
    if (encontrarSalida(lab, R, C, x, y - 1, salidaX, salidaY) == true) //Nos movemos hacia abajo
        return true;
    if (encontrarSalida(lab, R, C, x, y + 1, salidaX, salidaY) == true) //Nos movemos hacia arriba
        return true;
    *(*(lab + x) + y) = ' '; //Si nos tenemos que regresar dejamos la casilla vacía
        return false;
    }
        return false;
}
	
int main(int argc, char const *argv[]){
    int i, j;
    int R=30;   //Dimension del Renglon
    int C=30;   //Dimension de la Columna

    //Llenamos la matriz
	llenarLaberinto();
    //Buscamos la salida
    auto start1 = std::chrono::system_clock::now(); //Asignamos el tiempo actual
    encontrarSalida(laberinto, R, C, 1, 0, 22, 29);
    auto end1 = std::chrono::system_clock::now();   //Asignamos el tiempo actual
    std::chrono::duration<float, std::milli> duration = end1-start1; //Calculamos la duracion

    //Mostramos el laberinto
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			cout<<laberinto[i][j];
		}
		cout<<"\n";
	}

    std::cout<<"Segundos empleados buscando la solucion: "<<duration.count()<<" milisegundos"<<std::endl;
    return 0;
}