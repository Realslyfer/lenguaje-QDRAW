/*
	===================================================
		COLOCAR AMBOS ARCHIVOS EN EL ESCRITORIO
  	===================================================
El compilador buscara las referencias en este archivo cabecera: 
*/
#include "Engine.h"
/*	
	==========================================
		QDRAW - PROCEDIMIENTOS
	==========================================
*/
void dibujarCuadrado(){
	//dibujo de un cuadrado en la esquina superior izquierda
	pintarNegro();
    moverDerecha();
    pintarRojo();
    moverAbajo();
    pintarNegro();
    moverIzquierda();
    pintarVerde();
}
/*	
	======================================================================================================
		FUNCION PRINCIPAL MAIN - Programa(). PARA COMPILAR Y EJECUTAR ESTE ARCHIVO PRESIONE LA TECLA F11
	======================================================================================================
*/
int main(){
	
	//Si no quiere ver el cabezal parpadeando habilite la siguiente funcion borrando las barras invertidas
	ocultarCursor();
	
	//Activa el color blanco de fondo de la consola
	fondoNegativo();
	
	//coloca el cursor de escritura en el punto 0 de X , 0 de Y (es donde inicia el cabezal)	
	Comienzo(0,0);	
		
	//LLAME A SUS PROCEDIMIENTOS ACA
	//Ejemplo: 
	dibujarCuadrado();
	
	
	/*=============
		NO TOCAR
	  =============*/
	system("pause>null");
	remove("null");
	return 0;
}
