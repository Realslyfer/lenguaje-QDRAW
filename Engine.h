/*
	*****************************************************************************************************
	Creado por Alejandro Lucero, ultima modificacion del repositorio: 3-12-18, www.github.com/Realslyfer 
    *****************************************************************************************************
	====================================================================================================
	NO TOCAR NADA DE ESTE ARCHIVO, SE APLICAN LAS DIRECTIVAS BASICAS DE QDRAW PARA QUE C++ LO INTERPRETE
	BIBLIOTECAS REQUERIDAS POR C++:
	====================================================================================================
*/
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<conio.h>
/*
	=========================================================
		DIRECTIVAS DEL PRE PROCESADOR PARA LOS COLORES
	=========================================================
*/
#define NEGRO	 			0x000
#define AZUL 				0x001
#define VERDE 				0x002
#define CELESTE			 	0x003
#define ROJO 				0x004
#define VIOLETA 			0x005
#define AMARILLO 			0x006
#define GRIS				0x007
#define GRIS_OSCURO			0x008
#define AZUL_BRILLANTE		0x009
#define VERDE_BRILLANTE 	0x00A
#define CELESTE_BRILLANTE	0x00B
#define ROJO_BRILLANTE 		0x00C
#define VIOLETA_BRILLANTE	0x00D
#define AMARILLO_BRILLANTE  0x00E
#define BLANCO				0x00F

using namespace std;

/*	======================================
		VARIABLES GLOBALES
	======================================
Se especifica que se debe sumar y restar desde 0 para X e Y, y la variable contador para el Repetir en 0 
*/ 
int valorX	 = 0;
int valorY	 = 0;
int contador = 0;

/*Se declara a falso (valor 0) todos los colores de las celdas al iniciar el mapa exepto el Blanco
*/
bool estaPintadoDeNegro     = 0;
bool estaPintadoDeRojo	    = 0;
bool estaPintadoDeVerde	    = 0;
bool Limpiar				= 1; //porque el mapa ya es blanco

/*	================================================
		DEFINICION DE FUNCIONES PARA C++
	================================================*/

//Funcion palabraColor() para letras individuales
void p_color(int color){
	static HANDLE hConsole;
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,color | (0*0x10+0x100));
}

//Funcion gotoxy(x,y) se pide a windows el control del puntero de escritura y el formato (cabezal)
void gotoxy(int x, int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}
//Funcion ocultarCursor() oculta el cursor en la consola
void ocultarCursor(){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci; //objeto console cursor info con el mismo nombre.
	cci.dwSize=2;
	cci.bVisible=FALSE;
	SetConsoleCursorInfo(hCon,&cci);
}
//Se crea el Comienzo para aplicar el cursor de escritura (cabezal) en el mapa
int Comienzo(int num1,int num2){
	gotoxy(valorX+=num1,valorY+=num2);
	return valorX;
	return valorY;
}
/*	=================================================
		DEFINICION DE MOVIMIENTOS DE QDRAW PARA C++  
	=================================================
*/
int moverDerecha(){
	//se mueve 1 pixel sobre el eje positivo de X
	gotoxy(valorX+=1,valorY);
	return valorX;
}
int moverIzquierda(){
	//se mueve 1 pixel sobre el eje negativo de X
	gotoxy(valorX-=1,valorY);
	return valorX;
}
int moverArriba(){
	//se mueve 1 pixel sobre el eje positivo de Y
	gotoxy(valorX,valorY-=1);
	return valorY;
}
int moverAbajo(){
	//se mueve 1 pixel sobre el eje negativo de Y
	gotoxy(valorX,valorY+=1);
	return valorY;
}
/*	============================================================
	  HABILITA COLOR DE FONDO BLANCO PARA APLICAR A LA CONSOLA
	============================================================
*/
void fondoNegativo(){
	system("color f0");
}
/*	=================================================
		DEFINICION DE COLORES DE QDRAW PARA C++
		y una indicacion para saber que color pinto
	=================================================
*/
int pintarNegro(){
	p_color(NEGRO);
	gotoxy(valorX,valorY);
	cout<<(char) 219;
	estaPintadoDeNegro = 1;
	return estaPintadoDeNegro;
	return valorX, valorY;
}
int pintarVerde(){
	p_color(VERDE);
	gotoxy(valorX,valorY);
	cout<<(char) 219;
	estaPintadoDeVerde = 1;
	return estaPintadoDeVerde;
	return valorX, valorY;
}
int pintarRojo(){
	p_color(ROJO);
	gotoxy(valorX,valorY);
	cout<<(char) 219;
	estaPintadoDeRojo = 1;
	return estaPintadoDeRojo;
	return valorX, valorY;
}
int limpiar(){
	p_color(BLANCO);
	gotoxy(valorX,valorY);
	cout<<(char) 219;
	Limpiar = 1;
	return Limpiar = 1;
	return valorX, valorY;	
}
