// Programa Que Muestra Las Llamadas A Funciones Hechas En Assembly

#include <stdio.h>
#include <stdlib.h>

//	rax	rdi,	rsi
	int sumar(int, int);

int main(int numeroParametros, char ** argumentos){

	int resultado;
	int numero1 = 5;
	int numero2 = 6;

	printf("El Numero De Parametros En La Linea De Comandos Fue %d \r\n", numeroParametros);
	resultado = sumar (numero1, numero2);
	printf("La Suma De %d Y %d Es %d \r\n",numero1, numero2, resultado);

	return(EXIT_SUCCESS);

}
